#include "global.h"

using namespace std;

paths DFS(const Graph &graph)
{
    int size = graph.GetSize();
    vector<bool> visited(size, false);
    vector<int> prev(size, -1);
    vector<int> path;

    int startIndex = graph.Start;
    int endIndex = graph.End;

    bool flag = false;

    DFSutil(graph, startIndex, visited, size, path, flag, prev);

    paths result;
    result.traverseList = path;

    vector<int> resultpath = Solve(prev, endIndex);

    result.Result = resultpath;
    result.start = startIndex;
    result.end = endIndex;
    

    return result;
}
void DFSutil(Graph graph, int start, vector<bool>& visited, int size, vector<int>& path, bool& flag, vector<int>& prev) 
{
    visited[start] = true;
    path.push_back(start);

    if (graph.Data[start] == graph.Data[graph.End]) { // Check if the current node is the end node
        flag = true;
        return; // Stop further exploration
    }

    for (int i = 0; i < graph.Matrix[start].size(); i++) { 
        if (!visited[i] && !flag && graph.Matrix[start][i]) { 
            prev[i] = start; 
            DFSutil(graph, i, visited, size, path, flag, prev);
            if (flag) return; 
        }
    }

}