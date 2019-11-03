#ifndef TREASUREHUNT_H_
#define TREASUREHUNT_H_

#include <iostream>
#include <cstdlib>
#include <vector>
#include "linuxfunc.h"

using namespace std;

#endif


class Obstruct{

 public:
   
   void move();
   
   void draw();

 private:
    
    int xpos;
    int ypos;

    char body;
};


