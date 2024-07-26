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
    int64_t timeTaken;

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
                cin.ignore(2);
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
                auto start = chrono::high_resolution_clock::now();
                solution = DFS(*selectedMaze);
                auto end = chrono::high_resolution_clock::now();
                solution.timeTaken = chrono::duration_cast<chrono::microseconds>(end - start).count();
            }
            else if (solveChoice == 2)
            {
                auto start = chrono::high_resolution_clock::now();
                solution = BFS(*selectedMaze);
                auto end = chrono::high_resolution_clock::now();

                solution.timeTaken = chrono::duration_cast<chrono::microseconds>(end - start).count();
            }
            else
            {
                cout << "----------------------------------------------" << endl;
                cout << "| Invalid choice.                            |" << endl;
                cout << "----------------------------------------------" << endl;
                cin.ignore(2);
                break;
            }
            cout << "----------------------------------------------" << endl;
            cout << "| Solved Path: ";
            for (int node : solution.Result)
            {
                cout << node << " ";
            }
            cout << "\n";
            cout << "| Time taken: " << solution.timeTaken << " microseconds              |" << endl;
            cout << "----------------------------------------------" << endl;
            solution.maze = selectedMaze;
            return solution;
            break;
        case 2:
            displayAllMazes(mazes);
            cout << "Press enter to continue...";
            cin.ignore(2);
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
            cin.ignore(2);
            break;
        }
    }
    return solution;
}
