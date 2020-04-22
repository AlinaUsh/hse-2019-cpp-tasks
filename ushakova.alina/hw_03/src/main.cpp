#include <iostream>
#include "CLI.h"
#include "HuffmanArchiver.h"

void checkFiles(std::ifstream& in, std::ofstream& out) {
    if (!in.good()) {
        throw FileException("input file");
    }
    if (!out.good()) {
        throw FileException("output file");
    }
}

int main(int argc, char** argv) {
    CLI args;
    try {
        args.parse(argc, argv);
    } catch (CLIException& e) {
        std::cout << e.what() << '\n';
        return 1;
    }

    HuffmanArchiver archiver;
    std::ifstream in;
    std::ofstream out;

    try {
        if (args.archiving) {
            in = std::ifstream(static_cast<std::string>(args.input_file), std::ifstream::in);
            out = std::ofstream(static_cast<std::string>(args.output_file), std::ofstream::binary);
            checkFiles(in, out);
            archiver.createArchive(in, out);
        } else {
            in = std::ifstream(static_cast<std::string>(args.input_file), std::ifstream::binary);
            out = std::ofstream(static_cast<std::string>(args.output_file), std::ofstream::out);
            checkFiles(in, out);
            archiver.unpackArchive(in, out);
        }
        in.close();
        out.close();
    } catch (const std::exception& e) {
        std::cout << e.what() << '\n';
        in.close();
        out.close();
        return 1;
    }
    return 0;
}
