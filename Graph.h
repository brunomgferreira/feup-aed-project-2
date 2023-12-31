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

/**
* @brief Class representing an edge in a graph, associated with a destination vertex and airlines.
*/

class Edge {
private:
    Vertex *dest;       // destination vertex
    unordered_set<string> airlines;     // edge weight
public:
    Edge() = default;

    /**
    * @brief Constructor for the Edge class.
    *
    * @details Initializes an instance of the Edge class with the specified destination vertex and airlines.
    *
    * @param d Pointer to the destination vertex.
    * @param airlines Set of airline codes associated with the edge.
    */
    Edge(Vertex *d, unordered_set<string> airlines);

    /**
    * @brief Get the destination vertex associated with the edge.
    *
    * @return Pointer to the destination vertex.
    */
    Vertex *getDest() const;

    /**
    * @brief Get the set of airline codes associated with the edge.
    *
    * @return The set of airline codes.
    */
    unordered_set<string> getAirlines() const;

    friend class Graph;
    friend class Vertex;
};

/**
* @brief Represents a vertex in the graph, corresponding to an airport.
*/

class Vertex {
private:
    Airport* airport;                // contents
    unordered_map<string, Edge> adj;  // list of outgoing edges
    bool visited;          // auxiliary field
    int num;               // auxiliary field
    int low;

    /**
    * @brief Add an edge to another vertex in the adjacency list.
    *
    * @details If an edge to the specified destination already exists, add the airline code to the edge's set of airlines.
    * Otherwise, create a new edge with the specified destination and airline code.
    *
    * @param dest Pointer to the destination vertex.
    * @param airlineCode The airline code associated with the edge.
    */
    void addEdge(Vertex *dest, const string& airlineCode);
public:

    /**
    * @brief Constructor for the Vertex class.
    *
    * @details Initializes an instance of the Vertex class with the specified airport.
    *
    * @param airport Pointer to the airport associated with the vertex.
    */
    Vertex(Airport *airport);

    /**
    * @brief Get the airport associated with the vertex.
    *
    * @return Pointer to the airport associated with the vertex.
    */
    Airport *getAirport() const;

    /**
    * @brief Check if the vertex has been visited during traversal.
    *
    * @return True if the vertex has been visited; otherwise, false.
    */
    bool isVisited() const;

    /**
    * @brief Set the visited status of the vertex.
    *
    * @param v The value to set for the visited status.
    */
    void setVisited(bool v);

    /**
    * @brief Get the numerical identifier for the vertex during traversal.
    *
    * @return The numerical identifier for the vertex.
    */
    int getNum() const;

    /**
    * @brief Set the numerical identifier for the vertex.
    *
    * @param num The numerical identifier to set for the vertex.
    */
    void setNum(int num);

    /**
    * @brief Get the low value used in traversal algorithms.
    *
    * @return The low value for the vertex.
    */
    int getLow() const;

    /**
    * @brief Set the low value for the vertex.
    *
    * @param low The low value to set for the vertex.
    */
    void setLow(int low);

    /**
    * @brief Get the adjacency list representing edges to other vertices.
    *
    * @return A constant reference to the adjacency list.
    */
    const unordered_map<string, Edge> &getAdj() const;

    friend class Graph;
};

/**
* @brief Represents a graph of airports and flights.
*/

class Graph {
private:
    unordered_map<string, Vertex *> vertices;      // vertex set
public:

    /**
    * @brief Retrieves a constant reference to the map of vertices in the graph.
    *
    * @details This method returns a constant reference to the map containing all vertices in the graph.
    *
    * @return A constant reference to the map of vertices.
    *
    * @details Time complexity: O(1)
    */
    const unordered_map<string, Vertex *> &getVertices() const;

