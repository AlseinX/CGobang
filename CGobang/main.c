// CGobang.cpp: 定义应用程序的入口点。
//

#include "main.h"
#include "color.h"
#include "chessboard.h"
#include "locale.h"
#include "stdlib.h"

int main()
{
	//setlocale(LC_ALL, "");
	system("mode con:cols=62 lines=31");
	initscr();
	setColor();
	move(6, 2);
	createChessboard(0, 0);
	doupdate();
	getch();
	endwin();
	return 0;
}
