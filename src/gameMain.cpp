#include "TreasureHunt.h"


//#include "GameManager.h"

int main(){

 GameManager GM;
 GM.init();

 while(1){

   GM.gameMenu();

   if(GM.getGameState() == GAME_END_STATE)
      goto GAME_END;

 GAME_PLAYING:

   GM.playGame();

   if(GM.getGameState() == STAGE_CLEAR_STATE){
     GM.setGameState(GAME_PLAYING_STATE); 
     goto GAME_PLAYING;
   }

 }


  GAME_END:
	system("reset");

 return 0;
}
