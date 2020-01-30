#ifndef HW_02_STDIOBOARDVIEW_H
#define HW_02_STDIOBOARDVIEW_H

#include "Board.h"

class StdioBoardView {
public:
    StdioBoardView(Board &board) : _board(board) {};
    ~StdioBoardView() = default;

    /** Основной цикл игры, от начала до конца. */
    void runGame();

    // Можно добавлять методы при необходимости.
    void setSilenceMode();
    void printBoard();
    bool readCell(int &x, int &y, Player cur_player);
private:
    bool _silence_mode = false;
    Board &_board;
};

#endif //HW_02_STDIOBOARDVIEW_H
