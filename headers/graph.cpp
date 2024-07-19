#include "global.h"

using namespace std;

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
                    break;
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

                    this->AddEdge(x, y);
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
        }
        if (lines[i] == "#end")
        {
            string end = lines[i + 1];
            this->End = find(Data.begin(), Data.end(), end) - Data.begin();
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
