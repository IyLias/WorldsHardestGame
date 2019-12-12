	
// There's no kbhit() function in linux if you want to use kbhit() function, use this code as below.
// reference : http://indra17.tistory.com/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>

#define RED		0
#define BOLD_RED	1
#define GREEN		2
#define BOLD_GREEN	3
#define YELLOW		4
#define BOLD_YELLOW	5
#define BLUE		6
#define BOLD_BLUE	7
#define MAGENTA		8
#define BOLD_MAGENTA	9
#define CYAN		10
#define BOLD_CYAN	11
#define WHITE		12

static struct termios initial_settings, new_settings;
 
static int peek_character = -1;

void gotoxy(int xpos,int ypos);

void set_color(int color);

void init_keyboard();

 
void close_keyboard();

int _kbhit();
 
int _getch();
 
int _putch(int c);
