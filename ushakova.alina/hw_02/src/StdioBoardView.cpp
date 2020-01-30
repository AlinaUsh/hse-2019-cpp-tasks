#include "../include/StdioBoardView.h"
#include <iostream>

void StdioBoardView::setSilenceMode() {
    this->_silence_mode = true;
}

bool StdioBoardView::readCell(int &x, int &y, Player cur_player) {
    while (true) {
        cur_player.printRequest();
        std::cin >> x >> y;
        if (x == -1 && y == -1) {
            return false;
        }
        if (_board.canMove(x, y)) {
            return true;
        }
        std::cout << "Bad move!\n";
    }
}

void StdioBoardView::runGame() {
    Player cur_player(player_X);
    int x, y;
    while (true) {
        printBoard();
        if (!readCell(x, y, cur_player))
            return;
        _board.move(x, y, cur_player);
        game_status cur_state = _board.getState(x, y);
        if (cur_state != not_ended) {
            _silence_mode = false;
            printBoard();
        }
        switch (cur_state) {
            case draw:
                std::cout << "Draw.\n";
                return;
            case player_wins:
                std::cout << cur_player._name << " wins!\n";
                return;
            case not_ended:
                break;
        }
        cur_player.changePlayer();
    }
}

void StdioBoardView::printBoard() {
    if (_silence_mode)
        return;
    std::cout << std::endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cell cur_cell = _board.getCell(i, j);
            switch (cur_cell) {
                case cell_empty:
                    std::cout << '.';
                    break;
                case cell_O:
                    std::cout << 'O';
                    break;
                case cell_X:
                    std::cout << "X";
                    break;
            }
        }
        std::cout << std::endl;
    }
}
