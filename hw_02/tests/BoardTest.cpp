#include "BoardTest.h"

void BoardTest::testDraw() {
    Board b;
    Player player_1(player_X);
    Player player_2(player_O);
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < 10; j++) {
                if (j % 4 <= 1) {
                    b.move(i, j, player_1);
                } else {
                    b.move(i, j, player_2);
                }
            }
        } else {
            for (int j = 0; j < 10; j++) {
                if (j % 4 <= 1) {
                    b.move(i, j, player_2);
                } else {
                    b.move(i, j, player_1);
                }
            }
        }
    }
    DO_CHECK(b.getState(3, 3, player_1) == draw);
}

void BoardTest::testWin1() {
    Board b;
    Player player_1(player_X);
    Player player_2(player_O);
    for (int i = 0; i < 5; i++) {
        b.move(0, i, player_1);
    }
    for (int i = 0; i < 4; i++) {
        b.move(1, i, player_2);
    }
    DO_CHECK(b.getState(0, 2, player_1) == X_wins);
}


void BoardTest::testWin2() {
    Board b;
    Player player_1(player_X);
    Player player_2(player_O);
    for (int i = 0; i < 4; i++) {
        b.move(i, i, player_1);
    }
    for (int i = 0; i < 5; i++) {
        b.move(9 - i, 7, player_2);
    }
    DO_CHECK(b.getState(9, 7, player_2) == O_wins);
}

void BoardTest::testNotEnded() {
    Board b;
    Player player_1(player_X);
    Player player_2(player_O);
    b.move(0, 0, player_1);
    b.move(5, 5, player_2);
    DO_CHECK(b.getState(0, 0, player_1) == not_ended);
}

void BoardTest::testMove1() {
    Board board;
    Player player(player_O);
    board.move(0, 0, player);
    DO_CHECK(!board.canMove(0, 0));
}

void BoardTest::testMove2() {
    Board board;
    Player player(player_O);
    board.move(0, 0, player);
    DO_CHECK(board.canMove(1, 1));
}

void BoardTest::testGetCellEmpty() {
    Board board;
    DO_CHECK(board.getCell(1, 2) == cell_empty);
}

void BoardTest::testGetCellX() {
    Board board;
    Player player(player_X);
    board.move(1, 2, player);
    DO_CHECK(board.getCell(1, 2) == cell_X);
}

void BoardTest::testGetCellO() {
    Board board;
    Player player(player_O);
    board.move(5, 6, player);
    DO_CHECK(board.getCell(5, 6) == cell_O);
}

void BoardTest::testSameInLine1() {
    Board board;
    Player player(player_O);
    for (int i = 0; i < 7; i++) {
        board.move(2, i, player);
    }
    DO_CHECK(board.sameInLine(2, 3, 0, 1));
}

void BoardTest::testSameInLine2() {
    Board board;
    Player player(player_O);
    for (int i = 0; i < 7; i++) {
        board.move(2, i, player);
    }
    DO_CHECK(!board.sameInLine(2, 3, 1, 0));
}

void BoardTest::testChangePlayer1() {
    Player player(player_O);
    player.changePlayer();
    DO_CHECK(player.player == player_X);
}

void BoardTest::testChangePlayer2() {
    Player player(player_X);
    player.changePlayer();
    DO_CHECK(player.player == player_O);
}

void BoardTest::runAllTests() {
    testWin1();
    testWin2();
    testDraw();

    testNotEnded();
    testMove1();
    testMove2();

    testGetCellEmpty();
    testGetCellX();
    testGetCellO();

    testSameInLine1();
    testSameInLine2();

    testChangePlayer1();
    testChangePlayer2();
}

