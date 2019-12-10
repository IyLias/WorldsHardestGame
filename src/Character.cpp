#include "Character.h"

Character::Character(int x,int y){

 body = '#';
 xpos = x;
 ypos = y;

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
