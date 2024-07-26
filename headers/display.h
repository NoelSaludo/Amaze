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
    std::vector<int> traversed;
    std::vector<std::pair<int, int>> edges;
    std::vector<std::pair<int, int>> connectives;
    std::vector<int>MazeInArrayForm;
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
        std::vector<int>traversed_data;
        //dagdagan ko ng path sa loob
        //pero pwede rin mamaya yung walang assignValue, try ko
        MazeDetails* next;
    } MazeDetails;

    Display();
    ~Display();
    bool odd_even(int x);
    
    void GetDetails(const Graph::MazeStruct& mazeDetails);
    void AssignPath(int x, std::vector<int>data, std::vector<int>traversed_data);
    void printAll_linkedList(int x);
    void WindowInitialize(float width, float height);

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

        int tile_counter = 0;
        int index_counter = 0;

        int y_axis_counter = 0;
        int x_axis_counter = 0;
        
        int endingTile;

        void MazeSimulate(float width, float height);
        void simulatePath(int x);

        void switcher();

        float lastUpdateTime = 0;
        const float delay = 0.2f;
        bool switchSignal = false;
        bool ModifiedswitchSignal = false;

        float prevCurrentX = posX;

        float PlayerCurrentPosX;
        float PlayerCurrentPosY;
        int PlayerCurrentIndex; 
        int InitializeCallOnce;
        int PlayerCounterX;
        int PlayerCounterY;
        
        float Xposition(int x, int mode);
        float Yposition(int y, int mode);

        typedef enum GameScreen { LOGO, MAZE1, MAZE2, MAZE3, MAZE4, MAZE5,MAZE6,MAZE7, SIMULATE,DFS,BFS,BOTH,SOLVE} GameScreen;
        int framesCounter = 0;       
        bool gamePaused = false; 


        bool PlayMazeSolved;
        bool SimulationMazeSolved;

        bool SimulateEnd;
        bool SimulateEndSignal;
        int range = 0;
        bool ReturnScreen = false;


        int TileDirection;
        int PrevTileDirection;
        int CurrentTileDirection;
        int NextTileDirection;

        void PrintMazeInArray();

private:
//determinator, dofenshmirtzh
    bool ConnectiveDeterminator(const std::pair<int, int>& edge);

    void create_connectives();

    MazeDetails* head;
    MazeDetails* CreateNewNode(const Graph::MazeStruct& mazeDetails);

    void drawborder();
    void simulateEdge(float x, float y);

    float screenWidth;
    float screenHeight;
    
    void UpdatePlayerPosition();
    void CheckMazeCollision(int x);
    void PlayMaze();
    void PlaySolveSignal();
    void SimulateSolveSignal();
    void InitializeStartingPosition();
    bool Modifiedswitcher(float ModifiedDelay);

    void simulateAlgorithm(int x);

    void DetermineMazeArrayForm();
    
     void Initializer(int x, float width, float height);
     int directionality(int i,int mode);

     void DrawLogo();
     void DrawBoldText();
     };

#endif // DISPLAY_H