#ifndef TREASUREHUNT_H_
#define TREASUREHUNT_H_

#include <vector>
#include <iostream>
#include <cstdlib>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include "linuxfunc.h"
#include "Character.h"
#include "PatternSet.h"
#include "Stage.h"

using namespace std;

#endif

#define BUF_SIZE_FOR_MAP	MAXROW * MAXCOL + 1

#define MAXLEN		10 // for readIntData()

#define SCREEN_HEIGHT		50
#define SCREEN_WIDTH		180

#define CURSOR_XPOS		68	

#define CURSOR_MOVE		3

#define GAME_START_CURSOR	32	
#define GAME_END_CURSOR		35

#define GAME_END_STATE		11
#define GAME_PLAYING_STATE	22
#define GAME_MENU_STATE		33
#define STAGE_CLEAR_STATE	44

class Character;

class GameManager{

 // GameManager should control all situations
 // Character,Obstructs,Map are just doing their duties,behaviors which we set
 // Only GameManager can control all situations
 // ex1) make Character move only in map
 // ex2) check Character get treasure, if that do other funcs
 // ex3) check Character crushed to obstructs, if that call gameEnd
 

 // number of obstructs and patterns of move should be different in each stage
 
 // need a function to deal with setting stage(map,obstruct)
 
 // which way would be better? set all map and obstructs for every stage in advance or set before stage coming up?

 // seems setting in advance would be better...

 // make Stage class that stores maps and obstructs for corresponding stage
 
 // make Stage class array in GameManager 

  public: 

     Stage stage[TOTAL_STAGE_NUM+1]; //index start from 1

     Character hero; // game Main Character

     GameManager(){
        curStageNum=1;
	hero.setBody();
     }

     void init();

     int readIntData(int fp);

     void readDataFromFile(); // read all datas about all stages from file

     void gameMenu();

     void gameGuide();

     void playGame();

     void setCharacterPos(){
	hero.setXpos(stage[curStageNum].characterPos[curStageNum][0]);
	hero.setYpos(stage[curStageNum].characterPos[curStageNum][1]);
     }

     bool checkCharacterObstructCrush();

     bool checkGameClear();

     void setGameState(int state){
	gameState = state;
     }

     int getGameState(){
        return gameState;
     }

     void gameEnd();

  private:
      
     int gameState;

     int curStageNum; // index for accessing Stage array
};

