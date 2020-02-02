#include "StdioBoardView.h"
#include <iostream>
#include <vector>
#include <string>

void StdioBoardView::setSilenceMode() {
    this->silence_mode = true;
}

bool check_str(std::string &str) {
    for (size_t i = 0; i < str.size(); i++) {
        if (!(str[i] == '-' || str[i] == ' ' || (str[i] >= '0' && str[i] <= '9'))) {
            return false;
        }
    }
    return true;
}

void get_all_ints(std::vector<int> &vec, std::string &str) {
    bool fl = false, neg_num = false;
    int cur_num = 0;
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] == ' ') {
            if (fl) {
                if (neg_num) {
                    cur_num *= -1;
                }
                vec.push_back(cur_num);
            }
            cur_num = 0;
            neg_num = false;
            fl = false;
            continue;
        }
        if (str[i] >= '0' && str[i] <= '9') {
            fl = true;
            cur_num = cur_num * 10 + str[i] - '0';
        }
        if (str[i] == '-') {
            neg_num = true;
        }
    }
}

bool StdioBoardView::readCell(int &x, int &y, Player cur_player) {
    while (true) {
        cur_player.printRequest();
        std::string input;
        std::getline(std::cin, input);
        input += " ";
        bool fl_bad_move = false;
        if (!check_str(input)) {
            fl_bad_move = true;
        } else {
            std::vector<int> v;
            get_all_ints(v, input);
            if (v.size() != 2) {
                fl_bad_move = true;
            } else {
                if (v[0] == -1 && v[1] == -1) {
                    return false;
                }
                if (v[0] <= 9 && v[0] >= 0 && v[1] <= 9 && v[0] >= 0) {
                    x = v[0];
                    y = v[1];
                    if (board.canMove(x, y)) {
                        return true;
                    } else {
                        fl_bad_move = true;
                    }
                } else {
                    fl_bad_move = true;
                }
            }
        }
        if (fl_bad_move) {
            std::cout << "Bad move!\n";
        }
    }
}

void StdioBoardView::runGame() {
    Player cur_player(player_O);
    int x, y;
    while (true) {
        printBoard();
        if (!readCell(x, y, cur_player))
            return;
        board.move(x, y, cur_player);
        game_status cur_state = board.getState(x, y, cur_player);
        if (cur_state != not_ended) {
            silence_mode = false;
            printBoard();
        }
        switch (cur_state) {
            case draw:
                std::cout << "Draw.\n";
                return;
            case X_wins:
                std::cout << "X wins!\n";
                return;
            case O_wins:
                std::cout << "O wins!\n";
                return;
            case not_ended:
                break;
        }
        cur_player.changePlayer();
    }
}

void StdioBoardView::printBoard() {
    if (silence_mode)
        return;
    std::cout << std::endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cell cur_cell = board.getCell(i, j);
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
