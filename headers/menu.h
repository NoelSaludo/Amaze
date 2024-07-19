#ifndef MENU_H_
#define MENU_H_

#include <vector>
#include "graph.h"

void displayAllMazes(const std::vector<Graph>& mazes);
int getUserChoice();
void startMazeSolver(std::vector<Graph>& mazes);
void displayMainMenu();

#endif
