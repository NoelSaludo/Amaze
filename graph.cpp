#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include "graph.h"
#include <fmt/core.h>

using namespace std; 
using namespace fmt;

graph::graph(std::string file)
{
    char *Dataptr = &Data[0];
    size = strlen(Dataptr) - 1;
    Data = new char[size];
    SeedData(file);  
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
}

void graph::AddData(int Vertex, char data)
{
    if (0 <= Vertex < size)
    {
        this->Data[Vertex] = data;
    }
}

void graph::AddEdge(int x, int y,int weight)
{
    if (0 <= x < size && 0 <= y < size)
    {
        this->Matrix[x][y] = weight;
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
    for(int i = 0; i < size; i++)
        visited[i] = false;
    char* startIndex = find(Data,Data+size,start);
    DFSutil(startIndex-Data,visited);

}

void graph::SeedData(string& file)
{
    ifstream fin(file);
    if(!fin)
    {
        cout << "File not found" << endl;
        return;
    }
    if(!fin.is_open())
    {
        cout << "File not opened successfully" << endl;
    }
    vector<string> lines;
    while(!fin.eof())
    {
        string line;
        getline(fin,line);
        lines.push_back(line);
    }
    fin.close();
    for(string line: lines)
    {
        int x = line[0] - '0';
        char y = line[2];
        this->AddData(x,y);
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