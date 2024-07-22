#include <string>
#include <vector>
#include <utility>

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
        int TileStart;
        int TileEnd;
        int TileMaxSize;
        std::vector<std::string> Data;
        std::vector<std::vector<int>> Matrix;
        std::vector<std::pair<int,int>>Edges;
        int GetSize() const;
        typedef struct {
            int highest_tile;
            std::vector<std::pair<int,int>>MazeEdges;
            int Maze_Start;
            int Maze_End;
        }MazeStruct;

        MazeStruct StoreDetails();
        
    private:
        int size;
        void loadMatrixTemp();
        void AddData(std::string);
        void AddEdge(int,int);
        void PlotEdge(int,int);
        void ReadLines(std::vector<std::string>);
};
#endif