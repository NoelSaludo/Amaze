#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstring>
#include "graph.h"

using namespace std;

graph::graph(std::string file)
{
    char *Dataptr = &Data[0];
    size = strlen(Dataptr) - 1;
    Data = new char[size];
    Matrix = new int *[size];
    for (int i = 0; i < size; i++)
    {
        Matrix[i] = new int[size];
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            Matrix[i][j] = 0;
        }
    }
    LoadGraph(file);
}

void graph::AddData(int Vertex, char data)
{
    if (0 <= Vertex < size)
    {
        this->Data[Vertex] = data;
    }
}

void graph::AddEdge(int x, int y)
{
    if (0 <= x && x < size && 0 <= y && y < size)
    {
        this->Matrix[x][y] = 1;
        this->Matrix[y][x] = 1;
    }
}

void graph::DFSutil(int start, bool *visited)
{
    visited[start] = true;
    cout << Data[start] << " ";
    for (int i = 0; i < size; i++)
    {
        if (Matrix[start][i] != 0 && !visited[i])
        {
            DFSutil(i, visited);
        }
    }
}

void graph::DFS(const char &start)
{
    bool visited[size];
    for (int i = 0; i < size; i++)
        visited[i] = false;
    char *startIndex = find(Data, Data + size, start);
    DFSutil(startIndex - Data, visited);
}

void graph::LoadGraph(string &file)
{
    ifstream fin(file);
    if (!fin)
    {
        cout << "File not found" << endl;
        return;
    }
    if (!fin.is_open())
    {
        cout << "File not opened successfully" << endl;
    }
    vector<string> lines;
    while (!fin.eof())
    {
        string line;
        getline(fin, line);
        lines.push_back(line);
    }
    fin.close();
    for (int i = 0; i < lines.size(); i++)
    {
        if (lines[i] == "#data")
        {
            for (int j = i + 1; j < lines.size(); j++)
            {
                if (lines[j] == "#edge")
                    break;
                char data = lines[j][0];
                this->AddData(j - 1, data);
            }
            continue;
        }
        if (lines[i] == "#edge")
        {
            for (int j = i + 1; j < lines.size(); j++)
            {
                int x = lines[j][0] - '0';
                int y = lines[j][2] - '0';
                this->AddEdge(x, y);
            }
        }
    }
}
void graph::PrintGraph()
{
    cout << "  ";
    for (int i = 0; i < size; i++)
    {
        cout << Data[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << Data[i] << " ";
        for (int j = 0; j < size; j++)
        {
            cout << Matrix[i][j] << " ";
        }
        cout << endl;
    }
}