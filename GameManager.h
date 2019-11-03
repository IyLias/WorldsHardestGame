#ifndef TREASUREHUNT_H_
#define TREASUREHUNT_H_

#include <vector>
#include <iostream>
#include "linuxfunc.h"

using namespace std;

#endif

class Character;

class GameManager{


  public: 


     GameManager(){}

     void init();

     void gameMenu();

     void playGame(Character& hero);

     void gameEnd();

  private:
      
     bool gameClearFlag;
     bool gameEndFlag;

};

