#include "global.h"
#include <raylib.h>

using namespace std;

vector<vector<int>> convertTo2D(const vector<string> &originalArray);

int main(int argc, char *argv[])
{
    if (system("clear"))
        system("cls");

    vector<Graph> mazes{
        Graph("../resources/maze1.txt"),
        Graph("../resources/maze2.txt"),
        Graph("../resources/maze3.txt"),
        Graph("../resources/maze4.txt"),
        Graph("../resources/maze5.txt")};

    paths solution = startMazeSolver(mazes);

    vector<vector<int>> maze = convertTo2D(solution.maze->Data);

    cout << "Maze: " << endl;
    for (int i = 0; i < maze.size(); i++)
    {
        for (int j = 0; j < maze[i].size(); j++)
        {
            if (maze[i][j] <= 9)
            {
                cout << " " << maze[i][j] << " ";
                continue;
            }
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
    InitWindow(1100, 1100, "Maze Solver");
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        auto edgeList = solution.maze->EdgeList;
        int cellSizeY = 100, cellSizeX = 100;
        BeginDrawing();
        ClearBackground(BLACK);
        for (int i = 0; i < maze.size(); i++)
        {
            int posy = (i)*cellSizeY, posx = 0;
            for (int j = 0; j < maze[i].size(); j++)
            {
                posx = j * cellSizeX;
                int bottom =maze[i][j], right = maze[i][j], left = maze[i][j], current = maze[i][j];
                if(i+1 < maze.size()){
                    bottom = maze[i+1][j];
                }
                if(j+1 < maze.size()){
                    right = maze[i][j+1];
                }
                if(j-1 >= 0){
                    left = maze[i][j-1];
                }
                if(find(edgeList.begin(), edgeList.end(), make_pair(current, bottom)) != edgeList.end() ||
                    find(edgeList.begin(), edgeList.end(), make_pair(bottom, current)) != edgeList.end()){
                    DrawRectangle(posx, posy, cellSizeX-10, cellSizeY+10, RAYWHITE);
                }
                if(find(edgeList.begin(), edgeList.end(), make_pair(current, right)) != edgeList.end() ||
                    find(edgeList.begin(), edgeList.end(), make_pair(right, current)) != edgeList.end()){
                    DrawRectangle(posx, posy, cellSizeX+10, cellSizeY-10, RAYWHITE);
                }
                if(find(edgeList.begin(), edgeList.end(), make_pair(current, left)) != edgeList.end() ||
                    find(edgeList.begin(), edgeList.end(), make_pair(left, current)) != edgeList.end()){
                    DrawRectangle(posx-10, posy, cellSizeX, cellSizeY-10, RAYWHITE);
                }
                else{
                    DrawRectangle(posx, posy, cellSizeX-10, cellSizeY-10, RAYWHITE);
                }
                if(maze[i][j] == solution.start){
                    DrawRectangle(posx, posy, cellSizeX-10, cellSizeY-10, GREEN);
                }
                if(maze[i][j] == solution.end){
                    DrawRectangle(posx, posy, cellSizeX-10, cellSizeY-10, RED);
                } 
                DrawText(TextFormat("%d", maze[i][j]), posx+cellSizeX/2-10, posy+cellSizeY/2-10, 20, BLACK);


            }
        }

        EndDrawing();
    }
    CloseWindow();
    return 0;
}

vector<vector<int>> convertTo2D(const vector<string> &originalArray)
{
    int length = originalArray.size();
    int n = (int)sqrt(length); // Assuming the original array's size is a perfect square

    vector<vector<int>> twoDArray(n, vector<int>(n));

    for (int i = 0; i < length; ++i)
    {
        int row = i / n;
        int col = i % n;
        twoDArray[row][col] = i;
    }

    return twoDArray;
}
