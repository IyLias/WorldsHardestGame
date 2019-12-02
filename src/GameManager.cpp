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
   int obstructNum=0;
   char bufForMap[BUF_SIZE_FOR_MAP]; 
   ObstructData obstructData;
   PatternData patternData;

   // should read all stages 
   
   // each stage consists of one Map and several obstructs
   // read Map datas first
   // consists of MAXROW * MAXCOL character datas
   
   // each stage has different number of Obstructs
   // each Obstruct data has their first xpos,ypos and their pattern datas

   //for(int i=0;i< TOTAL_STAGE_NUM ; i++){

     for(int i=0;i<MAXROW;i++){
        memset(bufForMap,0x00,sizeof(bufForMap));
        read(datafile,bufForMap,MAXCOL+1);      
        stage[curStageNum].setGameMap(bufForMap);
     }
     
     obstructNum = readIntData(datafile);
   //cout << "obstruct num for stage 1: " << obstructNum << endl;
     for(int i=0;i<obstructNum;i++){
       obstructData.xpos = readIntData(datafile);obstructData.ypos = readIntData(datafile); obstructData.patternNum = readIntData(datafile); 
     //cout << "obstruct data: " << obstructData.xpos << " " << obstructData.ypos << " " << obstructData.patternNum << endl;
       stage[curStageNum].setObstruct(obstructData.xpos,obstructData.ypos,obstructData.patternNum);

       for(int j=0;j<obstructData.patternNum;j++){
	   patternData.period = readIntData(datafile); patternData.vel = readIntData(datafile); patternData.dir = readIntData(datafile);patternData.totalMoves = readIntData(datafile);
      //   cout << "pattern data: " << patternData.period << " " << patternData.vel << " " << patternData.dir << " " << patternData.totalMoves << endl;
	   stage[curStageNum].obstructAddMotion(patternData.period,patternData.vel,patternData.dir,patternData.totalMoves);
       }

     }

   //}

 }


void GameManager::init(){
   system("clear"); // clear screen
   system("setterm -cursor off"); // command for hiding cursor
   gotoxy(1,1);
   cout << "hello treasure hunt!" << endl;

   readDataFromFile();
}


bool GameManager::checkCharacterObstructCrush(const Character& hero){

  for(int i=0;i<stage[curStageNum].numOfObstructs;i++){  
      if(hero.getXpos() == stage[curStageNum].getCurObstructXpos(i) &&
		      hero.getYpos() == stage[curStageNum].getCurObstructYpos(i))
	      return true;
  }

  return false;
}


void GameManager::playGame(Character& hero){

  stage[curStageNum].drawMap();
  stage[curStageNum].drawObstructs();
  hero.draw();

  while(checkCharacterObstructCrush(hero) == false){

     stage[curStageNum].moveObstructs();

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

    
  }     

  close_keyboard();
}


void GameManager::gameEnd(){

  //system(cmd); 

  

}
