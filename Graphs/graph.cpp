#include "graph.h"
#include "queue.h"

#include <list>
#include <iostream>
#include <vector>

// Default Constructor
    Graph::Graph(int vertices_num) : m_vertices_num{vertices_num}
    {
        int count{0};
        while(count < m_vertices_num)
        {
            m_adjList.push_back(std::list<int>(count));
            m_visited.push_back(false);
           ++count;
        }
    }
    void Graph::add_edge(int v1, int v2)
    {
        m_adjList.at(v1).push_back(v2);
        m_adjList.at(v2).push_back(v1);
    }
//BFS Treversal
void Graph::BFS(int start_vertex)
{
    if(!is_vertex(start_vertex))
        throw "input is not a vertex";
    
    Queue<int> bfs_queue{m_vertices_num};
    bfs_queue.add(start_vertex);
    m_visited.at(start_vertex) = true;

    while(!bfs_queue.is_empty())
    {
        int current_vertex = bfs_queue.free();

        std::cout << current_vertex << ' ';
        for(int neighbor : m_adjList[current_vertex]) {
            if(!m_visited.at(neighbor))
            {
                bfs_queue.add(neighbor);
                m_visited[neighbor] = true;
            }
        }
    }
    std::cout << '\n';
    m_visited.assign(m_vertices_num, false);
}
//DFS Treversal
void Graph::DFS(int start_vertex)
{
    if(!is_vertex(start_vertex))
    {
        throw "input is not an existing vertex";
    }
    m_visited.at(start_vertex) = true;
    std::cout << start_vertex << " ";

    for(int neighbor : m_adjList.at(start_vertex))
    {
        if(!m_visited.at(neighbor))
        {
            DFS(neighbor);
        }
    }
}
//check if vertex is in Graph
bool Graph::is_vertex(int vertex) const
{
    return vertex < m_adjList.size();
}