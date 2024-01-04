//
// Created by Olcay Taner YILDIZ on 8.05.2023.
//

#ifndef DATASTRUCTURES_CPP_GRAPH_H
#define DATASTRUCTURES_CPP_GRAPH_H


#include <vector>
#include "../../General/AbstractGraph.h"
#include "../../List/Graph/Edge.h"

namespace array{
    class Graph : public AbstractGraph{
    private:
        //FIXX
    public:
        int** edges;
        explicit Graph(int vertexCount);
        ~Graph();
        void addEdge(int from, int to);
        void addEdge(int from, int to, int weight);
        void connectedComponentDisjointSet();
        Path* bellmanFord(int source);
        Path dijkstra(int source, int des);
        int** floydWarshall();
        void prim();
        void breadthFirstSearch2(std::vector<std::string> wordlist ,int from, int to);
        void breadthFirstSearch(bool* visited, int startNode) override;
    protected:
        void depthFirstSearch(bool* visited, int fromNode) override;

        Edge* edgeList(int& edgeCount) override;
    };

}


#endif //DATASTRUCTURES_CPP_GRAPH_H
