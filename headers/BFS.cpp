#include "global.h"

using namespace std;

paths BFS(const Graph &g){
    queue<int> nextToVisit;
    vector<bool> visited(g.GetSize(), false);
    vector<int> previousList(g.GetSize(),-1);

    int startIndex = g.Start;
    int endIndex = g.End;

    paths result = BFSUtil(g,startIndex, visited, nextToVisit, previousList);
    result.start = startIndex;
    result.end = endIndex;
    
    auto start = chrono::high_resolution_clock::now();
    vector<int> path = Solve(previousList,endIndex);
    auto end = chrono::high_resolution_clock::now();

    result.time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    result.Result = path;
    return result;
}

paths BFSUtil(const Graph &g,const int start, vector<bool> &visited, queue<int> &q, vector<int> &previousList) {
    visited[start] = true;
    q.push(start);

    vector<int> depthList(g.GetSize(),0);
    vector<int> *traversedList = new vector<int>;

    int depth = 0;

    while (!q.empty()) {
        int queueSize = q.size();  
        
        for (int i = 0; i < queueSize; i++) {
            int current = q.front();
            q.pop();
            
            if (g.Data[current] == g.Data[g.End] && !visited[current]) {
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
        }
        
        depth++;
    }
    return {*traversedList,0,0};
}
