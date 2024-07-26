#include "global.h"
Display::Display() : head(nullptr), area(0), squared(0), expanded(0), start(0), end(0), lastUpdateTime(GetTime()) {}

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

void Display::GetDetails(const Graph::MazeStruct& mazeDetails)
 {
    MazeDetails* newNode = CreateNewNode(mazeDetails);

    if (newNode == nullptr) {
        std::cerr << "Error: CreateNewNode returned nullptr" << std::endl;
        return;
    }

    if (head == nullptr) {
        head = newNode;
        
    } else {
        MazeDetails* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            
        } else {
            temp->next = newNode;
            
        }
    }
}

bool Display::odd_even(int x){
if (x % 2 == 0){
    return true;
}
return false;
}


void Display::AssignPath(int x,std::vector<int> data, std::vector<int>traversed_data)
{
 MazeDetails* current = head;
 int target = 0;

  while (current != nullptr) {
            target++;
            if (target == x) 
            {
                current->traversed_path = data;
                current->traversed_path.push_back(end);
                current->traversed_data = traversed_data;
            }
            current = current->next;
  }

}
void Display::printAll_linkedList(int x)
{
 MazeDetails* current = head;
int target = 0;
  while (current != nullptr) {
    target++;
    if(target == x){
                 // Print MazeDetails members
                std::cout << "Maze Area: " << current->maze_area << "\n";
                std::cout << "Maze Start: " << current->maze_start << "\n";
                std::cout << "Maze End: " << current->maze_end << "\n";

                // Print valid_edges
                std::cout << "Valid Edges: ";
                for (const auto& edge : current->valid_edges) {
                    std::cout << "(" << edge.first << ", " << edge.second << ") ";
                }
                std::cout << "\n";

                // Print traversed_path
                std::cout << "Traversed Path: ";
                for (const int& path : current->traversed_path) {
                    std::cout << path << " ";
                }
                std::cout << "\n";

                // Print traversed_data
                std::cout << "Traversed Data: ";
                for (const int& data : current->traversed_data) {
                    std::cout << data << " ";
                }
                std::cout << "\n\n\n";
            }
            current = current->next;
  }
}


void Display::create_connectives()
{
    connectives.clear();
    if (path.size() < 2) return;
    for (size_t i = 0; i < path.size() - 1; i++) 
        {
        connectives.push_back(std::make_pair(path[i], path[i + 1]));
        }
}


void Display::Initializer(int x, float width, float height)
{
 MazeDetails* current = head;
 int target = 0;

  while (current != nullptr) {
            target++;
            if (target == x) 
            {
                area = current->maze_area;
                squared = std::sqrt((area));
                expanded = ((squared * 2) - 1);
                start = current->maze_start;
                end = current->maze_end;
                edges = current->valid_edges;

                traversed = current->traversed_data;
                path = current->traversed_path;
                
            }
            current = current->next;
  }
endingTile = end % squared; 
create_connectives();
WindowInitialize(width, height);
}


void Display::WindowInitialize(float width, float height){
    screenWidth = width;
    screenHeight = height;
    size = (width - height);
    posX = (width - size) / 2; // position of maze in x-axis
    posY = ((height - size) / 2);  // position of maze in Y-axis
    
    thickness = Tilesize - (Tilesize - squared);
    Tilesize = size / squared;
    EdgeCurrentPosX = (posX);
    EdgeCurrentPosY = (posY);
}


bool Display::ConnectiveDeterminator(const std::pair<int, int>& edge)
{//Pathconnective edge
    for(int i = 0; i < path.size();i++)
    {
        if((edge.first == connectives[i].first && edge.second == connectives[i].second)){ return true;}
        if((edge.first == connectives[i].second && edge.second == connectives[i].first)){ return true;}
    }

    for(int i = 0; i < edges.size();i++)
    {
        if((edge.first == edges[i].first && edge.second == edges[i].second)){return true;}
        if((edge.first == edges[i].second && edge.second == edges[i].first)){return true;}     
    }

    return false;
}


