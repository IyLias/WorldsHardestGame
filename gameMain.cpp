#include "TreasureHunt.h"

//#include "GameManager.h"

int main(){

 GameManager GM;
 GM.init();

 Character hero;
 hero.draw();

 GM.playGame(hero);

 

 return 0;
}
