#include <vector>
#include <string>
#include <queue>
#include "graph.h"
#include "solver.h"

#ifndef BFS_H_
#define BFS_H_

paths BFS(const Graph &);
paths BFSUtil(const Graph &,const int , std::vector<bool> &, std::queue<int> &, std::vector<int> &);

#endif