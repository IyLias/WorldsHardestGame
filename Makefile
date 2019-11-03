gameMain: gameMain.o GameManager.o Map.o Character.o Pattern.o Obstruct.o linuxfunc.o
	g++ -o gameMain gameMain.o GameManager.o Map.o Character.o Pattern.o Obstruct.o linuxfunc.o

linuxfunc.o: linuxfunc.cpp linuxfunc.h
	g++ -c linuxfunc.cpp	

gameMain.o: gameMain.cpp TreasureHunt.h
	g++ -c gameMain.cpp 

GameManager.o: GameManager.cpp GameManager.h linuxfunc.h 
	g++ -c GameManager.cpp

Map.o: Map.cpp Map.h
	g++ -c Map.cpp

Character.o: Character.cpp Character.h linuxfunc.h
	g++ -c Character.cpp

Pattern.o: Pattern.cpp Pattern.h
	g++ -c Pattern.cpp

Obstruct.o: Obstruct.cpp Obstruct.h linuxfunc.h
	g++ -c Obstruct.cpp

clean:
	rm -f *.o
