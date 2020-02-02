#include "BoardTest.h"

int main() {
    BoardTest bt;
    bt.runAllTests();
    if (!bt.showFinalResult()) {
        return 1;
    }
    return 0;
}
