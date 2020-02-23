#include "matrix.h"
#include "MatrixException.h"
#include <iostream>
#include <string>

int main() {
    std::string str;
    Matrix matrixList[10];
    char ch;
    int reg;
    while (std::cin >> str) {
        try {
            if (str == "exit") {
                return 0;
            }
            if (str == "load") {
                std::string filename;
                std::cin >> ch >> reg >> filename;
                matrixList[reg].readMatrix(filename);
                continue;
            }
            if (str == "elem") {
                int x, y;
                std::cin >> ch >> reg >> x >> y;
                matrixList[reg].printElem(x, y);
                continue;
            }
            if (str == "print") {
                std::cin >> ch >> reg;
                matrixList[reg].printMatrix();
                continue;
            }
            if (str == "add") {
                int reg1, reg2;
                std::cin >> ch >> reg1 >> ch >> reg2;
                matrixList[reg1] += matrixList[reg2];
                continue;
            }
            if (str == "mul") {
                int reg1, reg2;
                std::cin >> ch >> reg1 >> ch >> reg2;
                matrixList[reg1] *= matrixList[reg2];
                continue;
            }
        } catch (MatrixException except) {
            std::cout << except.what() << '\n';
        }
    }
    return 0;
}
