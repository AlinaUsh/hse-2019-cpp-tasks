#ifndef LAB_11_MATRIXEXCEPTION_H
#define LAB_11_MATRIXEXCEPTION_H

#include <string>

class MatrixException : public std::exception {
public:
    MatrixException(std::string new_message);

    std::string what();

    std::string message;
};

#endif //LAB_11_MATRIXEXCEPTION_H
