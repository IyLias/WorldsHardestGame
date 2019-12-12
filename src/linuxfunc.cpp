#include "linuxfunc.h"

void gotoxy(int xpos,int ypos){
 printf("\033[%d;%df",ypos,xpos);
 fflush(stdout);
}


void set_color(int color){

 static char colors[13][12]= {
 "\033[0;31m","\033[1;31m","\033[0;32m","\033[1;32m",
 "\033[0;33m","\033[01;33m","\033[0;34m","\033[1;34m",
 "\033[0;35m","\033[1;35m","\033[0;36m","\033[1;36m",
 "\033[0m"};

 printf(colors[color]);
}


void init_keyboard()
{
    tcgetattr(0,&initial_settings);
    new_settings = initial_settings;
    new_settings.c_lflag &= ~ICANON;
    new_settings.c_lflag &= ~ECHO;
    new_settings.c_cc[VMIN] = 1;
    new_settings.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &new_settings);
}
 
void close_keyboard()
{
    tcsetattr(0, TCSANOW, &initial_settings);
}
 
int _kbhit()
{
    unsigned char ch;
    int nread;
 
    if (peek_character != -1) return 1;
    new_settings.c_cc[VMIN]=0;
    tcsetattr(0, TCSANOW, &new_settings);
    nread = read(0,&ch,1);
    new_settings.c_cc[VMIN]=1;
    tcsetattr(0, TCSANOW, &new_settings);
    if(nread == 1)
    {
        peek_character = ch;
        return 1;
    }
    return 0;
}
 
int _getch()
{
    char ch;
 
    if(peek_character != -1)
    {
        ch = peek_character;
        peek_character = -1;
        return ch;
    }
    read(0,&ch,1);
    return ch;
}

int _putch(int c) {
 // putchar(c);
    fflush(stdout);
    return c;
}
