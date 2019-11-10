#ifndef TREASUREHUNT_H_
#define TREASUREHUNT_H_

#include <iostream>
#include <cstdlib>
#include <vector>
#include "linuxfunc.h"
#include "PatternSet.h"

using namespace std;

#endif


class PatternSet; 

class Obstruct{

 public:

   Obstruct(int patternNum);

   void move();
   
   void draw();

 private:
    
    int xpos;
    int ypos;

    char body;

    PatternSet motions;
};


