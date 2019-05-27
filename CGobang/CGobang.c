// CGobang.cpp: 定义应用程序的入口点。
//

#include "CGobang.h"

int main()
{
	initscr();
	move(2, 2);
	printw("Hello world!");
	refresh();
	getch();
	endwin();
	return 0;
}
