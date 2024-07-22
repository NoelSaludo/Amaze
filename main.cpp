#include "global.h"

using namespace std;

int main(int argc, char *argv[])
{

    vector<Graph> mazes{
        Graph("../resources/maze1.txt"),
        Graph("../resources/maze2.txt"),
        Graph("../resources/maze3.txt"),
        Graph("../resources/maze4.txt"),
        Graph("../resources/maze5.txt")
    };

    paths solution = startMazeSolver(mazes);

    InitWindow(800, 600, "Maze Solver");
    SetTargetFPS(60);
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
