#include "Character.h"

Character::Character(){

 body = '#';
 xpos = 30;
 ypos = 40;

}


void Character::move(int x,int y){

 gotoxy(xpos,ypos); cout << " ";
 xpos = x, ypos = y;
 draw();
}



void Character::draw(){

 gotoxy(xpos,ypos);
 cout << body << endl;

}
