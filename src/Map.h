#ifndef TREASUREHUNT_H_
#define TREASUREHUNT_H_

#include <vector>
#include <iostream>
#include "linuxfunc.h"

using namespace std;

#endif

#include <cstring>

#define MAXROW		15
#define MAXCOL		30

#define MAP_START_XPOS	5
#define MAP_START_YPOS	5

class Map{

  private:
    
    char map[MAXROW][MAXCOL];


   public:
     
     Map(){}

     void setMap(char * buf){
         int count=0;
	 int row=0;
	 for(int i=0;i<strlen(buf);i++){
	    map[row][count] = buf[i];
	    if((++count) % MAXCOL == 0){
		row++;	
		count=0;
	    }
   	    
	 }
	     
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



