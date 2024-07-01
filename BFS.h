#include <vector>
#include <string>
#include <queue>
#include "graph.h"

#ifndef BFS_H_
#define BFS_H_

void BFS(const Graph &);
void BFSUtil(const Graph &,const int , std::vector<bool> &, std::queue<int> &);

#endif