#ifndef HW_03_HUFFMANARCHIVER_H
#define HW_03_HUFFMANARCHIVER_H

#include "Huffman.h"
#include <fstream>

class HuffmanArchiver {
public:
    HuffmanArchiver() = default;

    void createArchive(std::istream& in, std::ostream& out);
    void unpackArchive(std::istream& in, std::ostream& out);

    void printDiff() const;

    void readTable(std::istream& in, std::map<char, int>& frequency);
    void putTable(std::ostream& out, const std::map<char, int>& frequency);

private:
    void putCode(std::ostream& out, HuffmanNode* node);
    void putBit(std::ostream& out, int bit, bool flush);

    int start_size = 0;
    int result_size = 0;
    int table_size = 0;
};

class DecodingException : public std::exception {
public:
    explicit DecodingException();

    const char* what() const noexcept override;

    std::string message;
};

#endif //HW_03_HUFFMANARCHIVER_H
