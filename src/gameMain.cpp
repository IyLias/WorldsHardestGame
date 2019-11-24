#include "TreasureHunt.h"


//#include "GameManager.h"

int main(){

 GameManager GM(10,15,2);
 GM.init();

 Character hero;
 hero.draw();

 GM.playGame(hero);

 

 return 0;
}