void Display::drawborder()
{
    
    DrawRectangleLinesEx({static_cast<float>(posX), static_cast<float>(posY), static_cast<float>(size), static_cast<float>(thickness)}, thickness, borderColor);
    
    DrawRectangleLinesEx({static_cast<float>(posX), static_cast<float>(posY + (Tilesize * squared)), static_cast<float>(size), static_cast<float>(thickness)}, thickness, borderColor);

    DrawRectangleLinesEx({static_cast<float>(posX), static_cast<float>(posY), static_cast<float>(thickness), static_cast<float>(size)}, thickness, borderColor);
    DrawRectangleLinesEx({static_cast<float>(posX + (Tilesize * squared)), static_cast<float>(posY), static_cast<float>(thickness), static_cast<float>(size + thickness)}, thickness, borderColor);

    DrawRectangleLinesEx({static_cast<float>(posX +(Tilesize * start) + (thickness)), static_cast<float>(posY), static_cast<float>(Tilesize - thickness), static_cast<float>(thickness)}, thickness, RAYWHITE);
    DrawRectangleLinesEx({static_cast<float>(posX +(Tilesize * endingTile) + (thickness)), static_cast<float>(posY + (Tilesize * squared)), static_cast<float>(Tilesize - thickness), static_cast<float>(thickness)}, thickness, RAYWHITE);
}

void Display::simulateEdge(float x, float y)
{
    WindowInitialize(x,y);
    int tile_counter = 0;
    int connective_counter = 0;
    int y_axis_counter = 0;
    bool rowIsOdd, columnIsOdd;

    
    for (int i = 0; i < expanded; i++) 
    {
        for (int j = 0; j < expanded; j++) 
        {
            columnIsOdd = odd_even(j);
            rowIsOdd = odd_even(i);

            if (y_axis_counter == squared) 
                {
                    y_axis_counter = 0;
                    EdgeCurrentPosY += Tilesize;
                }

            if (columnIsOdd && rowIsOdd) 
            {
                    tile_counter++;
                    EdgeCurrentPosX += Tilesize;
                    y_axis_counter++;
            }   

            if (columnIsOdd && !rowIsOdd ) 
             {
                 std::pair<int, int> connective = std::make_pair((tile_counter + connective_counter - squared), (tile_counter + connective_counter));
                bool isValid = ConnectiveDeterminator(connective);
                (isValid) ? (void)0 : DrawRectangle(EdgeCurrentPosX, EdgeCurrentPosY, Tilesize, Tilesize - (Tilesize - squared), BLACK);
                EdgeCurrentPosX += Tilesize;
                connective_counter++;
            }
            if (!columnIsOdd && rowIsOdd)
            {
            std::pair<int, int>connective = std::make_pair(tile_counter - 1, tile_counter);
            bool isValid = ConnectiveDeterminator(connective);
            (isValid) ? (void)0 : DrawRectangle(EdgeCurrentPosX, EdgeCurrentPosY, Tilesize - (Tilesize - squared), Tilesize, BLACK);
            } 
            else { DrawRectangle(EdgeCurrentPosX, EdgeCurrentPosY, Tilesize - (Tilesize - squared), Tilesize - (Tilesize - squared), BLACK);}
            }

            
        connective_counter = 0;
        EdgeCurrentPosX = posX;
    }
}

void Display::DetermineMazeArrayForm()
{
    int tile_counter = 0;
    int connective_counter = 0;
    bool rowIsOdd, columnIsOdd;

    for (int i = 0; i < expanded; i++) 
    {
        for (int j = 0; j < expanded; j++) 
        {
            columnIsOdd = odd_even(j);
            rowIsOdd = odd_even(i);

            if (columnIsOdd && rowIsOdd) 
            {
                MazeInArrayForm.push_back(tile_counter);
                tile_counter++;
            }   

            if (columnIsOdd && !rowIsOdd ) 
             {
                std::pair<int, int> connective = std::make_pair((tile_counter + connective_counter - squared), (tile_counter + connective_counter));
                bool isValid = ConnectiveDeterminator(connective);
                (isValid) ? MazeInArrayForm.push_back(area + 1) : MazeInArrayForm.push_back(area + 2);
                connective_counter++;
            }
            if (!columnIsOdd && rowIsOdd)
            {
            std::pair<int, int>connective = std::make_pair(tile_counter - 1, tile_counter);
            bool isValid = ConnectiveDeterminator(connective);
            (isValid) ? MazeInArrayForm.push_back(area+ 1) : MazeInArrayForm.push_back(area + 2);
            } 
            if(!columnIsOdd && !rowIsOdd) {MazeInArrayForm.push_back(area + area);}
            }
        connective_counter = 0;
    }
}

void Display::PrintMazeInArray()
{
    int counter = 0;
for(int i = 0; i < MazeInArrayForm.size(); i++)


{
if (counter == 9)
{
counter = 0;
std::cout << "\n";
}
std::cout << "(" << MazeInArrayForm[i]<< ")"; 


}
}



