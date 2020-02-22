#ifndef LAB_11_MATRIX_H
#define LAB_11_MATRIX_H

#include "MatrixException.h"

#include <string>
#include <vector>

class Matrix {
public:
    Matrix(){};
    Matrix(int h, int w);
    ~Matrix() = default;

    void readMatrix(std::string filename);
    void printMatrix();
    void printElem(int x, int y);

    Matrix& operator=(const Matrix& m);
    Matrix& operator+=(const Matrix& m);
    Matrix& operator*=(const Matrix& m);
private:
    int height = 0;
    int width = 0;
    std::vector<std::vector<int> > matrix;
};
#endif //LAB_11_MATRIX_H
