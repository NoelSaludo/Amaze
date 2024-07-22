#include "global.h"
Display::Display() : head(nullptr), area(0), squared(0), expanded(0), start(0), end(0),lastUpdateTime(GetTime()){}

Display::~Display() {
    MazeDetails* current = head;
    while (current != nullptr) {
        MazeDetails* next = current->next;
        delete current;
        current = next;
    }
}
Display::MazeDetails* Display::CreateNewNode(const Graph::MazeStruct& mazeDetails) {
    MazeDetails* newNode = new MazeDetails;
    newNode->maze_area = mazeDetails.highest_tile;
    newNode->valid_edges = mazeDetails.MazeEdges;
    newNode->maze_start = mazeDetails.Maze_Start;
    newNode->maze_end = mazeDetails.Maze_End;
    newNode->next = nullptr;
    return newNode;
}

void Display::GetDetails(const Graph::MazeStruct& mazeDetails) {
    MazeDetails* newNode = CreateNewNode(mazeDetails);

    if (newNode == nullptr) {
        std::cerr << "Error: CreateNewNode returned nullptr" << std::endl;
        return;
    }

    if (head == nullptr) {
        head = newNode;
        std::cout << "Inserted first node with maze_area: " << newNode->maze_area << std::endl;
    } else {
        MazeDetails* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            std::cerr << "Error: temp is nullptr after traversal" << std::endl;
        } else {
            temp->next = newNode;
            std::cout << "Inserted new node with maze_area: " << newNode->maze_area << std::endl;
        }
    }
}



void Display::determinator(int tile)
{
    for(int i = 0; i < path.size();i++)
    {
        if(tile == path[i])
        {
            (path[i+1] - path[i] <= 1) ? std::cout << "_": std::cout << "|";
            // std::cout << "X";
            return;
        }
    }
    std::cout << " ";
}

void Display::determinator(const std::pair<int, int>& edge)
{
    for(int i = 0; i < path.size();i++)
    {
        if((edge.first == connectives[i].first && edge.second == connectives[i].second) || (edge.first == connectives[i].second && edge.second == connectives[i].first))
        {
            (edge.second - edge.first == 1) ? std::cout << "_": std::cout << "|";
                // std::cout << "X";
                return;
        }
    }

    for(int i = 0; i < edges.size();i++)
    {
        if((edge.first == edges[i].first && edge.second == edges[i].second) || (edge.first == edges[i].second && edge.second == edges[i].first))
        {
            std::cout << " ";
            return;
        }     
    }
    std::cout << "*"; 
}

void Display::create_connectives(){
        connectives.clear();
        if (path.size() < 2) return;
    for (size_t i = 0; i < path.size() - 1; i++) {
        connectives.push_back(std::make_pair(path[i], path[i + 1]));
    }
    }

bool Display::odd_even(int x){
if (x % 2 == 0){
    return true;
}
return false;
}


void Display::display_border(int border_counter)
{
    if (border_counter == area + 1){
        for (int i = 0; i  < expanded + 2; i++){
            // expanded_maze_size + 2
            if (i == ((start % area)*2) + 1){
                std::cout << "  ";
            }
            else{std::cout << "* ";}
            }
            std::cout << "\n";  
    }

    if (border_counter == area + 2){
        for (int i = 0; i  < expanded + 2; i++){
            if (i == ((end % squared)*2) + 1)
            {
                std::cout << "  ";
            }
            else{std::cout << "* ";}
            }
            std::cout << "\n";  
    }

    if(border_counter == 0){
        std::cout << "* ";
    }
    if(border_counter == expanded){
        std::cout << "*";
    }
}

void Display::AssignValue(int x,std::vector<int> data)
{
 MazeDetails* current = head;
 int target = 0;

  while (current != nullptr) {
            target++;
            if (target == x) 
            {
                area = current->maze_area;
                start = current->maze_start;
                end = current->maze_end;
                edges = current->valid_edges;
                //add path once determined kung paano mareretrieve
                squared = std::sqrt((area));
                expanded = ((squared * 2) - 1);

                current->traversed_path = data;
                current->traversed_path.push_back(end);
                path = current->traversed_path;

            }
            current = current->next;
  }

}

