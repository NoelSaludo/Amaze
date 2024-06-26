#include <string>
class graph{
    public:
        graph(std::string);
        void PrintGraph();
        void DFS(const char &);
        void LoadGraph(std::string&);
        
    private:
        int size;
        int **Matrix;
        char *Data;
        void AddData(int,char);
        void AddEdge(int,int);
        void DFSutil(int,bool*);

};