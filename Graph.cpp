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
    return this->vertices.at(airportCode);
}

bool Graph::addVertex(Airport *airport) {
    if(findVertex(airport->getCode()) != nullptr) {
        Vertex *newVertex = new Vertex(airport);
        this->vertices.at(airport->getCode()) = newVertex;
        return true;
    }
    return false;
}

bool Graph::addEdge(const string& originAirportCode, const string& destinationAirportCode, const string& airlineCode) {
    // TODO check if edge exists if it exists add airlineCode to it. Otherwise create a new edge
    //  or just forget about the set of airlines and do a new edge for each different airline.
    Vertex *originVertex = findVertex(originAirportCode);
    Vertex *destVertex = findVertex(destinationAirportCode);

    if (originVertex && destVertex) {
        Edge newEdge(destVertex, {airlineCode});
        // originVertex->adj.push_back(newEdge);
        return true;
    }

    return false;
}