void Display::switcher() 
{
    float currentTime = GetTime();
    if ((currentTime - lastUpdateTime) >= delay) 
    {   
        // if(switchSignal)
        // {
        //     switchSignal = false;
        // }else{switchSignal = true;
        // }

        switchSignal = !switchSignal;
        lastUpdateTime = currentTime;
    }
}


void Display::simulatePath(int x)
{
    switcher();
    if(switchSignal)
    {
        TileCurrentPosX = Xposition(index_counter, x);
        TileCurrentPosY = Yposition(index_counter, x);
        TileDirection = directionality(index_counter, x);
        switch(TileDirection)
        {
        case 0:
                DrawRectangle(TileCurrentPosX + thickness, TileCurrentPosY + thickness, Tilesize,Tilesize  - (thickness), RED);
        break;
        case 1:
                DrawRectangle(TileCurrentPosX + thickness, TileCurrentPosY + thickness, Tilesize - (thickness), Tilesize, RED);
        break;
        case 4:
            SimulationMazeSolved = true;
            SimulateSolveSignal();
        break;
        case 6:
        {
          DrawRectangle(TileCurrentPosX + thickness, TileCurrentPosY + thickness, Tilesize,Tilesize  - (thickness), RED);  
          DrawRectangle(TileCurrentPosX + thickness, TileCurrentPosY + thickness, Tilesize - (thickness), Tilesize, RED);
        }
        default:
            DrawRectangle(TileCurrentPosX + thickness, TileCurrentPosY + thickness, Tilesize - (thickness), Tilesize - (thickness), RED);
        break;

        }
        prevCurrentX = TileCurrentPosX;
    }
    else 
    {   
       if (prevCurrentX == TileCurrentPosX) 
       {
        if(TileDirection == 4){return;}
        prevCurrentX += 1.0f;
        index_counter++;
        }           
    }
}



void Display::simulateAlgorithm(int x)
{
    int evaluate_size;
    int index = 0; 
    int callOnce = 0;
    float delay;
    Color AlgorithmColor;
    (x == 0) ? (AlgorithmColor = RED) : (AlgorithmColor = GREEN);
    (x == 0) ? (evaluate_size = (path.size()) - 1) : (evaluate_size = traversed.size());
    (x == 0) ? (delay = 0.05f) : (delay = 0.01f);
    for(int i = 0; i < evaluate_size;i++)
    {
        float CurrentPosX = Xposition(index, x);
        float CurrentPosY = Yposition(index, x);
        int Direction = directionality(index, x);
        switch(Direction)
        {
        case 0:
                DrawRectangle(TileCurrentPosX + thickness, TileCurrentPosY + thickness, Tilesize,Tilesize  - (thickness), AlgorithmColor);
        break;
        case 1:
                DrawRectangle(TileCurrentPosX + thickness, TileCurrentPosY + thickness, Tilesize - (thickness), Tilesize, AlgorithmColor);
        break;
        case 4:
           
        break;
        default:
            DrawRectangle(TileCurrentPosX + thickness, TileCurrentPosY + thickness, Tilesize - (thickness), Tilesize - (thickness), AlgorithmColor);
        break;
        }
        // DrawRectangle(CurrentPosX + thickness, CurrentPosY + thickness, Tilesize - (thickness), Tilesize - (thickness), AlgorithmColor);
        if(range == evaluate_size)
        {
            SimulateEnd = true;
        }
        else
        {
            
            bool Signal = Modifiedswitcher(delay);
            if(Signal)
            {
            if (callOnce == 0) 
            {
                callOnce = 1;
                range++;
                }  
            }
        }
        index++;
    //pag range is nagequal sa end size, di na magiincrement index, basically nilalagyan mo ng limit si index para di agad masolve/lagay delay
    //pag nagequal na yung range sa size, no increment indext
        
        if(index == range)
        {
            
            break;
        }

        }
    }
//limit mo yung range ng loop, global dapat range
//if range == size; enter = range 0
//after ng delay tska ka mag increment ng range
//if index == range(index = 0)

bool Display::Modifiedswitcher(float ModifiedDelay) 
{
    float currentTime = GetTime();
    if ((currentTime - lastUpdateTime) >= ModifiedDelay) 
    {   
        // if(switchSignal)
        // {
        //     switchSignal = false;
        // }else{switchSignal = true;
        // }

        ModifiedswitchSignal = !ModifiedswitchSignal;
        lastUpdateTime = currentTime;
        return ModifiedswitchSignal = true;
    }
    return ModifiedswitchSignal = false;;
}

