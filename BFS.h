#include <vector>
#include <string>
#include <queue>
#include "graph.h"

#ifndef BFS_H_
#define BFS_H_
struct DnP{
    std::vector<int> depthList;
    std::vector<int> previousList;
    std::vector<int> traversedList;
};

std::vector<int> BFS(const Graph &);
DnP BFSUtil(const Graph &,const int , std::vector<bool> &, std::queue<int> &);
std::vector<int> Solve(DnP,int);

#endif