#include "global.h"

using namespace std;

Graph::MazeStruct Graph::StoreDetails() {
    MazeStruct MazeDetails;
    MazeDetails.highest_tile = TileMaxSize;
    MazeDetails.MazeEdges = Edges;
    MazeDetails.Maze_Start = TileStart;
    MazeDetails.Maze_End = TileEnd;
    return MazeDetails;
}

Graph::Graph(string file)
{
    LoadGraph(file);
}

void Graph::AddData(string data)
{
    Data.push_back(data);
}

void Graph::AddEdge(int x, int y)
{
    if (0 <= x && x < size && 0 <= y && y < size)
    {
        this->Matrix[x][y] = 1;
        this->Matrix[y][x] = 1;
    }
    else
    {
        cout << "Invalid edge" << endl;
    }
}


void Graph::PlotEdge(int x, int y)
{
this->Edges.push_back(std::pair<int,int>(x,y));
// cout << "PUSH BACK ("<<x<<","<<y<<")\n";
}

void Graph::LoadGraph(string &file)
{
    ifstream fin(file);
    vector<string> lines;
    if (!fin)
    {
        cout << "File not found" << endl;
        return;
    }
    if (!fin.is_open())
    {
        cout << "File not opened successfully" << endl;
    }
    while (!fin.eof())
    {
        string line;
        getline(fin, line);
        lines.push_back(line);
    }
    fin.close();
    this->ReadLines(lines);

    //pwede din no? like no joke
    //create ka struct, print mo struct
    //gawa ka linked list, naka store sa graph, access mo yung linked list pag nag dfs na stostore mo pa dun yung path array,
    //traverse eh first head, sabay for (next ng next node), yun then get necessary details sa graph.h, pass mo variable

    //gets kona
    //main func, display traverse
    //GetDetailsTraverse = graph::Struct linked lists
    //then store mo yung na pull nun sa main
    //kunwari select - userhcoice, for (4 maze4), passa mo yung var from graph to display, sabay gawa ka ng func sa display na SetDetails (int x, y vector<pair,pair>)
}

void Graph::ReadLines(vector<string> lines)
{
    for (int i = 0; i < lines.size(); i++)
    {
        if (lines[i] == "#data")
        {
            for (int j = i + 1; j < lines.size(); j++)
            {
                if (lines[j] == "#edge")
                {
                    this->TileMaxSize = (j- 1);
                    //cout << "HIGHEST INDEX IS: " << j << "\n";
                    break;
                }
                string data = lines[j];
                this->AddData(data);
            }
            this->size = Data.size();
            continue;
        }
        if (lines[i] == "#edge")
        {
            this->loadMatrixTemp();
            for (int j = i + 1; j < lines.size(); j++)
            {
                if (lines[j] == "#start")
                    break;
                string line = lines[j];
                int commaIndex = line.find(",");
                try
                {
                    int x = stoi(line.substr(0, commaIndex));
                    int y = stoi(line.substr(commaIndex + 1));

                    this->EdgeList.push_back(make_pair(x, y));

                    this->AddEdge(x, y);
                    this->PlotEdge(x,y);
                }
                catch (const std::exception &e)
                {
                    std::cerr << e.what() << '\n';
                }
            }
        }
        if (lines[i] == "#start")
        {
            string start = lines[i + 1];
            this->Start = find(Data.begin(), Data.end(), start) - Data.begin();

            // cout << "start is: " << Start << "\n";
            this->TileStart = Start;
        }
        if (lines[i] == "#end")
        {
            string end = lines[i + 1];
            this->End = find(Data.begin(), Data.end(), end) - Data.begin();

            // cout << "end is: " << End << '\n';
            this->TileEnd = End;

        }
    }
}

void Graph::loadMatrixTemp()
{
    for (int i = 0; i < size; i++)
    {
        vector<int> temp;
        for (int j = 0; j < size; j++)
        {
            temp.push_back(0);
        }
        Matrix.push_back(temp);
    }
}

void Graph::PrintGraph() const // Add const here
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
        cout << endl; // theodore
    }
}

int Graph::GetSize() const
{
    return size;
}
