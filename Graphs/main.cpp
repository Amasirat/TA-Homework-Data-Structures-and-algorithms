#include <iostream>
#include "graph.h"

int main()
{
    Graph graph1{5};
    graph1.add_edge(0, 1);
    graph1.add_edge(1, 3);
    graph1.add_edge(4, 3);
    graph1.add_edge(3, 2);
    graph1.add_edge(4, 2);

    graph1.BFS(0);
    graph1.DFS(2);
    return 0;
}