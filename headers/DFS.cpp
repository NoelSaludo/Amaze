#include "DFS.h"

using namespace std;

paths DFS(const Graph &graph)
{
    int size = graph.GetSize();
    vector<bool> visited(size, false);
    vector<int> prev(size, -1);
    vector<int> path;

    int startIndex = find(graph.Data.begin(), graph.Data.end(), graph.Start) - graph.Data.begin();
    int endIndex = find(graph.Data.begin(), graph.Data.end(), graph.End) - graph.Data.begin();

    bool flag = false;

    DFSutil(graph, startIndex, visited, size, path, flag, prev);

    paths result;
    result.previousList = prev;
    result.traverseList = path;

    vector<int> resultpath = Solve(result, find(graph.Data.begin(), graph.Data.end(), graph.End) - graph.Data.begin());
    result.Result = resultpath;
    result.start = startIndex;
    result.end = endIndex;

    return result;
}
void DFSutil(Graph graph, int start, vector<bool>& visited, int size, vector<int>& path, bool& flag, vector<int>& prev) 
{
    visited[start] = true;
    path.push_back(start);

    if (graph.Data[start] == graph.End) { // Check if the current node is the end node
        flag = true;
        return; // Stop further exploration
    }

    for (int i = 0; i < graph.Matrix[start].size(); i++) { // Iterate through neighbors
        if (!visited[i] && !flag) { // Check if not visited and end node not found yet
            prev[i] = start; // Mark the current node as the predecessor of the next node
            DFSutil(graph, i, visited, size, path, flag, prev);
            if (flag) return; // If end node found in recursion, propagate the success back up
        }
    }

    if (!flag) { // If no path to end node found from this node, backtrack
        path.pop_back();
    }
}