#ifndef TREASUREHUNT_H_
#define TREASUREHUNT_H_

#include <vector>
#include <iostream>
#include "linuxfunc.h"

using namespace std;

#endif

#include <cstring>

#define MAXROW		15
#define MAXCOL		70

#define WALL		49 //ascii code for 1

#define MAP_START_XPOS	40
#define MAP_START_YPOS	10

class Map{

  private:
    
    char map[MAXROW][MAXCOL];

    int row;


   public:
     
     Map(){row=0;}

     Map(int row){
	this->row = row;
     }

     void setMap(char * buf){
	 for(int i=0;i<MAXCOL;i++){
	    map[row][i] = buf[i];
	 }
	 row++;
     }    


     void setRow(int r){
	 row = r;
     }

     void printMap(){

	for(int i=0;i<MAXROW;i++){
	   gotoxy(MAP_START_XPOS,MAP_START_YPOS+i);
   	   for(int j=0;j<MAXCOL;j++)
		if(map[i][j] == '1'){
		  set_color(MAGENTA);
		  cout << '*';
		  set_color(WHITE);
		}
	        else if(map[i][j] == '0' || map[i][j] =='2')
		   cout << ' ';
	        else if(map[i][j] == '7'){
		   set_color(YELLOW);
		   cout << '$';
		   set_color(WHITE);
		}
	}

     }

     char getCurPosition(int r,int c) const{
	  return map[r][c];
     }


};



