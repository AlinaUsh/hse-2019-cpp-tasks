#ifndef HW_02_BOARDTEST_H
#define HW_02_BOARDTEST_H

#include "Test.h"
#include "../include/Board.h"

class BoardTest : public Test {
private:
    void testWin1();
    void testWin2();
    void testDraw();
    void testNotEnded();

    void testMove1();
    void testMove2();

    void testGetCellEmpty();
    void testGetCellX();
    void testGetCellO();

    void testSameInLine1();
    void testSameInLine2();

    void testChangePlayer1();
    void testChangePlayer2();

    // ...

public:
    void runAllTests() override;
};

#endif //HW_02_BOARDTEST_H
