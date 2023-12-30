#ifndef FLIGHT_MANAGEMENT_SYSTEM_GRAPH_H_
#define FLIGHT_MANAGEMENT_SYSTEM_GRAPH_H_

#include <cstddef>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include "Airport.h"

using namespace std;

class Graph;
class Vertex;

class Edge {
private:
    Vertex *dest;       // destination vertex
    unordered_set<string> airlines;     // edge weight
public:
    Edge() = default;
    Edge(Vertex *d, unordered_set<string> airlines);
    Vertex *getDest() const;
    void setDest(Vertex *dest);
    unordered_set<string> getAirlines() const;
    void setAirlines(unordered_set<string> airlines);
    friend class Graph;
    friend class Vertex;
};

class Vertex {
private:
    Airport* airport;                // contents
    unordered_map<string, Edge> adj;  // list of outgoing edges
    bool visited;          // auxiliary field
    bool processing;       // auxiliary field
    int num;               // auxiliary field
    int low;
private:
    // auxiliary field

    void addEdge(Vertex *dest, const string& airlineCode);
public:
    Vertex(Airport *airport);
    Airport *getAirport() const;
    void setAirport(Airport *airport);
    bool isVisited() const;
    void setVisited(bool v);
    bool isProcessing() const;
    void setProcessing(bool p);
    int getNum() const;
    void setNum(int num);
    int getLow() const;
    void setLow(int low);
    const unordered_map<string, Edge> &getAdj() const;
    void setAdj(const unordered_map<string, Edge> &adj);
    friend class Graph;
};


class Graph {
private:
    unordered_map<string, Vertex *> vertices;      // vertex set
public:

    const unordered_map<string, Vertex *> &getVertices() const;

    Vertex *findVertex(const string &airportCode) const;
    bool addVertex(Airport *airport);
    bool addEdge(const string& originAirportCode, const string& destinationAirportCode, const string& airlineCode);

    void bfs(const string& airportCode, unordered_set<string>& destinationAirports, unordered_set<string>& destinationCities, unordered_set<string>& destinationCountries);

    void bfs(const string& airportCode, int stops, unordered_set<string>& destinationAirports, unordered_set<string>& destinationCities, unordered_set<string>& destinationCountries);

    void dfsart(Vertex *v, stack<string> &s, unordered_set<string> &set, int &i, string root);
};

#endif // FLIGHT_MANAGEMENT_SYSTEM_GRAPH_H_