Display displayInfo;
void Display::MazeDisplay()
{
    create_connectives();

    std::cout << std::endl;
   
    int tile_counter = 0;
    int connective_counter = 0;
    std::pair<int, int>connective = std::make_pair(0,0);

    bool rowIsOdd;
    bool columnIsOdd;
    
    int border_counter = 1;
    display_border(area + 1);

        for (int i = 0; i < expanded; i++)
        {
            border_counter = 0;
            display_border(border_counter);
            
            for(int j = 0; j < expanded;j++)
            {
                border_counter++;

            columnIsOdd = odd_even(j), rowIsOdd = odd_even(i);      
            
                if(columnIsOdd) 
                {
                    if(rowIsOdd)//(Both Odd) - Tile;
                    {
                    determinator(tile_counter);
                    tile_counter++;
                    } else {// (Odd -> Even) - y-connective; 
                        connective = std::make_pair((tile_counter + connective_counter - squared) ,(tile_counter + connective_counter));
                        determinator(connective);
                        connective_counter++;
                    }
                } else {
                    if (rowIsOdd)//(Even -> Odd) x-connective
                    {
                        connective = std::make_pair(tile_counter - 1, tile_counter);
                        determinator(connective);
                        connective_counter;
                    }else{
                    std::cout << "*";
                    }
                }     
            std::cout << " ";
            }
            display_border(border_counter);
            std::cout << "\n";
            connective_counter = 0;
        }

        display_border(area + 2);

}

void Display::TileDeterminator(int tile, float x, float y, float size, Color color)
{

    for (int i = 0; i < path.size(); i++) {
        if (tile == path[i]) {
            DrawRectangle(x, y, size, size, color);
            return;
        }
    }
}

bool Display::ConnectiveDeterminator(const std::pair<int, int>& edge)
{//Pathconnective edge
    for(int i = 0; i < path.size();i++)
    {
        if((edge.first == connectives[i].first && edge.second == connectives[i].second) || (edge.first == connectives[i].second && edge.second == connectives[i].first))
        {
                return true;
        }
    }
//Valid Edge
    for(int i = 0; i < edges.size();i++)
    {
        if((edge.first == edges[i].first && edge.second == edges[i].second) || (edge.first == edges[i].second && edge.second == edges[i].first))
        {
            return true;
        }     
    }

    return false;
}
void Display::drawborder(int width, int height)
{
    size = (width - height);
    Tilesize = size / squared;


    posX = (width - size) / 2; // position of maze in x-axis
    posY = (height - size) / 2;  // position of maze in Y-axis

    thickness = Tilesize - (Tilesize - squared);
    DrawRectangleLinesEx({static_cast<float>(posX), static_cast<float>(posY), static_cast<float>(size), static_cast<float>(thickness)}, thickness, borderColor);
    DrawRectangleLinesEx({static_cast<float>(posX), static_cast<float>(posY + (Tilesize * squared)), static_cast<float>(size), static_cast<float>(thickness)}, thickness, borderColor);

    DrawRectangleLinesEx({static_cast<float>(posX), static_cast<float>(posY), static_cast<float>(thickness), static_cast<float>(size)}, thickness, borderColor);
    DrawRectangleLinesEx({static_cast<float>(posX + (Tilesize * squared)), static_cast<float>(posY), static_cast<float>(thickness), static_cast<float>(size + thickness)}, thickness, borderColor);


}

void Display::simulateEdge()
{

    int tile_counter = 0;
    int connective_counter = 0;
    std::pair<int, int> connective = std::make_pair(0, 0);

    bool rowIsOdd = true;
    bool columnIsOdd = true;

    int y_axis_counter = 0;
    
    EdgeCurrentPosX = (posX);
    EdgeCurrentPosY = (posY);

    
    for (int i = 0; i < expanded; i++) {
        for (int j = 0; j < expanded; j++) {
            columnIsOdd = odd_even(j);
            rowIsOdd = odd_even(i);

            if (y_axis_counter == 10) {
                y_axis_counter = 0;
                EdgeCurrentPosY += Tilesize;
            }

            if (columnIsOdd) {
                if (rowIsOdd) {
                    tile_counter++;
                    EdgeCurrentPosX += Tilesize;
                    y_axis_counter++;
                } else { 
                    connective = std::make_pair((tile_counter + connective_counter - 10), (tile_counter + connective_counter));
                    bool isValid = ConnectiveDeterminator(connective);
                    (isValid == false) ? DrawRectangle(EdgeCurrentPosX, EdgeCurrentPosY, Tilesize, Tilesize - (Tilesize - squared), BLACK) : (void)0;
                    EdgeCurrentPosX += Tilesize;
                    connective_counter++;
                }
            } else {
                if (rowIsOdd) { 
                    connective = std::make_pair(tile_counter - 1, tile_counter);
                    bool isValid = ConnectiveDeterminator(connective);
                    (isValid == false) ? DrawRectangle(EdgeCurrentPosX, EdgeCurrentPosY, Tilesize - (Tilesize - squared), Tilesize, BLACK) : (void)0;
                } else {
                    DrawRectangle(EdgeCurrentPosX, EdgeCurrentPosY, Tilesize - (Tilesize - squared), Tilesize - (Tilesize - squared), BLACK);
                }
            }
        }
        // Reset counters
        connective_counter = 0;
        EdgeCurrentPosX = posX;
    }
}

