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


   void setDatas(); // get datas from GameManager.readDataFromFile() 
   // set datas to Map and several Obstructs


   void addObstruct(const Obstruct& obs){
      Obstructs.push_back(obs);
   }



 private:
   Map gameMap;
 
   vector<Obstruct> Obstructs;

};
