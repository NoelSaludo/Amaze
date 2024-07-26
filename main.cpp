#include "global.h"
#include <raylib.h>

using namespace std;

vector<vector<int>> convertTo2D(const vector<string> &originalArray);

int main(int argc, char *argv[])
{
    vector<string> mazeFiles = 
    {"../resources/maze1.txt",
     "../resources/maze2.txt",
    "../resources/maze3.txt",
    "../resources/maze4.txt",
    "../resources/maze5.txt",
    "../resources/maze6.txt",
    "../resources/maze7.txt"};
    vector<Graph> mazes;
    Graph *selectedMaze;
    paths data;
    Display display;

    // Load each maze from file
    for (const auto &file : mazeFiles)
    {
        Graph maze(file);
        mazes.push_back(maze);
        Graph::MazeStruct mazeDetails = maze.StoreDetails();
        display.GetDetails(mazeDetails); 
    }
    int mazeChoice = 1; //maze1
    mazeChoice--; // Adjust for 0-based indexing

    //mazechoice++;

    // Perform the chosen algorithm on the selected maze
    for(int i = 0; i < mazeFiles.size(); i++)
    {
        selectedMaze = &mazes[i];
        data = DFS(*selectedMaze);
        data = BFS(*selectedMaze);
        display.AssignPath(i+1, data.Result, data.traverseList);
    }
    // display.printAll_linkedList(1);
    display.MazeSimulate(800,450);

    return 0;
}

Graph loadMaze(const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error opening maze data file: " << filename << endl;
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < length; ++i)
    {
        int row = i / n;
        int col = i % n;
        twoDArray[row][col] = i;
    }
    Graph maze(mazeData); // Create a Graph object with the maze data
    return maze;
}

//debug mo yung other mazes, tingin ko nasa variables lang problem

