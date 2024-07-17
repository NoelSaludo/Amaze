#include "solver.h"

std::vector<int> Solve(std::vector<int> data, int end)
{
    std::vector<int> path;
    int current = end;
    while (current != -1)
    {
        path.push_back(data[current]);
        current = data[current];
    }
    std::reverse(path.begin(), path.end());
    return path;
}