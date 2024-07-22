#include "global.h"

using namespace std;

void displayAllMazes(const vector<Graph>& mazes)
{
    for (int i = 0; i < mazes.size(); i++)
    {
        cout << "Maze " << i+1 << "\n";
        cout << "\n";
    }
}

int getUserChoice()
{
    int choice;
    displayMainMenu();
    cin >> choice;
    return choice;
}

void displayMainMenu()
{
    
    cout << "Main Menu\n";
    cout << "1. Start\n";
    cout << "2. View Maze\n";
    cout << "3. Exit\n";
}

void checkCin()
{
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid choice.\n";
    }
}

paths startMazeSolver(vector<Graph>& mazes)
{
    Graph *selectedMaze;
    paths solution;
    int solveChoice;

    while (true)
    {
        int choice = getUserChoice();
        checkCin();

        switch (choice)
        {
            case 1:
            {
                displayAllMazes(mazes);
                int mazeChoice;
                cout << "Select a maze to solve (1-" << mazes.size() << "): ";
                cin >> mazeChoice;
                checkCin();
                selectedMaze = &mazes[mazeChoice - 1];
                if (mazeChoice < 1 || mazeChoice > mazes.size())
                {
                    cout << "Invalid maze choice.\n";
                    break;
                }
                cout << "Choose a solving algorithm:\n";
                cout << "1. Solve with DFS\n";
                cout << "2. Solve with BFS\n";
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
                    cout << "Invalid choice.\n";
                    break;
                }
                cout << "Solved Path: ";
                for (int node : solution.Result)
                {
                    cout << node << " ";
                }
                cout << "\n";
                cout << "Time taken: " << solution.time << " ms\n";
                return solution;
                break;
            }
            case 2:
                displayAllMazes(mazes);
                break;
            case 3:
                cout << "Exiting the program.\n";
                exit(0);
                break;
            default:
                cout << "Invalid choice.\n";
                break;
        }
    }
    return solution;
}
