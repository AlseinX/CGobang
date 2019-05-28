#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <ncursesw/curses.h>
#include <ncursesw/panel.h>
#include "definitions.h"

PANEL *createChessboard(int y, int x);

#endif
