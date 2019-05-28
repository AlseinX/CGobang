#include "chessboard.h"

void printChessboardBaseLine(WINDOW *win, int y, int x, wchar_t beg, wchar_t mid, wchar_t fill, wchar_t end)
{
    const wchar_t blank = ' ';
    wattron(win, COLOR_PAIR(PAIR_CB));
    mvwaddnwstr(win, y, x, &beg, 1);
    mvwaddnwstr(win, y, x + 1, &blank, 1);
    mvwaddnwstr(win, y, x + 2, &fill, 1);
    mvwaddnwstr(win, y, x + 3, &blank, 1);
    for (int i = 1; i < CB_YLENGTH - 1; i++)
    {
        mvwaddnwstr(win, y, x + i * 4, &mid, 1);
        mvwaddnwstr(win, y, x + i * 4 + 1, &blank, 1);
        mvwaddnwstr(win, y, x + i * 4 + 2, &fill, 1);
        mvwaddnwstr(win, y, x + i * 4 + 3, &blank, 1);
    }
    update_panels();
    doupdate();
    mvwaddnwstr(win, y, x + CB_DISPLAY_WIDTH - 2, &end, 1);
    mvwaddnwstr(win, y, x + CB_DISPLAY_WIDTH - 1, &blank, 1);
}

PANEL *createChessboard(int y, int x)
{
    WINDOW *win = newwin(CB_DISPLAY_HEIGHT + CB_XBORDER * 6, CB_DISPLAY_WIDTH + CB_YBORDER * 8, y, x);
    PANEL *pnl = new_panel(win);
    wattron(win, COLOR_PAIR(PAIR_CB));
    printChessboardBaseLine(win, CB_YBORDER, CB_XBORDER, L'┏', L'┯', L'━', L'┓');
    update_panels();
    doupdate();
    printChessboardBaseLine(win, CB_YBORDER + 1, CB_XBORDER, L'┃', L'│', L'　', L'┃');
    for (int i = 1; i < CB_YLENGTH - 1; i++)
    {
        printChessboardBaseLine(win, CB_YBORDER + i * 2, CB_XBORDER, L'┠', L'┼', L'─', L'┨');
        printChessboardBaseLine(win, CB_YBORDER + i * 2 + 1, CB_XBORDER, L'┃', L'│', L'　', L'┃');
    }
    printChessboardBaseLine(win, CB_YBORDER + CB_DISPLAY_HEIGHT - 1, CB_XBORDER, L'┗', L'┷', L'━', L'┛');
    wattroff(win, COLOR_PAIR(PAIR_CB));
    update_panels();
    return pnl;
}