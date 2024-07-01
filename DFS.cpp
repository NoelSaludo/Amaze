#include "DFS.h"
#include <array>
#include <algorithm>

using namespace std;

vector<string> DepthFirstSearch(const Graph &graph)
{
    int size = graph.GetSize();
    vector<bool> visited(size);
    for (int i = 0; i < size; i++)
    {
        visited[i] = false;
    }
    vector<string> neighbors;

    int index = 0;

    for(int i = 0; i < size; i++)
    {
        if(graph.Data[i] == graph.Start)
        {
            index = i;
        }
    }
    bool flag = false;

    DFSutil(graph, index, visited, size, neighbors, flag);

    return neighbors;


}
void DFSutil(Graph graph,int start, vector<bool>& visited, int size, vector<string> &neighbors, bool &flag)
{
    visited[start] = true;
    neighbors.push_back(graph.Data[start]);
    for (int i = 0; i < size; i++)
    {
        if(flag)
        {
            return;
        }
        if (graph.Data[start] == graph.End && !flag)
        {
            // neighbors.push_back(graph.Data[start]);
            flag = true;
            return;
        }
        else if (graph.Matrix[start][i] == 1 && !visited[i])
        {
            DFSutil(graph, i, visited, size, neighbors, flag);
        }
    }

}