#ifndef TREASUREHUNT_H_
#define TREASUREHUNT_H_

#include <vector>
#include <iostream>
#include <assert.h>

using namespace std;

#endif

// each Pattern class means just one motion for some period
// ex1) just going left with velocity x for time y
// ex2) going right-bottom diagonal with velocity x' for time y'

// Motions of Obstructs are composite of Patterns 
// So Obstruct should have Pattern set which contains Patterns as an element

class Pattern{

  public:

     Pattern() {}


     Pattern(double period,double vel,int dir,int tMoves){
      this->period = period;
      this->vel = period;

      this->dir = dir;

      this->curMoves = 0;
      this->totalMoves = tMoves;
     }	     

     void setPattern(double p,double v,int d,int curMoves,int tMoves){
        this->period = p;
	this->vel = v;
	this->dir = d;
	this->curMoves = curMoves;
	this->totalMoves = tMoves;
     }


     void setPattern(Pattern pattern){
	this->period = pattern.period;
	this->vel = pattern.vel;
	this->dir = pattern.dir;
	this->curMoves = pattern.curMoves;
	this->totalMoves = pattern.totalMoves;
     }


     void setPeriod(int p){
	 period = p;
     }

     void periodMinusOne(){
	 period-=1;
     }

     int getPeriod(){
	 return period;
     }



     void setVel(int v){
	 vel = v;
     }
 
     int getVel(){
	 return vel;
     }


     double period; // when period is 0, object moves
     double vel;
   
     int dir;


     int curMoves; // current number of moves
     int totalMoves; // possible total Moves

};



