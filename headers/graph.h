#ifndef GRAPH_H_
#define GRAPH_H_

#include <string>
#include <vector>

class Graph
{
public:
    Graph(std::string);
    void PrintGraph() const; // Add const here
    void LoadGraph(std::string&);
    int Start;
    int End;
    std::vector<std::string> Data;
    std::vector<std::vector<int>> Matrix;
    int GetSize() const;
    std::vector<std::pair<int, int>> EdgeList;

private:
    int size;
    void loadMatrixTemp();
    void AddData(std::string);
    void AddEdge(int, int);
    void ReadLines(std::vector<std::string>);
};

#endif
