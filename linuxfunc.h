	
// There's no kbhit() function in linux if you want to use kbhit() function, use this code as below.
// reference : http://indra17.tistory.com/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>


static struct termios initial_settings, new_settings;
 
static int peek_character = -1;

void gotoxy(int xpos,int ypos);

void init_keyboard();

 
void close_keyboard();

int _kbhit();
 
int _getch();
 
int _putch(int c);
