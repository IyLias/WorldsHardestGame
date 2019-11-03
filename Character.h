#ifndef TREASUREHUNT_H_
#define TREASUREHUNT_H_

#include <iostream>
#include <cstdlib>
#include "linuxfunc.h"

using namespace std;



#endif

class Character{


 public:

    Character();

    void move(int x,int y);
    
    void draw();

 private:
    int xpos;
    int ypos;
   
    char body;

};


