#ifndef TREASUREHUNT_H_
#define TREASUREHUNT_H_

#include <iostream>
#include <cstdlib>
#include "linuxfunc.h"

using namespace std;



#endif

class Character{


 public:

    Character(){
      body = '#';
      xpos = 41;
      ypos = 11;
    }

    Character(int x,int y);

    void move(int x,int y);
    
    void draw();

    void setBody() { body = '#'; }

    void setXpos(int x) { xpos = x; }

    int getXpos() const { return xpos; }

    void setYpos(int y) { ypos = y; }

    int getYpos() const { return ypos; }

 private:
    int xpos;
    int ypos;
   
    char body;

};