void Display::UpdatePlayerPosition()
{
    if (MazeInArrayForm[PlayerCurrentIndex] == end)
    {
        if(IsKeyPressed(KEY_DOWN))
        {
            PlayMazeSolved = true;
        }
    }
    else{
        PlayMazeSolved = false;
    }
    if (PlayMazeSolved)
            {
                DrawText("SOLVED", 20, 20, 20, GREEN);
                ReturnScreen = true;
            }

    //pwede yung funct na if key pressed down, increment fast af, but evaluator dapat mabilis
    //tommorow, ayusin mga constant, figure out timer?, figure out display path line, simulate path line, ayusin yung pag nacall yung solve rebalik index
    int x = 4;
    // timing, pag pumindot, undraw, wait, draw, pausecounter
    if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) {PlayerCurrentIndex--; x = 0;PlayerCounterX--;} 
    if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) {PlayerCurrentIndex++; x = 1;PlayerCounterX++;}
    if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) {PlayerCurrentIndex -= expanded; x = 2;PlayerCounterY--;}
    if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) {PlayerCurrentIndex += expanded; x = 3;PlayerCounterY++;}
    // std::cout << "x : " << PlayerCounterX << " y : " << PlayerCounterY << "\n";
    // std::cout << "index : " << PlayerCurrentIndex <<"\n";
    CheckMazeCollision(x);
                                           
}

void  Display::PlaySolveSignal()
{
    if (PlayMazeSolved)
            {
                DrawText("SOLVED", 20, 20, 20, GREEN);
                DrawText(" -- PRESS SPACE BAR TO PLAY -- ",static_cast<float>(posX) , static_cast<float>(posY + (Tilesize * squared) + (thickness * 2)), 20, GRAY);
                if (IsKeyPressed(KEY_SPACE))
                    {
                        ReturnScreen = true;
                        InitializeCallOnce = 1;
                    }
            }
   
}
//timer function, drawtime gamit update current time
//timersignal = true start timer
void  Display::SimulateSolveSignal()
{
    if (SimulationMazeSolved)
            {
                //NAGplay ng ibang maze, nasira!/naretian yung data nung ibang maze;
                //ayusin mo constant value
                DrawText("ROUTE FOUND!", 20,20,28,GREEN);
                DrawText("SIMULATE <- BACK : ENTER -> MAZE SELECTION",static_cast<float>(posX - 47) , static_cast<float>(posY + (Tilesize * squared) + (thickness * 2)), 19, GRAY);
    
            }
   
}
void Display::CheckMazeCollision(int x)
{
if(PlayerCounterX == -1){PlayerCounterX++; PlayerCurrentIndex++; return;}

//out of bounds
if (PlayerCounterX >= (squared) || PlayerCounterY >= (squared)) 
{
    switch(x)
{
    case 0:
    PlayerCurrentIndex++;
    PlayerCounterX++;
    break;
    case 1:
    PlayerCurrentIndex--;
    PlayerCounterX--;
    break;
    case 2:
    PlayerCurrentIndex+=expanded;
    PlayerCounterY++;
    break;
    case 3:
    PlayerCurrentIndex-=expanded;
    PlayerCounterY--;
    break;
}
    //isang switch na nagrereturn ng index back to normal if valid, pwede mo i func, bool is ganto, then 
    return;
}


if (x == 4){return;}    

//valid edge
if(MazeInArrayForm[PlayerCurrentIndex] == area + 1)
{
switch(x)
{
    case 0:
    PlayerCurrentPosX -= Tilesize;
    PlayerCurrentIndex-=1;
    break;
    case 1:
    PlayerCurrentPosX += Tilesize;
    PlayerCurrentIndex+=1;
    break;
    case 2:
    PlayerCurrentPosY -= Tilesize;
    PlayerCurrentIndex-=expanded;
    break;
    case 3:
    PlayerCurrentPosY += Tilesize;
    PlayerCurrentIndex+=expanded;
    break;

}
}
else
{
switch(x)
{
    case 0:
    PlayerCurrentIndex++;
    PlayerCounterX++;
    break;
    case 1:
    PlayerCurrentIndex--;
    PlayerCounterX--;
    break;
    case 2:
    PlayerCurrentIndex+=expanded;
    PlayerCounterY++;
    break;
    case 3:
    PlayerCurrentIndex-=expanded;
    PlayerCounterY--;
    break;

}
}
    // if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) {PlayerCurrentPosX -= Tilesize;} 
    // if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) {PlayerCurrentPosX += Tilesize;}
    // if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) {PlayerCurrentPosY -= Tilesize;}
    // if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) {PlayerCurrentPosY += Tilesize;}
}

