#ifndef TREASUREHUNT_H_
#define TREASUREHUNT_H_

#include <vector>
#include <iostream>

using namespace std;

#endif

#include <cstring>

#define MAXROW		15
#define MAXCOL		30

#define WALL		-1
#define SPACE		0


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
   	   for(int j=0;j<MAXCOL;j++)
		cout << map[i][j];
	   cout << endl;
	}

     }

     char getCurPosition(int r,int c){
	  return map[r][c];
     }


};



