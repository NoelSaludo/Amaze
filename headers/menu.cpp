#include "global.h"

using namespace std;

void displayAllMazes(const vector<Graph> &mazes)
{
    cout << "----------------------------------------------" << endl;
    cout << "|                 Available Mazes            |" << endl;
    cout << "----------------------------------------------" << endl;
    for (int i = 0; i < mazes.size(); i++)
    {
        cout << "| Maze " << i + 1 << "                                |" << endl;
    }
    cout << "----------------------------------------------" << endl;
}

int getUserChoice()
{
    int *choice = new int;
    displayMainMenu();
    cin >> *choice;
    checkCin();
    return *choice;
}

void checkCin()
{
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "----------------------------------------------" << endl;
        cout << "| Invalid choice.                            |" << endl;
        cout << "----------------------------------------------" << endl;
    }
}

void displayMainMenu()
{
    cout << "                                                 " << endl
         << "                                                 ###" << endl
         << "                                                #####" << endl
         << "                                               ### +##" << endl
         << "                                              ###   +##" << endl
         << "                                                     ###" << endl
         << "                                                      ###" << endl
         << "                                                       ##+" << endl
         << "                                          -##########   ##+" << endl
         << "                                         .##.      ###   ##+" << endl
         << "                                        .##.              ##-" << endl
         << "                                        ##-   ##-          ##-" << endl
         << "                                       ##-   ##+...........-##." << endl
         << "                                      ##-   ###################." << endl
         << "                                     ##-                     -##" << endl
         << "                                    ########.                 +##" << endl
         << "                                   ###--+##.             .##.  -##" << endl
         << "                                  ###   ##-  +#########+  -##.  +##" << endl
         << "                                 ###   ##-  +##            -########" << endl
         << "                                +##        +##                    ###" << endl
         << "                               +##        +##           ##+        ###" << endl
         << "                              -#############             #############+" << endl
         << "                              ............-               ............-" << endl
         << "                                                AMAZE                                " << endl;
    cout << "----------------------------------------------" << endl;
    cout << "|                   AMAZE                    |" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "|                   Main Menu                |" << endl;
    cout << "|                                            |" << endl;
    cout << "| 1. Start                                   |" << endl;
    cout << "| 2. View Maze                               |" << endl;
    cout << "| 3. Exit                                    |" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Enter your choice: ";

}

paths startMazeSolver(vector<Graph> &mazes)
{
    Graph *selectedMaze;
    paths solution;
    int solveChoice;

    while (true)
    {
        int choice = getUserChoice();

        switch (choice)
        {
        case 1:
            displayAllMazes(mazes);
            int mazeChoice;
            cout << "----------------------------------------------" << endl;
            cout << "| Select a maze to solve (1-" << mazes.size() << "): |" << endl;
            cout << "----------------------------------------------" << endl;
            cout << "Enter choice: ";
            cin >> mazeChoice;
            checkCin();
            if (mazeChoice < 1 || mazeChoice > mazes.size())
            {
                cout << "----------------------------------------------" << endl;
                cout << "| Invalid maze choice.                       |" << endl;
                cout << "----------------------------------------------" << endl;
                break;
            }
            selectedMaze = &mazes[mazeChoice - 1];
            cout << "----------------------------------------------" << endl;
            cout << "| Choose a solving algorithm:                |" << endl;
            cout << "| 1. Solve with DFS                          |" << endl;
            cout << "| 2. Solve with BFS                          |" << endl;
            cout << "----------------------------------------------" << endl;
            cin >> solveChoice;
            checkCin();
            if (solveChoice == 1)
            {
                solution = DFS(*selectedMaze);
            }
            else if (solveChoice == 2)
            {
                solution = BFS(*selectedMaze);
            }
            else
            {
                cout << "----------------------------------------------" << endl;
                cout << "| Invalid choice.                            |" << endl;
                cout << "----------------------------------------------" << endl;
                break;
            }
            cout << "----------------------------------------------" << endl;
            cout << "| Solved Path: ";
            for (int node : solution.Result)
            {
                cout << node << " ";
            }
            cout << "\n";
            cout << "| Time taken: " << solution.time << " ms               |" << endl;
            cout << "----------------------------------------------" << endl;
            return solution;
            break;
        case 2:
            displayAllMazes(mazes);
            break;
        case 3:
            cout << "----------------------------------------------" << endl;
            cout << "| Exiting the program.                       |" << endl;
            cout << "----------------------------------------------" << endl;
            exit(0);
            break;
        default:
            cout << "----------------------------------------------" << endl;
            cout << "| Invalid choice.                            |" << endl;
            cout << "----------------------------------------------" << endl;
            break;
        }
    }
    return solution;
}