void Display::InitializeStartingPosition()
{
if (InitializeCallOnce == 1)
{
    SimulateEnd = false;
    MazeInArrayForm.clear();
    DetermineMazeArrayForm();
    InitializeCallOnce++;
    PlayerCounterX = start;
    PlayerCounterY = 0;
    PlayerCurrentPosX = posX + ((start % squared) * Tilesize);
    PlayerCurrentPosY = posY;
    PlayerCurrentIndex = start * 2;
}
}

void Display::PlayMaze()
{
    DrawRectangle(PlayerCurrentPosX + thickness, PlayerCurrentPosY + thickness, Tilesize - (thickness), Tilesize - (thickness), RED);
}

    //outside switcher

float Display:: Xposition(int i, int mode)
{
    int tile;
    tile = Tilesize;
    (mode == 0) ? TileCurrentPosX = posX + ((tile * (path[i] % squared))) : TileCurrentPosX = posX + ((tile * (traversed[i] % squared)));
    return TileCurrentPosX;
}

float Display::Yposition(int i,  int mode){
    int tile;
    int y_value;
    tile = Tilesize;
    (mode == 0) ? y_value  = path[i]/squared : y_value  = traversed[i]/squared;
    TileCurrentPosY =posY + ((tile * (y_value)));
    return TileCurrentPosY;
}
//WORK IN PROGRESS PA
int Display::directionality(int i, int mode)
{
    int determinance;
    int SolvedSize;
    PrevTileDirection = CurrentTileDirection;
    (mode == 0) ? determinance = (path[i] - path[i+1]) : determinance = (traversed[i] - traversed[i+1]);
    (mode == 0) ? SolvedSize = (path.size() - 1) : SolvedSize=(traversed.size());
    (mode == 0) ? NextTileDirection = (path[i+1] - path[i+2]) : NextTileDirection = (traversed[i+1] - traversed[i+2]);
    if(i == SolvedSize - 1){return 3;}
    if(i == SolvedSize){return 4;}

    // determinance = std::abs(determinance);
    switch(determinance)
    {
    case -1:
    CurrentTileDirection = 0;
    break;

    case -10:
    CurrentTileDirection = 1;
    break;
    case 1:
    CurrentTileDirection = 5;
    // if(prevCurrentX == 5){return 0;}
    break;
    case 10:
    CurrentTileDirection = 1;
    break;
    }
    if(PrevTileDirection == 0 && CurrentTileDirection == 0){return 0;}
    if(PrevTileDirection == 1 && CurrentTileDirection == 1 ){return 1;}
    //sa simulate path ayusin mo  a buo yung red lines
    //limits ka eh
    // if(PrevTileDirection == 1 && CurrentTileDirection == 0 && NextTileDirection == 1){return 6;}
    // if(PrevTileDirection == 1 && CurrentTileDirection == 5){return 6;}
    // if(CurrentTileDirection == 5 && PrevTileDirection == 5){return 0;}
    // if(PrevTileDirection == 5 && CurrentTileDirection == 1){return 0;}
    

    // NextTileDirection = std::abs(NextTileDirection);
    // switch(NextTileDirection)
    // {
    // case 1:
    // NextTileDirection = 0;
    // break;

    // case 10:
    // NextTileDirection = 1;
    // break;
    // }

    // // if(PrevTileDirection == 0 && CurrentTileDirection == 1 && NextTileDirection == 0){return 0;}

    // if(CurrentTileDirection != PrevTileDirection){return 3;}
    // if(CurrentTileDirection == 0)
    // {
    //     return 0;
    // }
    // if(CurrentTileDirection == 1)
    // {
    //     return 1;
    // }

    return 3;
}

