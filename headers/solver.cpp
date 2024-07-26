#include "global.h"

std::vector<int> Solve(std::vector<int> data, int end)
{
    std::vector<int> path;
    int current = end;
    path.push_back(end);
    while (current != -1)
    {
        if(data[current] == -1)
            break;
        path.push_back(data[current]);
        current = data[current];
    }
    std::reverse(path.begin(), path.end());
    return path;
}