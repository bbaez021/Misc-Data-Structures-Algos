#include "Graph.h"
#include <stack>
#include <fstream>
#include <sstream>
#include <iostream>

Graph::Graph(std::string vertexFilePath, std::string edgeFilePath){
    std::fstream fileIn;
 
    std::string line  = "";

    //Open airports.csv
    fileIn.open(vertexFilePath);
    
    
    while (getline(fileIn, line)){
        
        //3 parameters for vertex
        std::string index;
        std::string name;
        std::string code;
        
        //gets a string stream of the entire current line
        std::stringstream input(line);
        
        //first value in airports.csv is an index. Gets characters until it encounters a comma (csv = comma separated file)
        getline(input, index, ',');
        
        //next line is the airports name
        getline(input, name, ',');

        //Cut quotation marks from beginning and end
        name = name.substr(1, name.size() - 2);
        
        //for this project, we dont care about the next two entries, so they can be skipped
        getline(input, code, ',');
        getline(input, code, ',');

        //in the file, this holds the last entry, which is the airports 3-letter code 
        getline(input, code, ',');

        code = code.substr(1, 3);

        //we can now insert a vertex from the information above. (Note that the indexes in the file start at 1, but we should be starting at 0, so 1 is subtracted)
        
        insertAirportVertex(stoi(index), name, code);

    }
    //closes airports.csv
    fileIn.close();

    //initializes adjacency matrix so that all possible edges have an initial weight of 0.
    int dim_ = vertices.size();
    adjMatrix.resize(dim_);
    for (int i = 0; i < dim_; i++){
        for (int j = 0; j < dim_; j++){
            adjMatrix[i].push_back(0);
        }
    }

    line = "";

    //open routes.csv
    fileIn.open(edgeFilePath);

    while (getline(fileIn, line)){
        
        // strings will eventually contain source and destination index values
        std::string srcIndex;
        std::string destIndex;

        //will contain index values converted into int from strings above
        int src;
        int dest;

        std::stringstream input(line);

        //first three values in csv file are irrelevant
        getline(input, srcIndex, ',');
        getline(input, srcIndex, ',');
        getline(input, srcIndex, ',');

        //This value gives us the index of the source airport (offset by 1 due to counting in c++)
        getline(input, srcIndex, ',');
        src = stoi(srcIndex);

        //next line does not matter
        getline(input, destIndex, ',');

        //this value gives us the index of the destination airport (offset by 1, like previous)
        getline(input, destIndex, ',');
        dest = stoi(destIndex);

        //increment the weight of the edge from src to dest by 1
        startAdjMatrix(src, dest);
    }
    // close routes.csv
    fileIn.close();

    // Constructor is done.

}

void Graph::insertAirportVertex(int index, std::string name, std::string code){
    
    //Creates new vertex struct
    airportVertex v;

    //assigns 
    v.airportName = name;
    v.airportCode = code;

    v.index = index;

    oldToNew[index] = vertices.size();
    vertices.push_back(v);

}

std::vector<Graph::airportVertex> Graph::accessVertices(){
    return vertices;
}

void Graph::insertEdge(int v1, int v2, double weight){
    adjMatrix[v1][v2] = weight;
}

void Graph::startAdjMatrix(int src, int dest){
    src = oldToNew[src];
    dest = oldToNew[dest];
    adjMatrix[src][dest]++;
}

double Graph::adjacentEdgeWeight(int src, int dest){
    if (src < (int)vertices.size() && dest < (int)vertices.size()){
        return adjMatrix[src][dest];
    }
    return 0.0;
}


std::vector<int> Graph::Djikstra(airportVertex source, airportVertex destination){
    std::vector<int> djikstra;
    return djikstra;
}   

std::vector<double> Graph::pagerank(int maxIterations, double dampeningFactor, double tolerance){
    std::vector<double> pagerankret;
    return pagerankret;
}

void Graph::DFS(int start){
    std::vector<bool> visited;

    visited.resize(vertices.size());

    if (start >= (int)visited.size()){
        return;
    }
    
    std::stack<int> dfs;
    dfs.push(start);
    visited[start] = true;
    int curr;
    while (!dfs.empty()){
        curr = dfs.top();
        dfs.pop();

        for (int i = 0; i < (int)visited.size(); i++){
            if (adjMatrix[curr][i] > 0 && !visited[i]){
                dfs.push(i);
                visited[i] = true;
            }
        }
    }

}