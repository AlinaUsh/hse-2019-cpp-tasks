#include <iostream>
#include <string>

#include "../include/Test.h"

int Test::totalNum;
int Test::failedNum;

bool Test::showFinalResult() {
    if (Test::failedNum == 0) {
        std::cout << "All test passed\n";
        return true;
    }
    std::cout <<"failed " << Test::failedNum << " of " << Test::totalNum <<" tests.\n";
    return false;
}

void Test::check(bool expr, const char *func, const char  *filename, size_t lineNum) {
    if (!expr) {
        std::cout << "test failed: " << std::string(func) << " in "
                  << std::string(filename) << ":" << (int)lineNum << '\n';
        Test::failedNum ++;
    }
    Test::totalNum++;
}



