#include <stdio.h>
#include "MacUILib.h"



// PREPROCESSOR CONSTANTS DEFINITION ========================================================================================================
//const int size doesnt work, must be #define size, otherwise variably modified array
#define sizeX 20
#define sizeY 10
const int speeds[5] = {200000, 175000, 150000, 125000, 100000}; // in seconds: 0.2, 0.175, 0.15, 0.125, 0.1
//my ideal speed in PPA1 was 0.15, so it is the middle speed level. 0.2 is not too slow and 0.1 is not too fast, and each speed levels have a noticable difference.




// GLOBAL VARIABLE DEFINITION ========================================================================================================
int exitFlag; // Program Exiting Flag - old stuff
char cmd;   // For storing the user input - from PPA1
int speed;
char board[sizeY][sizeX];
char playerChar;

enum FSMMode {UP, DOWN, LEFT, RIGHT, STALE}; // finite state machine
enum FSMMode currMode; // current mode

struct ObjPos {
    int xPos;
    int yPos;
};
struct ObjPos player;



// FUNCTION PROTOTYPING DEFINITION ========================================================================================================
void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);
// additional prototypes
void PlayerMove(void);



// MAIN PROGRAM LOOP ========================================================================================================
int main(void) {
    Initialize();
    while(!exitFlag) {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }
    CleanUp();
}



// INITIALIZATION ROUTINE ========================================================================================================
void Initialize(void) {
    MacUILib_init();
    MacUILib_clearScreen();

    cmd = 0;            // NULL
    exitFlag = 0;       // not exiting  
    speed = 0;          // default speed level for screen delay
    currMode = STALE;   // player will not move in any direction until a cmd is received
    playerChar = '+';
    
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
    board[player.yPos][player.xPos] = playerChar; //player goes to center of board. if a 'size' is even, then player will be positioned at 'higher coordinate' rather than the direct center at #.5 coordinate


}



// INPUT PROCESSING ROUTINE ========================================================================================================
void GetInput(void) {
    if (MacUILib_hasChar()){
        cmd = MacUILib_getChar();
    }
}



// PROGRAM LOGIC ROUTINE ========================================================================================================
void RunLogic(void) {

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
    
}



// SCREEN DRAWING ROUTINE ========================================================================================================
void DrawScreen(void) {

    MacUILib_clearScreen(); //clears screen each time something printed so it only shows once at a time

    // Basic Game Stats
    MacUILib_printf("Press 'Q' to decrease speed and 'E' to increase speed.\nCurrent Speed Level: %d\n\nPress 'esc' to exit.\n\n\n", (speed+1));
    //MacUILib_printf("Player Coords: %d , %d\n\n", player.xPos, player.yPos);
    
   
   //GAME BOARD
    int i, j;
    for (i=0; i<sizeY; i++){
        for (j=0; j<sizeX; j++){ //border
            MacUILib_printf("%c", board[i][j]);
        }
        MacUILib_printf("\n");
    }

}



// PROGRAM LOOOP DELAYER ROUTINE ========================================================================================================
void LoopDelay(void) {
    // Change the delaying constant to vary the movement speed.
    MacUILib_Delay(speeds[speed]);    
}



// PROGRAM CLEANUP ROUTINE ========================================================================================================
// Recall from PPA1 - this is run only once at the end of the program
// for garbage collection and exit messages.
void CleanUp(void) {
    MacUILib_uninit();
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


    board[player.yPos][player.xPos] = playerChar; //update the board with the players current position

}