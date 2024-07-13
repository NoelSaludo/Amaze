#include <vector>
#include <string>
#include <queue>
#include "graph.h"
#include "solver.h"

#ifndef BFS_H_
#define BFS_H_

std::vector<int> BFS(const Graph &);
struct dnp BFSUtil(const Graph &,const int , std::vector<bool> &, std::queue<int> &);

#endif