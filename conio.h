/* 
	* This is conio.h compatible header file for gcc.
*/

#ifndef _CONIO_H
#define _CONIO_H 1

#include <termios.h>
#include <unistd.h>
#include<stdlib.h>
#include <stdio.h>

void clrscr()
{
	system("clear");
}

void gotoxy(int x,int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}

/* reads from keypress, doesn't echo */
int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

/* reads from keypress, echoes */
int getche(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

#endif  /* conio.h */


