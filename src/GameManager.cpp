#include "GameManager.h"


int GameManager::readIntData(int fp){

  char ch=0;
  char num[MAXLEN];
  int idx=0;
 
  memset(num,0x00,MAXLEN);

  while(1){
    read(fp,&ch,1);
    if(ch == ' ' || ch == '\n') break;
    num[idx++] = ch;
  }

  return atoi(num);
}

void GameManager::readDataFromFile(){ // read all datas about all stages from file

   int datafile = open("datafile.txt",O_RDWR | O_APPEND,0644); 
   int obstructNum=0,txpos,typos,chxpos,chypos;
   char bufForMap[BUF_SIZE_FOR_MAP]; 
   ObstructData obstructData;
   PatternData patternData;

   // should read all stages 
   
   // each stage consists of one Map and several obstructs
   // read Map datas first
   // consists of MAXROW * MAXCOL character datas
   
   // each stage has different number of Obstructs
   // each Obstruct data has their first xpos,ypos and their pattern datas

   for(int i=1; i<= TOTAL_STAGE_NUM ; i++){

     for(int j=0;j<MAXROW;j++){   // read Map datas
        memset(bufForMap,0x00,sizeof(bufForMap));
        read(datafile,bufForMap,MAXCOL+1);      
        stage[curStageNum].setGameMap(bufForMap);
     }


     chxpos = readIntData(datafile); chypos = readIntData(datafile); // read Character Pos for Stage
     //cout << "chpos ; " << chxpos << " " << chypos <<endl;
     stage[curStageNum].setCharacterPos(curStageNum,chxpos,chypos);

     txpos = readIntData(datafile); typos = readIntData(datafile);  // read Treasure Pos for Stage
     //cout << "treasure pos : " << txpos << " " << typos << endl;
     stage[curStageNum].setTreasure(txpos,typos);


     obstructNum = readIntData(datafile);   // read number of Obstructs
   //cout << "obstruct num for stage 1: " << obstructNum << endl;
     for(int k=0;k<obstructNum;k++){
       obstructData.xpos = readIntData(datafile);obstructData.ypos = readIntData(datafile); obstructData.patternNum = readIntData(datafile); 
     //cout << "obstruct data: " << obstructData.xpos << " " << obstructData.ypos << " " << obstructData.patternNum << endl;
       stage[curStageNum].setObstruct(obstructData.xpos,obstructData.ypos,obstructData.patternNum);

       for(int p=0;p<obstructData.patternNum;p++){ // read Patterns of Obstructs
	   patternData.period = readIntData(datafile); patternData.vel = readIntData(datafile); patternData.dir = readIntData(datafile);patternData.totalMoves = readIntData(datafile);
         //cout << "pattern data: " << patternData.period << " " << patternData.vel << " " << patternData.dir << " " << patternData.totalMoves << endl;
	   stage[curStageNum].obstructAddMotion(patternData.period,patternData.vel,patternData.dir,patternData.totalMoves);
       }

     }

     curStageNum++;
   }

   //curStageNum--;
   curStageNum=1;
}


void GameManager::init(){
   system("clear"); // clear screen
   system("setterm -cursor off"); // command for hiding cursor
   gotoxy(1,1);

   gameState = GAME_MENU_STATE;

   readDataFromFile();
}


void GameManager::gameMenu(){

  int cursorPos;
  system("clear");
   
  gotoxy(SCREEN_WIDTH/2-75,SCREEN_HEIGHT-41);
  cout << "  ***********         **********               *********                 ****              **********        ***********       ";
  gotoxy(SCREEN_WIDTH/2-75,SCREEN_HEIGHT-40);
  cout << " *************      *************          **************              **    **           ************      *************        ";
  gotoxy(SCREEN_WIDTH/2-75,SCREEN_HEIGHT-39);
  cout << "***              ****         *****      *****                       ***      ***        ***       ***     *** ";
  gotoxy(SCREEN_WIDTH/2-75,SCREEN_HEIGHT-38);
  cout << "***               *****        *****    ****                        ***        ***       ***       **      ***  ";
  gotoxy(SCREEN_WIDTH/2-75,SCREEN_HEIGHT-37);
  cout << "*************      ******              ***                         ****************      ***********       *************   ";
  gotoxy(SCREEN_WIDTH/2-75,SCREEN_HEIGHT-36);
  cout << "*************         ******           ***                        ******************     ***               *************";
  gotoxy(SCREEN_WIDTH/2-75,SCREEN_HEIGHT-35);
  cout << "***               ****      ******      ****                     ****            ****    ***               ***";
  gotoxy(SCREEN_WIDTH/2-75,SCREEN_HEIGHT-34);
  cout << "***                ****         ****      *****                 ****              ****   ***               ***";
  gotoxy(SCREEN_WIDTH/2-75,SCREEN_HEIGHT-33);
  cout << " *************       **************         **************     ****                ****  ***                *************";
  gotoxy(SCREEN_WIDTH/2-75,SCREEN_HEIGHT-32);
  cout << "  ***********         ***********             **********      ****                  **** ***                 ***********";



  cursorPos = GAME_START_CURSOR;
  gotoxy(CURSOR_XPOS,GAME_START_CURSOR);
  cout << "=>";

  gotoxy(CURSOR_XPOS + 3,GAME_START_CURSOR);
  set_color(CYAN);
  cout << "Game Start"; fflush(stdout);
  gotoxy(CURSOR_XPOS + 4,GAME_END_CURSOR);
  cout << "Game End"; fflush(stdout);
  set_color(WHITE);

  while(1){

     if(_kbhit()){
          char ch = _getch();
	  _putch(ch);

	  if(ch == 's'){ // when s key pressed 

 	    if(cursorPos == GAME_START_CURSOR)
		 gameState = GAME_PLAYING_STATE;
	    else if(cursorPos == GAME_END_CURSOR)
		 gameState = GAME_END_STATE;

	    return;
	  }

	  if (ch == '\033'){
	     ch = _getch();
	  switch(_getch()){
 	    
	     case 'A': //up
  	   	//  cout << "up" << endl;
		  gotoxy(CURSOR_XPOS,cursorPos);
		  cout << "  ";
		 
		  if(cursorPos != GAME_START_CURSOR)
		     cursorPos -= CURSOR_MOVE;
		  gotoxy(CURSOR_XPOS,cursorPos);
		  cout << "=>"; fflush(stdout);
		  break;
	     case 'B': //down
                //  cout << "down" << endl;
		  gotoxy(CURSOR_XPOS,cursorPos);
		  cout << "  ";
		 
		  if(cursorPos != GAME_END_CURSOR)
		     cursorPos += CURSOR_MOVE;
		  gotoxy(CURSOR_XPOS,cursorPos);
		  cout << "=>"; fflush(stdout);
		
  		  break;
	   }
	 }

    }

  }



}

