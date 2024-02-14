#include <cstdlib>
#include <vector>
#include <string>
#include <map>

#pragma once

/*
Graph ADT class
*/

class Graph{
    private:
        /**
         * struct for our airport vertices
         * 
         * Index = OpenFlights airport ID number.
         * airportName = name of airport
         * airportCode = IATA code
         * 
         */
        struct airportVertex
            {
                int index;
                std::string airportName;
                std::string airportCode;

                bool operator< (const airportVertex &other) const{
                    return (index < other.index);
                }
            };

        /**
         * Adjacency matrix containing edge weights
         * 
         */
        std::vector<std::vector<double>> adjMatrix;

        /**
         * Used to convert OpenFlights indexes to locations in our vector
         * 
         */
        std::map<int, int> oldToNew;

    public:
        /**
         * Location to store airport vetices
         * 
         */
        std::vector<airportVertex> vertices;

        /**
         * Constructor for a new Graph object
         * 
         * @param vertexFilePath The location of the file for the vertices
         * @param edgeFilePath The location of the file for the edges
         */
        Graph(std::string vertexFilePath, std::string edgeFilePath);
        
        /**
         * Inserts an aroprt vertex into the graph
         * 
         * @param index OpenFlights index of the airport
         * @param name Name of the airport
         * @param code IATA code
         */
        void insertAirportVertex(int index, std::string name, std::string code);

        /**
         * Returns airport vertices
         * 
         * @return Vector of airport vertices
         */
        
        std::vector<airportVertex> accessVertices();

        /**
         * Inserts or changes edge in graph object
         * 
         * @param v1 Source vertex of edge
         * @param v2 Destination vertex of edge
         * @param weight Desired weight of edge
         */
        void insertEdge(int v1, int v2, double weight);

        /**
         * Initializes the adjacency matrix for testing purposes before any operations by algorithms are done
         * 
         * @param src Source vertex of current edge
         * @param dest Destination vertex of current edge
         */
        void startAdjMatrix(int src, int dest);

        /**
         * Returns the weight of an edge. 
         * 
         * @param src source vertex of edge
         * @param dest destination vertex of edge
         * @return Weight of an adjacent edge. If 0, edge is not adjacent in this context
         */
        double adjacentEdgeWeight(int src, int dest);

        /**
         * Djikstra's Algorightm to return the shortest path 
         * 
         * @param source Source vertex
         * @param destination Destination vertex
         * @return std::vector<int> indexes of the vertices of the shortest path from source to destination
         */
        std::vector<int> Djikstra(airportVertex source, airportVertex destination);

        /**
         * @brief Pagerank algorithm that assigns edge weights to the 
         * 
         * @param maxIterations Maximum number of iterations that the algorithm will be performed
         * @param dampingFactor Makes it possible for the algorithm to continue. 
         * @param tolerance When the next iteration is within this value, the algorithm should stop and return
         * @return Vector of the ranks of each airport 
         */
        std::vector<double> pagerank(int maxIterations, double dampeningFactor, double tolerance);
        
        /**
         * Depth-first search algorithm on the graph
         * 
         * @param start starting vertex of the search
         */
        void DFS(int start);
};  