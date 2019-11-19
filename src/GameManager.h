#ifndef TREASUREHUNT_H_
#define TREASUREHUNT_H_

#include <vector>
#include <iostream>
#include <cstdlib>
#include <fcntl.h>
#include "linuxfunc.h"
#include "Character.h"
#include "PatternSet.h"
#include "Stage.h"

using namespace std;

#endif

#define TOTAL_STAGE_NUM		3

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

     Obstruct testObs;
     Obstruct testObs2;

     Map gameMap;

     Stage stage[TOTAL_STAGE_NUM];

     GameManager(){}

     GameManager(int x,int y,int patternNum):testObs(x,y,patternNum),
     testObs2(x+10,y-10,patternNum){}

     void init();

     void readDataFromFile(); // read all datas about all stages from file

     void gameMenu();

     void playGame(Character& hero);

     void gameEnd();

  private:
      
     bool gameClearFlag;
     bool gameEndFlag;

};

