#include "menu.h"
#include "global.h"
#include <iostream>
#include <vector>

using namespace std;

void displayAllMazes(const vector<Graph>& mazes)
{
    for (size_t i = 0; i < mazes.size(); ++i)
    {
        cout << "Maze " << i + 1 << ":\n";
        mazes[i].PrintGraph();
        cout << "\n";
    }
}

int getUserChoice()
{
    int choice;
    cout << "Choose an option:\n";
    cout << "1. Start\n";
    cout << "2. View Maze\n";
    cout << "3. Exit\n";
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

void startMazeSolver(vector<Graph>& mazes)
{
    int choice = getUserChoice();

    while (choice != 3)
    {
        switch (choice)
        {
            case 1:
            {
                int mazeChoice;
                cout << "Select a maze to solve (1-" << mazes.size() << "): ";
                cin >> mazeChoice;
                if (mazeChoice < 1 || mazeChoice > mazes.size())
                {
                    cout << "Invalid maze choice.\n";
                    break;
                }
                Graph& selectedMaze = mazes[mazeChoice - 1];
                paths solution;
                int solveChoice;
                cout << "Choose a solving algorithm:\n";
                cout << "1. Solve with DFS\n";
                cout << "2. Solve with BFS\n";
                cin >> solveChoice;
                if (solveChoice == 1)
                {
                    solution = DFS(selectedMaze);
                }
                else if (solveChoice == 2)
                {
                    solution = BFS(selectedMaze);
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
                break;
            }
            case 2:
                displayAllMazes(mazes);
                break;
            default:
                cout << "Invalid choice.\n";
                break;
        }
        displayMainMenu();
        choice = getUserChoice();
    }
    cout << "Exiting the program.\n";
}
