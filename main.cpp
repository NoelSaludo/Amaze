#include "headers/global.h"

using namespace std;

void displayAllMazes(const vector<string> &);
int getUserChoice(const string &, int);
Graph loadMaze(const string &);
void printPath(const paths &);

const int screenWidth = 800;
const int screenHeight = 450;

int main()
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

    string line;
    string mazeData;
    while (getline(file, line))
    {
        mazeData += line + "\n";
    }
    file.close();

    Graph maze(mazeData); // Create a Graph object with the maze data
    return maze;
}

//debug mo yung other mazes, tingin ko nasa variables lang problem