#include <string>
class graph{
    public:
        graph(std::string);
        void AddData(int,char);
        void AddEdge(int,int,int);
        void PrintGraph();
        void DFS(const char &);
    private:
        int size;
        int **Matrix;
        char *Data;
        void DFSutil(int,bool*);
        void SeedData(std::string&);
};