void Display::simulatePath()
{
    int tile_counter = 0;
    bool rowIsOdd = true;
    bool columnIsOdd = true;

    int y_axis_counter = 0;

    TileCurrentPosX = posX;
    TileCurrentPosY = posY;

    
    for (int i = 0; i < expanded; i++) {
        for (int j = 0; j < expanded; j++) 
        {
            columnIsOdd = odd_even(j);
            rowIsOdd = odd_even(i);

            if (y_axis_counter == 10) {
                y_axis_counter = 0;
                TileCurrentPosY += Tilesize;
            }

            if (columnIsOdd) {
                if (rowIsOdd)
                 { // (Both Odd) - Tile
                    // gap/2

                    TileDeterminator(tile_counter, TileCurrentPosX + thickness, TileCurrentPosY, Tilesize, RED);
                    update();
                    tile_counter++;
                    TileCurrentPosX += Tilesize;
                    EdgeCurrentPosX += Tilesize;
                    y_axis_counter++;
                }
            }
        }
        
        // Reset counters
        TileCurrentPosX = posX;
    }
}


void Display::update() {
    float currentTime = GetTime();
    while ((currentTime - lastUpdateTime) < delay) {
        // This loop will block for 5 seconds
        
        BeginDrawing();
        simulateEdge();
        EndDrawing();
        currentTime = GetTime();
    }
    lastUpdateTime = currentTime;
}

// void Display::update() {
//     float currentTime = GetTime();
//     if ((currentTime - lastUpdateTime) >= delay) {
//         // Enough time has passed, update the drawing
//         BeginDrawing();
//         simulateEdge(); // Draw the maze edge or whatever is needed
//         EndDrawing();

//         // Update the last update time
//         lastUpdateTime = currentTime;
//     }
// }
void Display::MazeSimulate(int screenWidth, int screenHeight) 
{
drawborder(screenWidth,screenHeight);
simulateEdge();
simulatePath();
}


//  int tile_counter = 0;
//     int connective_counter = 0;
//     std::pair<int, int> connective = std::make_pair(0, 0);

//     bool rowIsOdd = true;
//     bool columnIsOdd = true;

//     int y_axis_counter = 0;
//     int x_axis_counter = 0;

//     TileCurrentPosX = posX;
//     TileCurrentPosY = posY;

//     EdgeCurrentPosX = (posX);
//     EdgeCurrentPosY = (posY);

    
//     for (int i = 0; i < expanded; i++) {
//         for (int j = 0; j < expanded; j++) {
//             columnIsOdd = odd_even(j);
//             rowIsOdd = odd_even(i);

//             if (y_axis_counter == 10) {
//                 y_axis_counter = 0;
//                 TileCurrentPosY += Tilesize;
//                 EdgeCurrentPosY += Tilesize;
//             }

//             if (columnIsOdd) {
//                 if (rowIsOdd) { // (Both Odd) - Tile
//                     // gap/2
//                     TileDeterminator(tile_counter, TileCurrentPosX, TileCurrentPosY, Tilesize, RED);
//                     tile_counter++;
//                     TileCurrentPosX += Tilesize;
//                     EdgeCurrentPosX += Tilesize;
//                     y_axis_counter++;
//                 } else { 
//                     connective = std::make_pair((tile_counter + connective_counter - 10), (tile_counter + connective_counter));
//                     bool isValid = ConnectiveDeterminator(connective);
//                     (isValid == false) ? DrawRectangle(EdgeCurrentPosX, TileCurrentPosY, Tilesize, Tilesize - (Tilesize - squared), BLACK) : (void)0;
//                     EdgeCurrentPosX += Tilesize;
//                     connective_counter++;
//                     x_axis_counter++;
//                 }
//             } else {
//                 if (rowIsOdd) { 
//                     connective = std::make_pair(tile_counter - 1, tile_counter);
//                     bool isValid = ConnectiveDeterminator(connective);
//                     (isValid == false) ? DrawRectangle(EdgeCurrentPosX, TileCurrentPosY, Tilesize - (Tilesize - squared), Tilesize, BLACK) : (void)0;
//                     x_axis_counter++;
//                 } else {
//                     DrawRectangle(EdgeCurrentPosX, TileCurrentPosY, Tilesize - (Tilesize - squared), Tilesize - (Tilesize - squared), BLACK);
//                 }
//             }
//         }
//         // Reset counters
//         connective_counter = 0;
//         TileCurrentPosX = posX;
//         EdgeCurrentPosX = posX;
//     }