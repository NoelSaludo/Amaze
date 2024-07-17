#include <vector>
#include <string>
#include <algorithm>
#include "graph.h"
#include "solver.h"

#ifndef DFS_H_
#define DFS_H_

paths DFS(const Graph&);
void DFSutil(Graph,int, std::vector<bool>&, int,std::vector<int> &, bool &, std::vector<int>&);

#endif