#include <iostream>
#include <cstring>
#include "../include/StdioBoardView.h"
#include "../include/Board.h"

int main(int argc, char *argv[]) {
    Board new_board;
    StdioBoardView new_game(new_board);
    if (argc >= 2 && strcmp(argv[1], "silent") == 0) {
        new_game.setSilenceMode();
    }
    new_game.runGame();
    return 0;
}