#include "GameManager.h"


void GameManager::init(){
   system("clear");
   cout << "hello treasure hunt!" << endl;
}


void GameManager::playGame(Character& hero){

  while(1){
    
     if(_kbhit()){
          int ch = _getch();
	  _putch(ch);

	 if(ch == 'c')
	    break;

	  if (ch == '\033'){
	     ch = _getch();
	  switch(_getch()){
 	    
	     case 'A': //up
  	   	//  cout << "up" << endl;
		  hero.move(hero.getXpos(),hero.getYpos()-1);
		  break;
	     case 'B': //down
               //   cout << "down" << endl;
		  hero.move(hero.getXpos(),hero.getYpos()+1);
  		  break;
	     case 'C': //right
		 //cout << "right" << endl;
		  hero.move(hero.getXpos()+1,hero.getYpos());
		  break;
	     case 'D': //left
		 //cout << "left" << endl;
	   	  hero.move(hero.getXpos()-1,hero.getYpos());
		  break;
	   }
	  }

     }

  }     

  close_keyboard();
}


void GameManager::gameEnd(){

  //system(cmd); 

  

}
