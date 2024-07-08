#include <vector>
#include <string>
#include <queue>
#include "graph.h"

#ifndef BFS_H_
#define BFS_H_
struct DnP{
    std::vector<int> depth;
    std::vector<int> previous;
};

void BFS(const Graph &);
DnP BFSUtil(const Graph &,const int , std::vector<bool> &, std::queue<int> &);

#endif