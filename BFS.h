#include <vector>
#include <string>
#include <queue>
#include "graph.h"
#include "Dijsktra.h"

#ifndef BFS_H_
#define BFS_H_

void BFS(const Graph &);
DnP BFSUtil(const Graph &,const int , std::vector<bool> &, std::queue<int> &);

#endif