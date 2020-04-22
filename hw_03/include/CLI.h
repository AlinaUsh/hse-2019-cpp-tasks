#ifndef HW_03_CLI_H
#define HW_03_CLI_H

#include <bits/exception.h>
#include <string>
#include <cstring>

class CLIException : public std::exception {
public:
    explicit CLIException(std::string new_message);

    const char* what() const noexcept override;

    std::string message;
};

class CLI {
public:
    CLI() = default;
    bool archiving = false;
    bool dearchiving = false;
    bool input_file_fl = false;
    bool output_file_fl = false;
    std::string input_file;
    std::string output_file;

    void parse(int argc, char** argv);
};

class FileException : public std::exception {
public:
    explicit FileException(std::string new_message);

    const char* what() const noexcept override;

    std::string message = "Error in";
};

#endif //HW_03_CLI_H
