#include <stdio.h>
#include "MacUILib.h"
#include "myStringLib.h"   // This is your first custom C library
#include <stdlib.h>
#include <time.h>



// PREPROCESSOR DIRECTIVE CONSTANTS
// ================================
#define sizeX 20
#define sizeY 10
#define strSize 13
#define itemAmt 8 //the number of items
const int speeds[5] = {200000, 175000, 150000, 125000, 100000}; // in seconds: 0.2, 0.175, 0.15, 0.125, 0.1
//my ideal speed in PPA1 was 0.15, so it is the middle speed level. 0.2 is not too slow and 0.1 is not too fast, and each speed levels have a noticable difference.

const char goalStr[] = "McMaster-ECE";









// GLOBAL VARIABLES
// ================================
int exitFlag; // Program Exiting Flag - old stuff
char cmd;   // For storing the user input - from PPA1
int speed;
char board[sizeY][sizeX];

enum FSMMode {UP, DOWN, LEFT, RIGHT, STALE}; // finite state machine
enum FSMMode currMode; // current mode

struct ObjPos {
    int xPos;
    int yPos;
    char icon;
};
struct ObjPos player;
struct ObjPos item1;
struct ObjPos item2;
struct ObjPos item3;
struct ObjPos item4;
struct ObjPos item5;
struct ObjPos item6;
struct ObjPos item7;
struct ObjPos item8;



char mystStr [strSize] = "????????????";
char* mystPtr = NULL;

struct ObjPos bin [itemAmt];
struct ObjPos* binPtr = NULL;

int moveCount;

char bagMust[strSize] = "McMaster-ECE";
    char bagOther[] = {"ABDFGHIJKLNOPQRSTUVWXYZbdfghijklmnopquvwxyz"};
    int bagTaken [strSize+sizeof(bagOther)] = {0};







// FUNCTION PROTOTYPES
// ================================
// Declare function prototypes here, so that we can organize the function implementation after the main function for code readability.

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);
// additional prototypes
void PlayerMove(void);
void allocate(void);
void deallocate(void);
void GenItems(void);
void ResetItems (void);
void ItemCollision (void);




// [TODO] In PPA3, you will need to implement this function to generate random items on the game board
//        to set the stage for the Scavenger Hunter game.
// list[]       The pointer to the Item Bin
// listSize     The size of the Item Bin (5 by default)
// playerPos    The pointer to the Player Object, read only.
// xRange       The maximum range for x-coordinate generation (probably the x-dimension of the gameboard?)
// yRange       The maximum range for y-coordinate generation (probably the y-dimension of the gameboard?)
// str          The pointer to the start of the Goal String (to choose the random characters from)
//void GenerateItem(struct objPos list[], const int listSize, const struct objPos *playerPos, const int xRange, const int yRange, const char* str);



// MAIN PROGRAM
// ===============================
int main(void){
    Initialize();
    while(!exitFlag) {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }
    CleanUp();
}




// INITIALIZATION ROUTINE
// ===============================
void Initialize(void){
    MacUILib_init();
    MacUILib_clearScreen();

    // [COPY AND PASTE FROM PPA2] Copy your initialization routine from PPA2 and paste them below
    cmd = 0;            // NULL
    exitFlag = 0;       // not exiting  
    speed = 0;          // default speed level for screen delay
    currMode = STALE;   // player will not move in any direction until a cmd is received


    moveCount = 0;
    allocate();
    mystPtr = mystStr;
    binPtr = bin;
    binPtr[0] = item1;
    binPtr[1] = item2;
    binPtr[2] = item3;
    binPtr[3] = item4;
    binPtr[4] = item5;
    binPtr[5] = item6;
    binPtr[6] = item7;
    binPtr[7] = item8;
    



    
    //SETUP GAME BOARD
    int i, j;
    for (i=0; i<sizeY; i++){
        for (j=0; j<sizeX; j++){ //border
            if ( i==0 || i==sizeY-1){ 
                board[i][j] = '-';
            }
            else if (j==0 || j==sizeX-1){
                board[i][j] = '|';
            }
            else { //everything else
                board[i][j] = ' ';
            }
        }
    }
    //player
    player.xPos = sizeX/2;
    player.yPos = sizeY/2;
    player.icon = '+';
    board[player.yPos][player.xPos] = player.icon; //player goes to center of board. if a 'size' is even, then player will be positioned at 'higher coordinate' rather than the direct center at #.5 coordinate


    GenItems();
    
    // [TODO] Allocated heap memory for on-demand variables as required.  Initialize them as required.
    // [TODO] Seed the random integer generation function with current time.
    // [TODO] Generate the initial random items on the game board at the start of the game.

    
}




