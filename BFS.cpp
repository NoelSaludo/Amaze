#include <iostream>
#include <queue>
#include <algorithm>

#include "BFS.h"

using namespace std;

void BFS(const Graph &g){
    queue<int> nextToVisit;
    vector<bool> visited(g.GetSize());

    int startIndex = find(g.Data.begin(), g.Data.end(), g.Start) - g.Data.begin();

    BFSUtil(g,startIndex, visited, nextToVisit);
}

void BFSUtil(const Graph &g,const int start, vector<bool> &visited, queue<int> &q) {
    visited[start] = true;
    q.push(start);

    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        cout << g.Data[current] << " ";
        if(g.Data[current] == g.End && !visited[current])
        {
            cout << g.Data[current] << " ";
            return;
        }
        for(int i = 0; i < g.GetSize(); i++)
        {
            if(g.Matrix[current][i] == 1 && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }

}
