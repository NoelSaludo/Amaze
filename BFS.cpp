#include <iostream>
#include <queue>
#include <algorithm>


#include "BFS.h"
using namespace std;

void BFS(const Graph &g){
    queue<int> nextToVisit;
    vector<bool> visited(g.GetSize());

    int startIndex = find(g.Data.begin(), g.Data.end(), g.Start) - g.Data.begin();

    DnP result = BFSUtil(g,startIndex, visited, nextToVisit);
}

DnP BFSUtil(const Graph &g,const int start, vector<bool> &visited, queue<int> &q) {
    visited[start] = true;
    q.push(start);

    vector<int> depthList(g.GetSize(),0);
    vector<int> previousList(g.GetSize(),-1);

    int depth = 0;

    while (!q.empty()) {
        int queueSize = q.size();  
        
        for (int i = 0; i < queueSize; i++) {
            int current = q.front();
            q.pop();
            
            if (g.Data[current] == g.End && !visited[current]) {
                cout << g.Data[current] << " ";
                return {depthList, previousList};
            }
            
            for (int j = 0; j < g.GetSize(); j++) {
                if (g.Matrix[current][j] == 1 && !visited[j]) {
                    previousList[j] = current;
                    depthList[j] = depth + 1;  
                    visited[j] = true;
                    q.push(j);
                }
            }
            
            cout << "Data: " << g.Data[current] << "\nPrev: " << previousList[current] << "\nDepth: " << depthList[current] << endl;
            cout << endl;
        }
        
        depth++;  // Increment depth after processing all nodes at the current level
    }
    return {depthList,previousList};


}
