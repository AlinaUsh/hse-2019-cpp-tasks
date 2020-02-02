#include <iostream>
#include "Board.h"

Board::Board() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j] = cell_empty;
        }
    }
}

void Player::changePlayer() {
    if (player == player_O) {
        player = player_X;
        return;
    }
    player = player_O;
}

void Player::printRequest() {
    switch (player) {
        case player_X:
            std::cout << "X";
            break;
        case player_O:
            std::cout << "O";
            break;
    }
    std::cout << " move: ";
}

cell Board::getCell(int x, int y) const{
    return board[x][y];
}

bool Board::canMove(int x, int y) {
    if (x < 0 || y < 0 || x >= 10 || y >= 10)
        return false;
    if (getCell(x, y) != cell_empty)
        return false;
    return true;
}

void Board::move(int x, int y, Player cur_player) {
    if (cur_player.player == player_O)
        board[x][y] = cell_O;
    else
        board[x][y] = cell_X;
}

bool Board::sameInLine(int x, int y, int delta_x, int delta_y) {
    int cnt = 0;
    cell base_cell = getCell(x, y);
    if (base_cell == cell_empty) {
        return false;	
    }
    int new_x = x, new_y = y;
    while (new_x < 10 && new_x >= 0 && new_y < 10 && new_y >= 0 &&
            getCell(new_x, new_y) == base_cell) {
        new_x += delta_x, new_y += delta_y;
        cnt++;
    }
    new_x = x, new_y = y;
    delta_x *= -1, delta_y *= -1;
    while (new_x < 10 && new_x >= 0 && new_y < 10 && new_y >= 0 &&
           getCell(new_x, new_y) == base_cell) {
        new_x += delta_x, new_y += delta_y;
        cnt++;
    }
    cnt--;
    return (cnt >= 5);
}

game_status Board::getState(int x, int y, Player cur_player) {
    if (sameInLine(x, y, 1, 0) || sameInLine(x, y, 0, 1) || 
        sameInLine(x, y, 1, 1) || sameInLine(x, y, -1, 1)) {
        switch (cur_player.player) {
            case player_X:
                return X_wins;
            case player_O:
                return O_wins;
        }
    }
    int num_empty = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (getCell(i, j) == cell_empty)
                num_empty++;
        }
    }
    if (num_empty == 0)
        return draw;//все поля заняты
    return not_ended;
}
