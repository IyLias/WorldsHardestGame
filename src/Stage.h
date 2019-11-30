#ifndef TREASUREHUNT_H_
#define TREASUREHUNT_H_

#include <vector>
#include <iostream>
#include <cstdlib>
#include "linuxfunc.h"

using namespace std;

#endif

#include "Map.h"
#include "Obstruct.h"


class Stage{


 public:
 
   int numOfObstructs; // number of obstructs in this Stage

   Stage(){numOfObstructs=0;}


   void setDatas(char * buf){
   
   // get datas from GameManager.readDataFromFile() 
   // set datas to Map and several Obstructs

     setGameMap(buf);      

   //  cout << "buf size: " << strlen(buf) << endl;


   }


   void setGameMap(char * buf){
	gameMap.setMap(buf);
   }

   void drawMap(){
       gameMap.printMap();
   }


   void moveObstructs(){
	for(int i=0;i<Obstructs.size();i++)
	   Obstructs[i].move();
   }

   void addObstruct(const Obstruct& obs){
      Obstructs.push_back(obs);
      numOfObstructs++;
   }

   int getCurObstructXpos(int cur){
	return Obstructs[cur].getXpos();
   }

   int getCurObstructYpos(int cur){
	return Obstructs[cur].getYpos();
   }


 private:
   Map gameMap;
 
   vector<Obstruct> Obstructs;

};
