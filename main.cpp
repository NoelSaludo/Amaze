#include "global.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cerr << "Usage: " << argv[0] << " <maze_file>\n";
        return 1;
    }

    InitWindow(800, 600, "Maze Solver");
    SetTargetFPS(60);

    vector<Graph> mazes;
    for (int i = 1; i < argc; ++i)
    {
        mazes.emplace_back(argv[i]);
    }

    displayMainMenu();
    startMazeSolver(mazes);

    CloseWindow();
    return 0;
}