// INPUT COLLECTION ROUTINE
// ===============================
void GetInput(void){
    if (MacUILib_hasChar()){
        cmd = MacUILib_getChar();
    }
}




// MAIN LOGIC ROUTINE
// ===============================
void RunLogic(void){
    // [COPY AND PASTE FROM PPA2] Copy your main logic routine from PPA2 and paste them below
    if(cmd != 0) {
        switch(cmd) {                      
            case 27:  // exit
                exitFlag = 1;
                break;
            case 'e': //increade speed
            case 'E':
                (speed == 4)? speed = 4 : speed++;
                break; 
            case 'q': //decrease speed
            case 'Q':
                (speed == 0)? speed = 0 : speed--;
                break;
            

            // DIRECTIONS STUFF
            case 'w':
            case 'W':
                if (currMode != DOWN){
                    currMode = UP;
                }
                break;
            case 'a':
            case 'A':
            if (currMode != RIGHT){
                    currMode = LEFT;
                }
                break;
            case 's':
            case 'S':
            if (currMode != UP){
                    currMode = DOWN;
                }
                break;
            case 'd':
            case 'D':
            if (currMode != LEFT){
                    currMode = RIGHT;
                }
                break;
            default:
                break;
        }
        cmd = 0;
    }
    PlayerMove();

    


    // [TODO]   Implement the Object Collision logic here
    //
    //      Simple Collision Algorithm
    //      1. Go through all items on board and check their (x,y) against the player object x and y.
    //      2. If a match is found, use the ASCII symbol of the collided character, and 
    //         find all the occurrences of this ASCII symbol in the Goal String
    //      3. For every occurrence, reveal its ASCII character at the corresponding location in the
    //         Collected String
    //      4. Then, determine whether the game winning condition is met.

    // [TODO]   Implement Game Winning Check logic here
    //
    //      Game Winning Check Algorithm
    //      1. Check if the contents of the Collected String exactly matches that of the Goal String.
    //         YOU MUST USE YOUR OWN my_strcmp() function from Lab 3.
    //      2. If matched, end the game.
    //      3. Otherwise, discard the current items on the game board, and 
    //         generate a new set of random items on the board.  Game continues.
    
}



// DRAW ROUTINE
// ===============================
void DrawScreen(void){
       
    // [COPY AND PASTE FROM PPA2] Copy your draw logic routine from PPA2 and paste them below
    
    MacUILib_clearScreen(); //clears screen each time something printed so it only shows once at a time

    
   //GAME BOARD
    int i, j;
    for (i=0; i<sizeY; i++){
        for (j=0; j<sizeX; j++){ //border
            MacUILib_printf("%c", board[i][j]);
        }
        MacUILib_printf("\n");
    }


    // Basic Game Stats
    MacUILib_printf("Press 'Q' to decrease speed and 'E' to increase speed.\nCurrent Speed Level: %d\n\nPress 'esc' to exit.\n\n\n", (speed+1));

    MacUILib_printf("Goal String: %s\n", goalStr); //REMOVE THIS BEFORE SUBMITTING PLEASEEEE
    MacUILib_printf("Mystery String: %s\n", mystPtr); 
    MacUILib_printf("Move Count: %d\n\n", moveCount);


    //COORDINATES
    MacUILib_printf("Player Coordinates: (%d, %d)\n", player.xPos, player.yPos);
    MacUILib_printf("Item 1 Coordinates: (%d, %d)\n", (binPtr[0]).xPos, (binPtr[0]).yPos);
    MacUILib_printf("Item 2 Coordinates: (%d, %d)\n", (binPtr[1]).xPos, (binPtr[1]).yPos);
    MacUILib_printf("Item 3 Coordinates: (%d, %d)\n", (binPtr[2]).xPos, (binPtr[2]).yPos);
    MacUILib_printf("Item 4 Coordinates: (%d, %d)\n", (binPtr[3]).xPos, (binPtr[3]).yPos);
    MacUILib_printf("Item 5 Coordinates: (%d, %d)\n", (binPtr[4]).xPos, (binPtr[4]).yPos);
    MacUILib_printf("Item 6 Coordinates: (%d, %d)\n", (binPtr[5]).xPos, (binPtr[5]).yPos);
    MacUILib_printf("Item 7 Coordinates: (%d, %d)\n", (binPtr[6]).xPos, (binPtr[6]).yPos);
    MacUILib_printf("Item 8 Coordinates: (%d, %d)\n", (binPtr[7]).xPos, (binPtr[7]).yPos);
        
}



// DELAY ROUTINE
// ===============================
void LoopDelay(void){
    // Change the delaying constant to vary the movement speed.
    MacUILib_Delay(speeds[speed]);    
}


// TEAR-DOWN ROUTINE
// ===============================
void CleanUp(void){
    deallocate();
    MacUILib_uninit();
}


