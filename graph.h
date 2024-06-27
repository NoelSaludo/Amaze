#include <string>
#include <vector>
class Graph{
    public:
        Graph(std::string);
        void PrintGraph();
        void DFS(const std::string &);
        void LoadGraph(std::string&);
        
    private:
        u_int size;
        std::vector<std::vector<int>> Matrix;
        std::vector<std::string> Data;
        void loadMatrixTemp();
        void AddData(std::string);
        void AddEdge(int,int);
        void DFSutil(int,bool*);
        void ReadLines(std::vector<std::string>);

};