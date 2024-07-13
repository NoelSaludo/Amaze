#include "solver.h"

std::vector<int> Solve(dnp data, int end)
{
    std::vector<int> path;
    int current = end;
    while (current != -1)
    {
        path.push_back(current);
        current = data.previousList[current];
    }
    std::reverse(path.begin(), path.end());
    return path;
}