#include <iostream>
#include <queue>
#include <algorithm>

#include "BFS.h"

using namespace std;

paths BFS(const Graph &g){
    queue<int> nextToVisit;
    vector<bool> visited(g.GetSize(), false);

    int startIndex = find(g.Data.begin(), g.Data.end(), g.Start) - g.Data.begin();
    int endIndex = find(g.Data.begin(), g.Data.end(), g.End) - g.Data.begin();

    paths result = BFSUtil(g,startIndex, visited, nextToVisit);
    result.start = startIndex;
    result.end = endIndex;

    vector<int> path = Solve(result,endIndex);
    result.Result = path;
    return result;
}

paths BFSUtil(const Graph &g,const int start, vector<bool> &visited, queue<int> &q) {
    visited[start] = true;
    q.push(start);

    vector<int> depthList(g.GetSize(),0);
    vector<int> previousList(g.GetSize(),-1);
    vector<int> *traversedList = new vector<int>;

    int depth = 0;

    while (!q.empty()) {
        int queueSize = q.size();  
        
        for (int i = 0; i < queueSize; i++) {
            int current = q.front();
            q.pop();
            
            if (g.Data[current] == g.End && !visited[current]) {
                cout << g.Data[current] << " ";
                return {previousList};
            }
            
            for (int j = 0; j < g.GetSize(); j++) {
                if (g.Matrix[current][j] == 1 && !visited[j]) {
                    previousList[j] = current;
                    depthList[j] = depth + 1;  
                    visited[j] = true;
                    q.push(j);
                }
            }
            traversedList->push_back(current);
            
            cout << "Data: " << g.Data[current] << "\nPrev: " << previousList[current] << "\nDepth: " << depthList[current] << endl;
            cout << endl;
        }
        
        depth++;
    }
    return {previousList, *traversedList,0,0};
}
