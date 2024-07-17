#include <vector>
#include <string>
#include <algorithm>
#include "graph.h"
#include "solver.h"

#ifndef DFS_H_
#define DFS_H_

std::vector<int> DepthFirstSearch(const Graph&);
void DFSutil(Graph,int, std::vector<bool>&, int,std::vector<std::string> &, bool &, std::vector<int>&);

#endif