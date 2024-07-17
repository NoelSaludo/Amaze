#include <string>
#include <vector>

#ifndef GRAPH_H_
#define GRAPH_H_

class Graph
{
    public:
        Graph(std::string);
        void PrintGraph();
        void LoadGraph(std::string&);
        int Start;
        int End;
        std::vector<std::string> Data;
        std::vector<std::vector<int>> Matrix;
        int GetSize() const;
        
    private:
        int size;
        void loadMatrixTemp();
        void AddData(std::string);
        void AddEdge(int,int);
        void ReadLines(std::vector<std::string>);

};
#endif