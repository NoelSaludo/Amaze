#include <vector>
#include <string>
#include "graph.h"

#ifndef SOLVER_H_
#define SOLVER_H_

std::vector<std::string> DepthFirstSearch(const Graph&);
void DFSutil(Graph,int, std::vector<bool>&, int,std::vector<std::string> &, bool &);

#endif