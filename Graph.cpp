#include "Graph.h"


// Vertex

Vertex::Vertex(Airport *airport) : airport(airport) {}

Airport *Vertex::getAirport() const {
    return this->airport;
}

void Vertex::setAirport(Airport *airport) {
    this->airport = airport;
}

bool Vertex::isVisited() const {
    return this->visited;
}

void Vertex::setVisited(bool v) {
    this->visited = v;
}

bool Vertex::isProcessing() const {
    return this->processing;
}

void Vertex::setProcessing(bool p) {
    this->processing = p;
}

const unordered_map<string, Edge> &Vertex::getAdj() const {
    return this->adj;
}

void Vertex::setAdj(const unordered_map<string, Edge> &adj) {
    this->adj = adj;
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

void Edge::setDest(Vertex *dest) {
    this->dest = dest;
}

unordered_set<string> Edge::getAirlines() const {
    return this->airlines;
}

void Edge::setAirlines(unordered_set<string> airlines) {
    this->airlines = airlines;
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

vector<int> Graph::bfs(const string airportCode) const {
    unordered_set<string> airports;
    unordered_set<string> cities;
    unordered_set<string> countries;

    auto s = findVertex(airportCode);
    if (s == nullptr)
        return {0,0,0};
    queue<Vertex*> q;
    for (auto &v : vertices)
        v.second->visited = false;
    q.push(s);
    s->visited = true;
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        airports.insert(v->airport->getCode()); //-1 ?
        cities.insert(v->airport->getCity());
        countries.insert(v->airport->getCountry());

        for (auto & e : v->adj) {
            auto w = e.second.dest;
            if ( ! w->visited ) {
                /** ??
                airports.insert(v->airport->getCode()); //-1 ?
                cities.insert(v->airport->getCity());
                countries.insert(v->airport->getCountry());
                **/
                q.push(w);
                w->visited = true;
            }
        }
    }
    return {(int)airports.size(),(int)cities.size(),(int)countries.size()};
}

vector<int> Graph::bfs(const string airportCode, int stops) const {
    unordered_set<string> airports;
    unordered_set<string> cities;
    unordered_set<string> countries;

    auto s = findVertex(airportCode);
    if (s == nullptr)
        return {0,0,0};
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
            airports.insert(v->airport->getCode()); //-1 ?
            cities.insert(v->airport->getCity());
            countries.insert(v->airport->getCountry());

            for (auto &e: v->getAdj()) {
                auto w = e.second.dest;
                if (!w->isVisited()) {
                    /** ???
                    airports.insert(v->airport->getCode()); //-1 ?
                    cities.insert(v->airport->getCity());
                    countries.insert(v->airport->getCountry());
                     **/
                     q.push(w);
                    w->setVisited(true);
                }
            }
            s--;
        }
        stops--;
    }
    while(!q.empty()){
        airports.insert(q.front()->airport->getCode()); //-1 ?
        cities.insert(q.front()->airport->getCity());
        countries.insert(q.front()->airport->getCountry());
        q.pop();
    }
    return {(int)airports.size(),(int)cities.size(),(int)countries.size()};
}
