#ifndef GRAPH_H
#define GRAPH_H
#include <list>
#include "queue.h"
#include <map>
#include <iostream>
#include <vector>
class Graph
{
public:
// Default Constructor
    Graph(int vertices_num);
// add edge connecting two existing vertices in Graph, throws an instance of c style string if vertex does not exist
    void add_edge(int v1, int v2);
//BFS Treversal
    void BFS(int start_vertex);
//DFS Treversal
    void DFS(int start_vertex);
//check if vertex is in Graph
    bool is_vertex(int vertex) const;
private:
    std::vector<std::list<int>> m_adjList{};
    std::vector<bool> m_visited{};
    int m_vertices_num{};
};
#endif