#ifndef TREASUREHUNT_H_
#define TREASUREHUNT_H_

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include "linuxfunc.h"
#include "PatternSet.h"
#include "Character.h"
#include "Map.h"

using namespace std;

#endif

#define SHORTEST	11
#define INF		11111111

class Obstruct{

 private:
   PatternSet motions;

 public:

   Obstruct() {}

   Obstruct(int x,int y,int patternNum){
      motions.setPatternNum(patternNum);

      this->patternNum = patternNum;
      xpos = x; preXpos = xpos;
      ypos = y; preYpos = ypos;
      curPattern=0;
      patternStarted = false;
     
      body = (patternNum != 1 ? '@' : '%');
   }

   void setObstruct(int x,int y,int patternNum){

       motions.setPatternNum(patternNum);

       this->patternNum = patternNum;
       xpos = x; preXpos = xpos;
       ypos = y; preYpos = ypos;
       curPattern = 0;
       patternStarted = false;
       body = (patternNum != 1 ? '@' : '%');
   }

   int getXpos(){
      return xpos;
   }

   int getYpos(){
      return ypos;
   }

   void addMotion(double period,double vel,int dir,int tMoves){
     tempPattern.setPattern(period,vel,dir,0,tMoves); 
     motions.addMotion(tempPattern);
   }

   void move(const Character& hero, const Map& gameMap);
   
   void draw();

 private:
    
    int xpos;
    int ypos;

    int preXpos; // pos for SHORTEST move
    int preYpos; // pos for SHORTEST move

    int curPattern; // idx for current Pattern

    int patternNum; // total number of patterns

    static int direction[4][2];

    Pattern tempPattern; // pattern for Obstruct.addMotion() 
    Pattern movePattern; // pattern for Obstruct.move()

    bool patternStarted;

    char body;
};


