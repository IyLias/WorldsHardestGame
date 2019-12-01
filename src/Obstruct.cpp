#include "Obstruct.h"


int Obstruct::direction[4][2]={{0,-1},{-1,0},{0,1},{1,0}};

void Obstruct::move(){
 
 if(patternStarted == false){ 
    movePattern.setPattern(motions.getCurPattern(curPattern));
    patternStarted = true;
 }
 
 movePattern.period -= 0.01;
 if(movePattern.period <= 0){ //when period gets less than 0, then Obstruct moves!
     movePattern.period = movePattern.vel;
     movePattern.curMoves++;
     gotoxy(xpos,ypos); cout << ' ';
     
     xpos += direction[movePattern.dir][0];
     if(xpos <= 1) xpos = 1;

     ypos += direction[movePattern.dir][1];
     if(ypos <= 1) ypos = 1;
     draw(); // move with direction
 }

 if(movePattern.curMoves >= movePattern.totalMoves){
     movePattern.curMoves = 0;
     patternStarted = false;
     curPattern += 1;
     curPattern %= patternNum;
 } 

}



void Obstruct::draw(){

 gotoxy(xpos,ypos);
 cout << body; //fflush(stdout);
 gotoxy(xpos,ypos);
}
