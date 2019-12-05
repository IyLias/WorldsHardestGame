#include "Character.h"

Character::Character(){

 body = '#';
 xpos = 41;
 ypos = 11;

}


void Character::move(int x,int y){

 gotoxy(xpos,ypos); cout << ' '; //fflush(stdout);
 xpos = x, ypos = y;
 draw();
}



void Character::draw(){

 gotoxy(xpos,ypos);
 cout << body;
 gotoxy(xpos,ypos);
}
