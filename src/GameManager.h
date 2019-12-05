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

#define TOTAL_STAGE_NUM		2

#define BUF_SIZE_FOR_MAP	MAXROW * MAXCOL + 1

#define MAXLEN		10 // for readIntData()

#define SCREEN_HEIGHT		50
#define SCREEN_WIDTH		180

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

     Map gameMap;

     Stage stage[TOTAL_STAGE_NUM+1]; //index start from 1

     GameManager(){
        curStageNum=1;
	gameMap.setRow(0);
     }

     void init();

     int readIntData(int fp);

     void readDataFromFile(); // read all datas about all stages from file

     void gameMenu();

     void gameGuide();

     void playGame(Character& hero);

     bool checkCharacterObstructCrush(const Character& hero);

     bool checkGameClear(const Character& hero);

     void gameEnd();

  private:
      
     bool gameClearFlag;
     bool gameEndFlag;

     int curStageNum; // index for accessing Stage array
};