void Display::MazeSimulate(float width, float height) 
{
    int selector = 0; 
    float screenWidth = width;
    float screenHeight = height;  
    InitWindow(width, height, "SIMULATION");
    GameScreen screen = LOGO; 
    GameScreen previousScreen;

    while (!WindowShouldClose())    // Detect window close button or ESC key
        {
            switch(screen) 
            {
                case LOGO: 
                {   
                    framesCounter++;
                    // if (framesCounter > 6000) 
                    // {
                    //     screen = MAZE1;    // Change to TITLE screen after 3 seconds
                    //     framesCounter = 0;
                    // }
                    if (IsKeyPressed(KEY_SPACE)) screen = MAZE1;
                    
                } break;
                case MAZE1: 
                {
                    
                    selector = 1;
                    Initializer(selector,screenWidth,screenHeight);
                    InitializeCallOnce = 1;
                    framesCounter++;
                    previousScreen = screen;
                    if (IsKeyPressed(KEY_RIGHT)) screen = MAZE2;
                    if (IsKeyPressed(KEY_LEFT)) screen = MAZE7;
                    if (IsKeyPressed(KEY_ENTER)) screen = SIMULATE;
                    
                } break;
                case MAZE2:
                { 

                    
                    selector = 2;
                    Initializer(selector,width,height);
                    InitializeCallOnce = 1;
                    framesCounter++;
                    previousScreen = screen;
                    if (IsKeyPressed(KEY_RIGHT)) screen = MAZE3;
                    if (IsKeyPressed(KEY_LEFT)) screen = MAZE1;
                    if (IsKeyPressed(KEY_ENTER)) screen = SIMULATE;

                } break;
                case MAZE3: 
                {
                    selector = 3;
                    Initializer(selector,width,height);
                    InitializeCallOnce = 1;
                    framesCounter++;
                    previousScreen = screen;
                    if (IsKeyPressed(KEY_RIGHT)) screen = MAZE4;
                    if (IsKeyPressed(KEY_LEFT)) screen = MAZE2;
                    if (IsKeyPressed(KEY_ENTER)) screen = SIMULATE;

                } break;
                case MAZE4: 
                {
                    
                    
                    selector = 4;
                    Initializer(selector,width,height);
                    InitializeCallOnce = 1;
                    framesCounter++;
                    previousScreen = screen;
                    if (IsKeyPressed(KEY_RIGHT)) screen = MAZE5;
                    if (IsKeyPressed(KEY_LEFT)) screen = MAZE3;
                    if (IsKeyPressed(KEY_ENTER)) screen = SIMULATE;
                

                } break;
                case MAZE5: 
                {
                    
                    selector = 5;
                    Initializer(selector,width,height);
                    InitializeCallOnce = 1;


                    framesCounter++;
                    previousScreen = screen;
                    if (IsKeyPressed(KEY_RIGHT)) screen = MAZE6;
                    if (IsKeyPressed(KEY_LEFT)) screen = MAZE4;
                    if (IsKeyPressed(KEY_ENTER)) screen = SIMULATE;

                } break;
                case MAZE6: 
                {
                    
                    selector = 6;
                    Initializer(selector,width,height);
                    InitializeCallOnce = 1;


                    framesCounter++;
                    previousScreen = screen;
                    if (IsKeyPressed(KEY_RIGHT)) screen = MAZE7;
                    if (IsKeyPressed(KEY_LEFT)) screen = MAZE5;
                    if (IsKeyPressed(KEY_ENTER)) screen = SIMULATE;

                } break;
                case MAZE7: 
                {
                    
                    selector = 7;
                    Initializer(selector,width,height);
                    InitializeCallOnce = 1;


                    framesCounter++;
                    previousScreen = screen;
                    if (IsKeyPressed(KEY_RIGHT)) screen = MAZE1;
                    if (IsKeyPressed(KEY_LEFT)) screen = MAZE6;
                    if (IsKeyPressed(KEY_ENTER)) screen = SIMULATE;

                } break;
                case SIMULATE: 
                {
                    framesCounter++;
                    InitializeStartingPosition();
                    UpdatePlayerPosition();
                    PlaySolveSignal();
                    if (ReturnScreen)
                    {
                        screen = SIMULATE;
                        ReturnScreen = false;
                    
                    };//magkakabug to, need mo ng counter reseter
                    if (IsKeyPressed(KEY_ENTER)) screen = LOGO;
                    if (IsKeyPressed(KEY_BACKSPACE)) screen = previousScreen;
                    if (IsKeyPressed(KEY_X)) screen = DFS;
                    if (IsKeyPressed(KEY_Z)) screen = BFS;
                    if (IsKeyPressed(KEY_C)) screen = BOTH;
                    if (IsKeyPressed(KEY_V)) screen = SOLVE;
                    

                } break;
                case DFS: 
                //solver to;
                {
                    
                    if(IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_BACKSPACE))
                    {range = 0; SimulateEnd = false;}
                    framesCounter++;
                    if (IsKeyPressed(KEY_ENTER)) screen = previousScreen;
                    if (IsKeyPressed(KEY_BACKSPACE)) screen = SIMULATE;
                    
                } break;
                case BFS: 
                {
                    if(IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_BACKSPACE))
                    {range = 0; SimulateEnd = false;}
                    framesCounter++;
                    if (IsKeyPressed(KEY_ENTER)) screen = previousScreen;
                    if (IsKeyPressed(KEY_BACKSPACE)) screen = SIMULATE;
                    //dagdag ka ng para sa solve at both
                    //
                    
                } break;
                case BOTH: 
                //solver to;
                {
                    
                    
                    framesCounter++;
                    if(IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE))
                    {range = 0; SimulateEnd = false;}
                    if (IsKeyPressed(KEY_ENTER)) screen = previousScreen;
                    if (IsKeyPressed(KEY_BACKSPACE)) screen = SIMULATE;
                    
                } break;
                case SOLVE: 
                //solver to;
                {
                    
                    //SPACE RE-SIMULATE, BACKSPACE - SIMULATE MENU; ENTER - MAZE SELECTION
                    framesCounter++;
                    if (IsKeyPressed(KEY_ENTER)) screen = previousScreen;
                    if (IsKeyPressed(KEY_BACKSPACE)) screen = SIMULATE;
                    if (IsKeyPressed(KEY_BACKSPACE) || IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE))
                    {
                        index_counter = 0;
                        SimulationMazeSolved = false;
                    }
                    
                } break;
                default: break;
            }
            //----------------------------------------------------------------------------------
            
            // Draw
            //----------------------------------------------------------------------------------
            BeginDrawing();
            
                ClearBackground(RAYWHITE);
                
                switch(screen) 
                {
                    case LOGO:
                    {
                        
                        DrawLogo();
        
                    } break;
                    case MAZE1:
                    {
                        DrawText("MAZE 1", 20, 20, 30, RED);
                        drawborder();
                        simulateEdge(screenWidth,screenHeight);


                    } break;
                    case MAZE2:
                    {
                        DrawText("MAZE 2", 20, 20, 30, RED);
                        drawborder();
                        simulateEdge(screenWidth,screenHeight);

                    } break;
                    case MAZE3:
                    {
                    DrawText("MAZE 3", 20, 20, 30, RED);
                        drawborder();
                        simulateEdge(screenWidth,screenHeight);

                    } break;
                    case MAZE4:
                    {
                        DrawText("MAZE 4", 20, 20, 30, RED);
                        drawborder();
                        simulateEdge(screenWidth,screenHeight);

                    } break;
                    case MAZE5:
                    {
                        DrawText("MAZE 5", 20, 20, 30, RED);
                        drawborder();
                        simulateEdge(screenWidth,screenHeight);

                    } break;
                    case MAZE6:
                    {
                        DrawText("MAZE 6", 20, 20, 30, RED);
                        drawborder();
                        simulateEdge(screenWidth,screenHeight);

                    } break;
                    case MAZE7:
                    {
                        DrawText("MAZE 7", 20, 20, 30, RED);
                        drawborder();
                        simulateEdge(screenWidth,screenHeight);

                    } break;
                    case SIMULATE:
                    {
                        
                        //sa logo mo ilagay yung -PRESS SPACE/ENTER TO PLAY-
                        simulateEdge(screenWidth,screenHeight);
                        drawborder();
                        DrawRectangle(PlayerCurrentPosX + thickness, PlayerCurrentPosY + thickness, Tilesize - (thickness), Tilesize - (thickness), RED);
                        if(!PlayMazeSolved){DrawText("Z: BFS X: DFS C: BOTH V: SOLVE",static_cast<float>(posX + thickness) , static_cast<float>(posY + (Tilesize * squared) + (thickness * 2)), 20, GRAY);}

                    } break;
                    case BFS:
                    {
                    drawborder();
                    simulateEdge(screenWidth,screenHeight);
                    simulateAlgorithm(1);
                    if(SimulateEnd)
                    {
                        //ayusin ko exit ng simulation end
                        DrawText(" -- SIMULATION FINISHED -- ",static_cast<float>(posX + 30) , static_cast<float>(posY + (Tilesize * squared) + (thickness * 2)), 20, GRAY);
                    }

                    } break;
                    case DFS:
                    {
                    drawborder();
                    simulateEdge(screenWidth,screenHeight);
                    simulateAlgorithm(0);
                    if(SimulateEnd)
                    {
                        //ayusin ko exit ng simulation end
                        DrawText(" -- SIMULATION FINISHED -- ",static_cast<float>(posX + 30) , static_cast<float>(posY + (Tilesize * squared) + (thickness * 2)), 20, GRAY);
                    }

                    } break;
                    case BOTH:
                    {
                    drawborder();
                    simulateEdge(screenWidth,screenHeight);
                    simulateAlgorithm(1);
                    simulateAlgorithm(0);
                    if(SimulateEnd)
                    {
                        DrawText(" -- SIMULATION FINISHED -- ",static_cast<float>(posX) , static_cast<float>(posY + (Tilesize * squared) + (thickness * 2)), 20, GRAY);
                    }

                    } break;
                    case SOLVE:
                    {
                    drawborder();
                    simulateEdge(screenWidth,screenHeight);
                    simulatePath(0);
            
                    } break;
                    default: break;
                }
            
            EndDrawing();
                        // Close window and OpenGL context