//HEAP STUFF
void allocate(void){
    //MYSTERY STRING
    char* mystPtr;
    mystPtr = (char*)malloc(sizeof(mystStr));

    //ITEM BIN
    struct ObjPos* binPtr;
    binPtr = (struct ObjPos*)malloc(itemAmt*sizeof(struct ObjPos));
}
void deallocate(void){
    free(mystPtr);
    free(binPtr);
}


//MOVE
void PlayerMove(void){

    board[player.yPos][player.xPos] = ' '; //previous player position is replaced by ' '

    //UP
    //moves up = decrease yPos = touching boudary at yPos = 1. *at 0 is boundary
    if (currMode == UP){
        if (player.yPos == 1){
            player.yPos = sizeY-2;
        }
        else {player.yPos--;}
    }

    //DOWN
    //moves down = increase yPos = touching boudary at yPos = sizeY-2. *at size-1 is boundary, so size-2 is touching it
    else if (currMode == DOWN){ 
        if (player.yPos == sizeY-2){
            player.yPos = 1;
        }
        else {player.yPos++;}
    }

    //LEFT
    //moves left = decrease xPos = touching boudary at xPos = 1. *at 0 is boundary
    else if (currMode == LEFT){ 
    if (player.xPos == 1){
            player.xPos = sizeX-2;
        }
        else {player.xPos--;}
    }

    //RIGHT
    //moves right = increase xPos = touching boudary at xPos = sizeX-2. *at size-1 is boundary, so size-2 is touching it
    else if (currMode == RIGHT){
    if (player.xPos == sizeX-2){
            player.xPos = 1;
        }
        else {player.xPos++;}
    }

    if (currMode != STALE){
        moveCount++;
    }

    board[player.yPos][player.xPos] = player.icon; //update the board with the players current position

}



void GenItems (void){
    //ASSIGN SPOTS
    int itemsSpawned = 0;
    while (itemsSpawned < itemAmt){
        int xrand = rand()%18+1;
        int yrand = rand()%18+1; 
         if (board[xrand][yrand] == ' '){
            binPtr[itemsSpawned].xPos = xrand;
            binPtr[itemsSpawned].yPos = yrand;
            itemsSpawned++;
         }
    }
    itemsSpawned = 0;


    //ASSIGN CHARS

    int charsSpawned = 0;
    while (charsSpawned < 2){
        int charIndex = rand()%(strSize-1);
        char symbol = bagMust[charIndex];
        if (bagTaken[charIndex] == 0){
            binPtr[itemsSpawned].icon = symbol;
            bagTaken[charIndex] = 1;
            charsSpawned++;
        }
    }
    while (charsSpawned < itemAmt){
        int charIndex = rand()%(43);
        char symbol = bagOther[charIndex];
        if (bagTaken[charIndex+strSize-1] == 0){
            binPtr[itemsSpawned].icon = symbol;
            bagTaken[charIndex+strSize-1] = 1;
            charsSpawned++;
        }
    }
    charsSpawned = 0;


    //PUT ITEMS ON BOARD
    int i = 0;
    for (i=0; i < itemAmt; i++){
        int x = binPtr[i].xPos;
        int y = binPtr[i].yPos;
        board[y][x] = binPtr[i].icon;   
    }
}


void ResetItems (void){
    int i = 0;
    for (i=0; i < itemAmt; i++){
        int x = binPtr[i].xPos;
        int y = binPtr[i].yPos;
        board[y][x] = ' ';   
    }

    for (i=0;i<strSize+44;i++){
        bagTaken[i] = 0;
    }



}

void ItemCollision (void){

    int i=0;
    for (i =0; i<2; i++){

        if (player.xPos == (binPtr[i]).xPos && player.yPos == (binPtr[i]).yPos){
            switch (binPtr[i].icon){
                case 'M':
                    mystPtr[0] = binPtr[i].icon;
                    mystPtr[2] = binPtr[i].icon;
                    break;
                case 'c':
                    mystPtr[1] = binPtr[i].icon;
                    break;
                case 'a':
                    mystPtr[3] = binPtr[i].icon;
                    break;
                case 's':
                    mystPtr[4] = binPtr[i].icon;
                    break;
                case 't':
                    mystPtr[5] = binPtr[i].icon;
                    break;
                case 'r':
                    mystPtr[6] = binPtr[i].icon;
                    break;
                case '-':
                    mystPtr[7] = binPtr[i].icon;
                    break;
                case 'E':
                    mystPtr[10] = binPtr[i].icon;
                    break;
                default: //case C
                    mystPtr[9] = binPtr[i].icon;
                    mystPtr[11] = binPtr[i].icon;
                    break;
            }

        }

    }

}