#include "CLI.h"

#include <utility>
#include <iostream>

CLIException::CLIException(std::string new_message) {
    message = std::move(new_message);
}

const char *CLIException::what() const noexcept {
    return message.c_str();
}

void CLI::parse(int argc, char **argv) {
    for (std::size_t i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "-c")) {
            archiving = true;
            continue;
        }
        if (!strcmp(argv[i], "-u")) {
            dearchiving = true;
            continue;
        }
        if (!strcmp(argv[i], "-f") || !strcmp(argv[i], "--file")) {
            input_file_fl = true;
            i++;
            if (i >= argc) {
                input_file_fl = false;
            } else {
                input_file = argv[i];
            }
            continue;
        }
        if (!strcmp(argv[i], "-o") || !strcmp(argv[i], "--output")) {
            output_file_fl = true;
            i++;
            if (i >= argc) {
                output_file_fl = false;
            } else {
                output_file = argv[i];
            }
            continue;
        }
        throw CLIException("Unknown argument: " + static_cast<std::string>(argv[i]));
    }
    if (!input_file_fl) {
        throw  CLIException("No input file");
    }
    if (!output_file_fl) {
        throw CLIException("No output file");
    }
    if (!archiving && !dearchiving) {
        throw CLIException("No action");
    }
    if (archiving && dearchiving) {
        throw CLIException("Choose only one action");
    }
}

FileException::FileException(std::string new_message) {
    message = "Error in" + std::move(new_message);
}
const char *FileException::what() const noexcept {
    return message.c_str();
}
