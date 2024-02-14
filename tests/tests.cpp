#define CATCH_CONFIG_MAIN
#define _GLIBCXX_USE_CXX11_ABI 0
#include "../tests/catch.hpp"
#include <string>
#include "../src/Graph.cpp"

TEST_CASE("Test Constructor"){
    
    std::string vertices = "..\\tests\\testVertices.csv";
    std::string edges = "..\\tests\\testEdges.csv";
    
    Graph g = Graph(vertices, edges);
    
    REQUIRE(g.adjacentEdgeWeight(0, 1) == 1);
    REQUIRE(g.adjacentEdgeWeight(0, 8) == 1);
    REQUIRE(g.adjacentEdgeWeight(0, 9) == 1);
    REQUIRE(g.adjacentEdgeWeight(1, 0) == 1);  
    REQUIRE(g.adjacentEdgeWeight(1, 12) == 3.0);
    REQUIRE(g.adjacentEdgeWeight(1, 20) == 2.0);
    REQUIRE(g.adjacentEdgeWeight(2, 0) == 2);  
    REQUIRE(g.adjacentEdgeWeight(20, 1) == 1);
   
}

TEST_CASE("Test for Vertex Access"){
        
    std::string vertices = "..\\tests\\testVertices.csv";
    std::string edges = "..\\tests\\testEdges.csv";
    
    Graph g = Graph(vertices, edges);

    REQUIRE(g.vertices[0].index == 1);
    REQUIRE(g.vertices[0].airportName == "La Guardia Airport");
    REQUIRE(g.vertices[0].airportCode == "LGA");

    REQUIRE(g.vertices.back().index == 2022);
    REQUIRE(g.vertices.back().airportName == "Hamad International Airport");
    REQUIRE(g.vertices.back().airportCode == "DOH");
}