//pag tile = 2, pag valid edge 1, pag hindi 0;
        
        }
        CloseWindow();
        return; 
}


// Function to draw the logo
void Display::DrawLogo() {
    float yOffset = -30;
    float xOffset = 0;

    // Define the points that make up the logo lines
    Vector2 lines[] = {
        {390 + xOffset, 50 + yOffset}, {200 + xOffset, 400 + yOffset},
        {390 + xOffset, 50 + yOffset}, {600 + xOffset, 400 + yOffset},
        {383 + xOffset, 162 + yOffset}, {415 + xOffset, 225 + yOffset},
        {285 + xOffset, 412 + yOffset}, {360 + xOffset, 280 + yOffset},
    };

    int numLines = sizeof(lines) / sizeof(lines[0]) / 2;
    float thickness = 30.0f; // Line thickness
    Color lineColor = BLACK; // Line color equivalent to #1d1e1f

    // Draw each line segment
    for (int i = 0; i < numLines; i++) {
        DrawLineEx(lines[i * 2], lines[i * 2 + 1], thickness, lineColor);
    }

    DrawRectangle(375 + xOffset, 40 + yOffset, 30, 20, lineColor);

    DrawRectangle(325 + xOffset, 155 + yOffset, 70, 30, lineColor);

    DrawRectangle(187.95 + xOffset, 390 + yOffset, 110, 30, lineColor);
    DrawRectangle(512.5 + xOffset, 390 + yOffset, 100, 30, lineColor);

    DrawRectangle(320 + xOffset, 320 + yOffset, 150, 30, lineColor);

    DrawRectangle(380 + xOffset, 240 + yOffset, 130, 30, lineColor);

    DrawRectangle(305 + xOffset, 125 + yOffset, 30, 30, RAYWHITE);
    DrawRectangle(335 + xOffset, 265 + yOffset, 43, 30, RAYWHITE);

    DrawRectangle(390 + xOffset, 210 + yOffset, 43, 30, RAYWHITE);
    DrawRectangle(330 + xOffset, 125 + yOffset, 60, 30, RAYWHITE);

    DrawBoldText();
}



void Display::DrawBoldText() {
    const char* text = "AMAZE";
    int posX = 335;
    int posY = 350;
    int fontSize = 45;
    Color color = {227, 0, 0,255};
    Color color2 = GRAY;

    // Simulate bold by drawing the text multiple times with slight offsets
    int thickness = 1; // Number of times to draw the text to simulate bold effect
    for (int offsetX = -thickness; offsetX <= thickness; offsetX++) {
        for (int offsetY = -thickness; offsetY <= thickness; offsetY++) {
            DrawText(text, posX + offsetX, posY + offsetY, fontSize, color);
        }
    }

    // Calculate alpha value for the fade-in and fade-out effect
    float time = GetTime();
    float alpha = (sinf(time * 2.0f) + 1.0f) / 2.0f; // Alpha value oscillates between 0 and 1
    Color fadeColor = { color2.r, color2.g, color2.b, (unsigned char)(alpha * 255) };

    // Draw the fading text
    DrawText("-- PRESS SPACE TO CONTINUE --", 220, 410, 20, fadeColor);
}