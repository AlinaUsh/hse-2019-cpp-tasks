#include "matrix.h"
#include <iostream>
#include <fstream>
#include <cstring>

Matrix::Matrix(int h, int w): height(h), width(w){
    try {
        matrix.resize(height);
    } catch (const std::bad_alloc&) {
        throw MatrixException("Unable to allocate memory.");
    }
    for (int i = 0; i < height; i++) {
        try {
            matrix[i].resize(width, 0);
        } catch (const std::bad_alloc&) {
            throw MatrixException("Unable to allocate memory.");
        }
    }
};

void Matrix::readMatrix(std::string filename) {
    int h, w;
    std::ifstream in;
    in.open(filename);
    if (!in.is_open()) {
        throw MatrixException("LOAD: unable to open file.");
    }
    if (!(in >> h)) {
        throw MatrixException("LOAD: invalid file format.");
    }
    if (!(in >> w)) {
        throw MatrixException("LOAD: invalid file format.");
    }
    *this = Matrix(h, w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (!(in >> matrix[i][j])) {
                throw MatrixException("LOAD: invalid file format.");
            }
        }
    }
    in.close();
}

void Matrix::printMatrix() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

void Matrix::printElem(int x, int y) {
    if (x < 0 || y < 0 || x >= height || y >= width) {
        throw MatrixException("ACCESS: bad index.");
    }
    std::cout << matrix[x][y] << '\n';
}

Matrix& Matrix::operator=(const Matrix& m) {
    if (this == &m) return *this;
    Matrix c = m;
    height = c.height;
    width = c.width;
    std::swap(matrix, c.matrix);
    return *this;
}

Matrix& Matrix::operator+=(const Matrix& m) {
    if (m.height != height || m.width != width) {
        throw MatrixException("ADD: dimensions do not match.");
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            matrix[i][j] += m.matrix[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator*=(const Matrix& m) {
    if (width != m.height)
        throw MatrixException("MUL: #arg1.columns != #arg2.rows.");
    Matrix c(height, m.width);
    for (int i = 0; i < height; i++)
        for (int j = 0; j < m.width; j++) {
            for (int k = 0; k < width; k++)
                c.matrix[i][j] += matrix[i][k] * m.matrix[k][j];
        }
    *this = c;
    return *this;
}