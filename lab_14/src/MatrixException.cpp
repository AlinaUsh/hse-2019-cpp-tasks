#include "MatrixException.h"

MatrixException::MatrixException(std::string new_message) {
    message = new_message;
}

std::string MatrixException::what() {
    return message;
}
