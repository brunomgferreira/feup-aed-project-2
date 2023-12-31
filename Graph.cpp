#include "Graph.h"


// Vertex

Vertex::Vertex(Airport *airport) : airport(airport) {}

Airport *Vertex::getAirport() const {
    return this->airport;
}

bool Vertex::isVisited() const {
    return this->visited;
}

void Vertex::setVisited(bool v) {
    this->visited = v;
}

int Vertex::getNum() const {
    return num;
}

void Vertex::setNum(int num) {
    Vertex::num = num;
}

int Vertex::getLow() const {
    return low;
}

void Vertex::setLow(int low) {
    Vertex::low = low;
}

const unordered_map<string, Edge> &Vertex::getAdj() const {
    return this->adj;
}

void Vertex::addEdge(Vertex *dest, const string& airlineCode) {
    auto it = adj.find(dest->airport->getCode());
    if(it != adj.end()) it->second.airlines.insert(airlineCode);
    else {
        Edge newEdge(dest, {airlineCode});
        adj.insert({dest->airport->getCode(), newEdge});
    }
}


// Edge

Edge::Edge(Vertex *d, unordered_set<string> airlines) : dest(d), airlines(airlines) {}

Vertex *Edge::getDest() const {
    return this->dest;
}

unordered_set<string> Edge::getAirlines() const {
    return this->airlines;
}


// Graph

Vertex *Graph::findVertex(const string &airportCode) const {
    auto it = this->vertices.find(airportCode);
    if (it != this->vertices.end()) {
        return it->second;
    }
    return nullptr;
}

bool Graph::addVertex(Airport *airport) {
    if(findVertex(airport->getCode()) == nullptr) {
        Vertex *newVertex = new Vertex(airport);
        this->vertices.insert({airport->getCode(), newVertex});
        return true;
    }
    return false;
}

bool Graph::addEdge(const string& originAirportCode, const string& destinationAirportCode, const string& airlineCode) {
    Vertex *originVertex = findVertex(originAirportCode);
    Vertex *destVertex = findVertex(destinationAirportCode);

    if (originVertex && destVertex) {
        originVertex->addEdge(destVertex, airlineCode);
        return true;
    }

    return false;
}

const unordered_map<string, Vertex *> &Graph::getVertices() const {
    return vertices;
}

void Graph::bfs(const string& airportCode, unordered_set<string>& destinationAirports, unordered_set<string>& destinationCities, unordered_set<string>& destinationCountries) {
    auto s = findVertex(airportCode);
    if (s == nullptr)
        return;
    queue<Vertex*> q;
    for (auto &v : vertices)
        v.second->visited = false;
    q.push(s);
    s->visited = true;
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        for (auto & e : v->adj) {
            auto w = e.second.dest;
            if ( ! w->visited ) {
                destinationAirports.insert(w->airport->getCode());
                destinationCities.insert(w->airport->getCity());
                destinationCountries.insert(w->airport->getCountry());
                q.push(w);
                w->visited = true;
            }
        }
    }
}

void Graph::bfs(const string& airportCode, int stops, unordered_set<string>& destinationAirports, unordered_set<string>& destinationCities, unordered_set<string>& destinationCountries) {
    auto s = findVertex(airportCode);
    if (s == nullptr)
        return;
    queue<Vertex*> q;
    for (auto &v : vertices)
        v.second->visited = false;
    q.push(s);
    s->visited = true;
    while(stops>=0){
        size_t s = q.size();
        while(s>0) {
            auto v = q.front();
            q.pop();
            for (auto &e: v->getAdj()) {
                auto w = e.second.dest;
                if (!w->isVisited()) {
                    destinationAirports.insert(w->airport->getCode());
                    destinationCities.insert(w->airport->getCity());
                    destinationCountries.insert(w->airport->getCountry());
                    q.push(w);
                    w->setVisited(true);
                }
            }
            s--;
        }
        stops--;
    }
}

bool contains(stack<string> s, const string &airportCode) {
    while(!s.empty()){
        if(airportCode==s.top()) return true;
        s.pop();
    }
    return false;
}

void Graph::dfsart(Vertex *v, stack<string> &s, unordered_set<string> &set, int &i, string root) {
    v->setVisited(true);
    v->setLow(i);
    v->setNum(i);
    i++;
    s.push(v->getAirport()->getCode());
    int children = 0;
    for(auto w : v->getAdj() ){
        auto child = w.second.getDest();
        if(!child->isVisited()){
            children++;
            dfsart(child,s,set,i, root);
            v->setLow(min(v->getLow(),child->getLow()));
            if(child->getLow() >= v->getNum()) set.insert(v->getAirport()->getCode());
        }
        else if (contains(s,child->getAirport()->getCode())){
            v->setLow(min(v->getLow(),child->getNum()));
        }
    }
    if((v->getAirport()->getCode() == root) &&(children<=1)) set.erase(v->getAirport()->getCode());
    s.pop();
}

void Graph::bfsmaxtrip(vector<pair<string,string>> &maxTripVec, int &maxTrip) {
    for(auto &originAirport : vertices){
        for(auto v : vertices){
            v.second->setVisited(false);
        }
        queue<pair<Vertex*,int>> q;
        q.push({findVertex(originAirport.first),0});
        q.front().first->setVisited(true);
        while(!q.empty()){
            Vertex * r = q.front().first;
            int i = q.front().second;
            q.pop();
            for(auto &e : r->getAdj()){
                auto w = e.second.getDest();
                if(!w->isVisited()){
                    q.push({w,i+1});
                    w->setVisited(true);
                    if (maxTrip < i + 1) maxTripVec.clear();
                    if (maxTrip <= i + 1) maxTrip = i + 1, maxTripVec.push_back({originAirport.first, w->getAirport()->getCode()});
                }
            }
        }
    }
}





