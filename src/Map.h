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
#define MAP_START_YPOS	20

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
		if(map[i][j] == '1')
		   cout << '+';
	        else
		   cout << ' ';
	}

     }

     char getCurPosition(int r,int c){
	  return map[r][c];
     }


};