void GameManager::gameGuide(){

 gotoxy(40,30);
 cout << "---------move Character "; set_color(RED); cout <<"#"; set_color(WHITE); cout << "----------";
 gotoxy(40,32);
 cout << "-move right: press right arrow key-";
 gotoxy(40,34);
 cout << "-move left: press left arrow key---";
 gotoxy(40,36);
 cout << "-move down: press bottom arrow key-";
 gotoxy(40,38);
 cout << "-move up: press up arrow key-------";
 gotoxy(40,40);
 cout << "-----------------------------------";

 

 gotoxy(80,30);
 set_color(RED);
 cout << "#    ";
 set_color(WHITE);
 cout << "Character";
 gotoxy(79,32);
 set_color(BLUE);
 cout << "@";
 set_color(BOLD_GREEN);
 cout << " %";
 set_color(WHITE);
 cout << "   Obstructs";
 gotoxy(80,34);
 set_color(YELLOW);
 cout << "$    ";
 set_color(WHITE);
 cout << "Treasure";

 gotoxy(SCREEN_WIDTH/2-20,6);
 cout << "STAGE " << curStageNum;

 gotoxy(20,4);
 cout << "press b key to gameMenu";






}


bool GameManager::checkCharacterObstructCrush(){

  for(int i=0;i<stage[curStageNum].numOfObstructs;i++){  
      if(hero.getXpos() == stage[curStageNum].getCurObstructXpos(i) &&
		      hero.getYpos() == stage[curStageNum].getCurObstructYpos(i)){	      
	      
	      // if following objects, then goto first pos 
	      
	      return true;
      }
  }

  return false;
}



bool GameManager::checkGameClear(){

   if(hero.getXpos() == stage[curStageNum].getTreasureXpos() && hero.getYpos() == stage[curStageNum].getTreasureYpos())
	return true; 

   return false;
}



void GameManager::playGame(){

  system("clear");
  gameGuide();

  setCharacterPos();
  stage[curStageNum].drawMap();
  stage[curStageNum].drawObstructs();
  hero.draw();

  while(1){

     stage[curStageNum].moveObstructs(hero,stage[curStageNum].getGameMap());
     if(checkCharacterObstructCrush() == true){ // when obstruct and character crushed, goto first position
	hero.move(stage[curStageNum].characterPos[curStageNum][0],stage[curStageNum].characterPos[curStageNum][1]);
	continue;	
     }

     if(_kbhit()){
          int ch = _getch();
	  _putch(ch);

	 if(ch == 'b'){ // when b pressed, set stageNum 1 and goto gameMenu
	   gameState = GAME_MENU_STATE;
   	   curStageNum = 1; 
	   return;
	 }

	  if (ch == '\033'){
	     ch = _getch();
	  switch(_getch()){
 	    
	     case 'A': //up
  	   	//  cout << "up" << endl;
		if(stage[curStageNum].getMapCurPosition(hero.getYpos()-1-MAP_START_YPOS,hero.getXpos()-MAP_START_XPOS) != WALL)  
		   hero.move(hero.getXpos(),hero.getYpos()-1);
		  break;
	     case 'B': //down
               //   cout << "down" << endl;
		if(stage[curStageNum].getMapCurPosition(hero.getYpos()+1-MAP_START_YPOS,hero.getXpos()-MAP_START_XPOS) != WALL)  
		    hero.move(hero.getXpos(),hero.getYpos()+1);
  		  break;
	     case 'C': //right
		 //cout << "right" << endl;
		if(stage[curStageNum].getMapCurPosition(hero.getYpos()-MAP_START_YPOS,hero.getXpos()+1-MAP_START_XPOS) != WALL)  
		    hero.move(hero.getXpos()+1,hero.getYpos());
		  break;
	     case 'D': //left
		 //cout << "left" << endl;
	   	if(stage[curStageNum].getMapCurPosition(hero.getYpos()-MAP_START_YPOS,hero.getXpos()-1-MAP_START_XPOS) != WALL)  
		  hero.move(hero.getXpos()-1,hero.getYpos());
		  break;
	   }
	 }

     }


     if(checkGameClear() == true){ // when stage Cleared , goto Next Stage
		
	if(curStageNum < TOTAL_STAGE_NUM)
	  curStageNum++;

	gameState = STAGE_CLEAR_STATE;
	return;
     }
  }     

  close_keyboard();
}


void GameManager::gameEnd(){

  //system(cmd); 

  

}
