#include "DFS.h"
#include <array>
#include <algorithm>

using namespace std;

vector<string> DepthFirstSearch(const Graph &graph)
{
    int size = graph.GetSize();
    vector<bool> visited(size, false);

    vector<string> path;

    int index = find(graph.Data.begin(), graph.Data.end(), graph.Start) - graph.Data.begin();

    bool flag = false;

    DFSutil(graph, index, visited, size, path, flag);

    return path;


}
void DFSutil(Graph graph,int start, vector<bool>& visited, int size, vector<string> &path, bool &flag)
{
    int current = start;
    visited[current] = true;
    path.push_back(graph.Data[current]);
    for (int i = 0; i < size; i++)
    {
        if(flag)
        {
            break;
        }
        if (graph.Data[current] == graph.End && !flag)
        {
            flag = true;
            break;
        }
        else if (graph.Matrix[current][i] == 1 && !visited[i])
        {
            DFSutil(graph, i, visited, size, path, flag);
        }
    }

}