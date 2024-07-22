#include <vector>
#include <iostream>
#include <algorithm>

#ifndef SOLVER_H_
#define SOLVER_H_
typedef struct{
    std::vector<int> traverseList;
    int start;
    int end;
    std::vector<int> Result;
    int64_t time;
}paths;

std::vector<int> Solve(std::vector<int> data, int end);
#endif