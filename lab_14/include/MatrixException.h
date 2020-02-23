#ifndef LAB_11_MATRIXEXCEPTION_H
#define LAB_11_MATRIXEXCEPTION_H

#include <string>

class MatrixException : public std::exception {
public:
    explicit MatrixException(std::string new_message);

    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override;

    std::string message;
};

#endif //LAB_11_MATRIXEXCEPTION_H