    /**
    * @brief Finds and returns the vertex with the given airport code.
    *
    * @details This method searches for a vertex in the graph using the provided airport code.
    *
    * @param airportCode The code of the airport to search for.
    * @return A pointer to the found vertex, or nullptr if not found.
    *
    * @details Time complexity: O(1)
    */
    Vertex *findVertex(const string &airportCode) const;

    /**
    * @brief Adds a new vertex to the graph with the given airport.
    *
    * @details This method adds a new vertex to the graph if a vertex with the same airport code does not already exist.
    *
    * @param airport The airport associated with the new vertex.
    * @return True if the vertex is successfully added, false otherwise.
    *
    * @details Time complexity: O(1)
    */
    bool addVertex(Airport *airport);


    /**
    * @brief Adds a directed edge between two airports with the given airline code.
    *
    * @details This method adds a directed edge from the origin airport to the destination airport with the specified airline code.
    * Both origin and destination airports must exist in the graph.
    *
    * @param originAirportCode The code of the origin airport.
    * @param destinationAirportCode The code of the destination airport.
    * @param airlineCode The code of the airline associated with the edge.
    * @return True if the edge is successfully added, false otherwise.
    *
    * @details Time complexity: O(1)
    */
    bool addEdge(const string& originAirportCode, const string& destinationAirportCode, const string& airlineCode);

    /**
    * @brief Performs a breadth-first search (BFS) starting from the given airport code.
    *
    * @details This method explores the graph using BFS and populates sets with information about destination airports, cities, and countries.
    *
    * @param airportCode The code of the starting airport for BFS.
    * @param destinationAirports A set to store destination airport codes.
    * @param destinationCities A set to store destination city names.
    * @param destinationCountries A set to store destination country names.
    *
    * @details Time complexity: O(V + E), where V is the number of vertices and E is the number of edges.
    */
    void bfs(const string& airportCode, unordered_set<string>& destinationAirports, unordered_set<string>& destinationCities, unordered_set<string>& destinationCountries);

    /**
    * @brief Performs a modified breadth-first search (BFS) with a specified number of stops.
    *
    * @details This method explores the graph using BFS up to a specified number of stops and populates sets with information about destination airports, cities, and countries.
    *
    * @param airportCode The code of the starting airport for BFS.
    * @param stops The maximum number of stops allowed in the search.
    * @param destinationAirports A set to store destination airport codes.
    * @param destinationCities A set to store destination city names.
    * @param destinationCountries A set to store destination country names.
    *
    * @details Time complexity: O(V + E), where V is the number of vertices and E is the number of edges.
    */
    void bfs(const string& airportCode, int stops, unordered_set<string>& destinationAirports, unordered_set<string>& destinationCities, unordered_set<string>& destinationCountries);

    /**
    * @brief Performs a BFS to find the maximum trip length and corresponding airports.
    *
    * @details This method iterates through all airports in the graph and performs BFS to find the maximum trip length and the corresponding origin and destination airports.
    *
    * @param maxTripVec A vector to store pairs of origin and destination airports for the maximum trip.
    * @param maxTrip An integer representing the maximum trip length.
    *
    * @details Time complexity: O(V * (V + E)), where V is the number of vertices and E is the number of edges.
    */
    void bfsmaxtrip(vector<pair<string,string>> &maxTripVec, int &maxTrip);

    /**
    * @brief Performs a depth-first search (DFS) to find articulation points in the graph.
    *
    * @details This method identifies articulation points in the graph using DFS and updates a set with the found articulation points.
    *
    * @param v The current vertex being processed in the DFS.
    * @param s A stack to keep track of visited vertices during DFS.
    * @param set A set to store the identified articulation points.
    * @param i An integer representing the current DFS iteration.
    * @param root The code of the root airport for DFS.
    *
    * @details Time complexity: O(V + E), where V is the number of vertices and E is the number of edges.
    */
    void dfsart(Vertex *v, stack<string> &s, unordered_set<string> &set, int &i, string root);


};

#endif // FLIGHT_MANAGEMENT_SYSTEM_GRAPH_H_
