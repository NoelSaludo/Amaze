#include <string>
#include <vector>
class Graph{
    public:
        Graph(std::string);
        void PrintGraph();
        void LoadGraph(std::string&);
        std::string Start;
        std::string End;
        
    private:
        u_int size;
        std::vector<std::vector<int>> Matrix;
        std::vector<std::string> Data;
        void loadMatrixTemp();
        void AddData(std::string);
        void AddEdge(int,int);
        void ReadLines(std::vector<std::string>);

};