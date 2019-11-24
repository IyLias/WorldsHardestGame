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

   Stage(){}


   void setDatas(char * buf){
   
   // get datas from GameManager.readDataFromFile() 
   // set datas to Map and several Obstructs

     setGameMap(buf);      



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
   }



 private:
   Map gameMap;
 
   vector<Obstruct> Obstructs;

};
