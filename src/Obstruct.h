#ifndef TREASUREHUNT_H_
#define TREASUREHUNT_H_

#include <iostream>
#include <cstdlib>
#include <vector>
#include "linuxfunc.h"
#include "PatternSet.h"

using namespace std;

#endif

class Obstruct{

 private:
   PatternSet motions;

 public:

   Obstruct() {}

   Obstruct(int x,int y,int patternNum){
      motions.setPatternNum(patternNum);

      this->patternNum = patternNum;
      xpos = x; ypos = y;
      curPattern=0;
      patternStarted = false;
      body = '@';
   }

   void setObstruct(int x,int y,int patternNum){

       motions.setPatternNum(patternNum);

       this->patternNum = patternNum;
       xpos = x; ypos = y;
       curPattern = 0;
       patternStarted = false;
       body = '@';
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

   void move();
   
   void draw();

 private:
    
    int xpos;
    int ypos;

    int curPattern; // idx for current Pattern

    int patternNum; // total number of patterns

    static int direction[4][2];

    Pattern tempPattern; // pattern for Obstruct.addMotion() 
    Pattern movePattern; // pattern for Obstruct.move()

    bool patternStarted;

    char body;
};


