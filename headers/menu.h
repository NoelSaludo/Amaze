#ifndef MENU_H_
#define MENU_H_

#include <vector>
#include "graph.h"
#include "paths.h"

void displayAllMazes(const std::vector<Graph>& mazes);
int getUserChoice();
paths startMazeSolver(std::vector<Graph>& mazes);
void displayMainMenu();

#endif
