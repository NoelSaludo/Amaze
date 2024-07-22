#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include "graph.h"

#ifndef DISPLAY_H
#define DISPLAY_H

class Display {
public:
    std::vector<int> path;
    std::vector<std::pair<int, int>> edges;
    std::vector<std::pair<int, int>> connectives;
    int area;
    int squared;
    int expanded;
    int start;
    int end;
    typedef struct MazeDetails {
        int maze_area;
        std::vector<std::pair<int, int>> valid_edges;
        int maze_start;
        int maze_end;
        std::vector<int>traversed_path;
        //dagdagan ko ng path sa loob
        //pero pwede rin mamaya yung walang assignValue, try ko
        MazeDetails* next;
    } MazeDetails;

    Display();
    ~Display();
    bool odd_even(int x);
    
    void GetDetails(const Graph::MazeStruct& mazeDetails);
    void AssignValue(int x, std::vector<int>data);
    void MazeDisplay();

        float posX; // X position of the top-left corner
        float posY; // Y position of the top-left corner
        float size; // Width and height of the square // constant
        float thickness; // Thickness of the border //iisipin kopa
        Color borderColor = BLACK; // Color of the border //matic const
        float TileCurrentPosX;
        float TileCurrentPosY;
        float EdgeCurrentPosX;
        float EdgeCurrentPosY;
        float Tilesize;

        void MazeSimulate(int screenWitdh, int screenHeight);
        void update();
        void simulatePath();

        float lastUpdateTime = 0;
        const float delay = 0.3f;

private:
    //delay timer
    

    void determinator(int tile);
    void determinator(const std::pair<int, int>& edge);
//determinator, dofenshmirtzh
    void TileDeterminator(int tile, float x, float y, float size, Color color);
    bool ConnectiveDeterminator(const std::pair<int, int>& edge);

    void create_connectives();
    void display_border(int border_counter);
    MazeDetails* head;
    MazeDetails* CreateNewNode(const Graph::MazeStruct& mazeDetails);

    void drawborder(int width,int height);
    void simulateEdge();

};

#endif // DISPLAY_H