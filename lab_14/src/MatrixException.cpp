#include "MatrixException.h"
#include <cstring>

MatrixException::MatrixException(std::string new_message) {
    message = new_message;
}

const char* MatrixException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT {
    return message.c_str();
}
