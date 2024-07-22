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
    vector<User> users;
    vector<string> mazeFiles = {"../resources/maze1.txt", "../resources/maze2.txt", "../resources/maze3.txt", "../resources/maze4.txt"};
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

    
    //need mopa ng isa pang menu, if terminal ang choice or raylibs
    // Display loaded mazes
    displayAllMazes(mazeFiles);

    // Get user choice for the maze and algorithm
    int mazeChoice = getUserChoice("Choose a maze (1-4): ", mazes.size());
    mazeChoice--; // Adjust for 0-based indexing

    //mazechoice++;

    int algorithmChoice = getUserChoice("Choose an algorithm:\n1. Depth-First Search (DFS)\n2. Breadth-First Search (BFS)\n Enter choice: ", 2);

    // Perform the chosen algorithm on the selected maze
    selectedMaze = &mazes[mazeChoice];

    if (algorithmChoice == 1)
    {
        data = DFS(*selectedMaze);
    }

    else if (algorithmChoice == 2)
    {
        data = BFS(*selectedMaze);
    }

    printPath(data);
    cout << "CHOSEN MAZE: " << mazeChoice + 1 <<'\n';
    for(int i = 0; i < data.Result.size();i++){
        cout << data.Result[i] << " ";
    }

    display.AssignValue(mazeChoice+1, data.Result);
    display.MazeDisplay();
    cout << "press a key";
    getch();
    

    InitWindow(screenWidth, screenHeight, "Maze Solver");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        
        ClearBackground(RAYWHITE);
        display.MazeSimulate(screenWidth, screenHeight); // Draw the maze
        
        EndDrawing();       
        
           
           
       

        
    }
    CloseWindow();

    return 0;
    
}

void printPath(const paths &data)
{
    if (data.Result.empty())
    {
        cout << "No path found." << endl;
    }
    else
    {
        cout << "Path found!" << endl;
        cout << "Path: ";
        for (int i = 0; i < data.Result.size(); ++i)
        {
            if(data.Result[i] == -1){
                continue;
            }
            cout << data.Result[i];
            if (i < data.Result.size() - 1)
            {
                cout << " -> ";
            }
        }
        cout << endl;
    }
}

// Display all available mazes
void displayAllMazes(const vector<string> &mazeFiles)
{
    cout << "Loaded Mazes:" << endl;
    for (size_t i = 0; i < mazeFiles.size(); ++i)
    {
        cout << i + 1 << ". " << mazeFiles[i] << endl;
    }
    cout << endl;
}

// Get a valid user choice within the specified range
int getUserChoice(const string &prompt, int maxChoice)
{
    int choice;
    while (true)
    {
        cout << prompt;
        cin >> choice;
        if (choice >= 1 && choice <= maxChoice)
        {
            break;
        }
        else
        {
            cout << "Invalid choice. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return choice;
}

// Load a maze from a file
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