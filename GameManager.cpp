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
  	   	  cout << "up" << endl;
		  hero.move();
		  break;
	     case 'B': //down
                  cout << "down" << endl;
		  hero.move();
  		  break;
	     case 'C': //right
		  cout << "right" << endl;
		  hero.move();
		  break;
	     case 'D': //left
		  cout << "left" << endl;
	   	  hero.move();
		  break;
	   }
	  }

     }

  }     

  close_keyboard();

}


