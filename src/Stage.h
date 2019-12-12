#ifndef TREASUREHUNT_H_
#define TREASUREHUNT_H_

#include <vector>
#include <iostream>
#include <cstdlib>
#include "linuxfunc.h"

using namespace std;

#endif

#include "Map.h"
#include "Obstruct.h"

#define TOTAL_STAGE_NUM		3


struct __ObstructData{ // Obstruct data set for reading from datafile
   
   int xpos;
   int ypos;
   int patternNum;

};
typedef struct __ObstructData ObstructData;


struct __PatternData{  // pattern data set for reading from datafile
   
   double period;
   double vel;

   int dir;
   int totalMoves;

};
typedef struct __PatternData PatternData;


class Stage{


 public:
 
   int numOfObstructs; // number of obstructs in this Stage

   int characterPos[TOTAL_STAGE_NUM+1][2]; // start position for character in each stage

   Stage(){numOfObstructs=0;}

   void setGameMap(char * buf){
	gameMap.setMap(buf);
   }

   void setObstruct(int x,int y,int patternNum){
      Obstruct obstruct(x,y,patternNum);
      Obstructs.push_back(obstruct);
      numOfObstructs++; 
   }

   void obstructAddMotion(double period,double vel,int dir,int tMoves){	
      Obstructs[numOfObstructs-1].addMotion(period,vel,dir,tMoves);
   }

   void setCharacterPos(int curStage,int x,int y){
      characterPos[curStage][0] = x;
      characterPos[curStage][1] = y;
   }

   void drawMap(){
       gameMap.printMap();
   }

   void drawObstructs(){
       for(int i=0;i<Obstructs.size();i++)
	    Obstructs[i].draw();
   }

   void moveObstructs(const Character& hero,const Map& gameMap){
	for(int i=0;i<Obstructs.size();i++)
	   Obstructs[i].move(hero,gameMap);
   }

   void addObstruct(const Obstruct& obs){
      Obstructs.push_back(obs);
      numOfObstructs++;
   }

   int getCurObstructXpos(int cur){
	return Obstructs[cur].getXpos();
   }

   int getCurObstructYpos(int cur){
	return Obstructs[cur].getYpos();
   }

   void setTreasure(int x,int y){
	treasureXpos = x;
	treasureYpos = y;
   }

   void setTreasureXpos(int x){
	treasureXpos = x;
   }

   int getTreasureXpos(){
       return treasureXpos;
   }

   void setTreasureYpos(int y){
	treasureYpos = y;
   }

   int getTreasureYpos(){
       return treasureYpos;
   }

   Map& getGameMap(){
       return gameMap;
   }

   char getMapCurPosition(int r,int c){
      return gameMap.getCurPosition(r,c);
   }

 private:
   Map gameMap;
 
   vector<Obstruct> Obstructs;

   int treasureXpos; 
   int treasureYpos; 

};
