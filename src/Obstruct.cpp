#include "Obstruct.h"


int Obstruct::direction[4][2]={{0,-1},{-1,0},{0,1},{1,0}};

void Obstruct::move(const Character& hero, const Map& gameMap){
 
 if(patternStarted == false){ 
    movePattern.setPattern(motions.getCurPattern(curPattern));
    patternStarted = true;
 }
 
 movePattern.period -= 0.01;
 if(movePattern.period <= 0){ //when period gets less than 0, then Obstruct moves!
     movePattern.period = movePattern.vel;
     movePattern.curMoves++;
     gotoxy(xpos,ypos); cout << ' ';
     
     if(movePattern.dir != SHORTEST){

        xpos += direction[movePattern.dir][0];
        ypos += direction[movePattern.dir][1];

        if(movePattern.curMoves >= movePattern.totalMoves){
          movePattern.curMoves = 0;
          patternStarted = false;
          curPattern += 1;
          curPattern %= patternNum;
        } 

     }else{ // if dir is SHORTEST, continuosly follow Character 

	int chxpos = hero.getXpos();
	int chypos = hero.getYpos();

	for(int i=0;i<4;i++){ // search 4 ways and find shortest

	   

	}

     }

     draw(); // move with direction
 } 

}



void Obstruct::draw(){

 gotoxy(xpos,ypos);
 set_color(BLUE); cout << body; set_color(WHITE); //fflush(stdout);
 gotoxy(xpos,ypos);
}
