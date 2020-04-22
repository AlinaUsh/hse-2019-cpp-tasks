#include <iostream>
#include "HuffmanArchiver.h"

void HuffmanArchiver::printDiff() const {
    std::cout << start_size << '\n'
              << result_size << '\n'
              << table_size << '\n';
    std::cout.flush();
}

DecodingException::DecodingException() {
    message = "Error while decoding";
}

const char *DecodingException::what() const noexcept {
    return message.c_str();
}

void HuffmanArchiver::readTable(std::istream &in, std::map<char, int> &frequency) {
    int size = 0;
    in.read((char *) &size, 4);
    for (int i = 0; i < size; i++) {
        char symbol = 0;
        in.read(&symbol, 1);
        int count = 0;
        in.read((char *) &count, 4);
        frequency[symbol] = count;
    }
    table_size = size * 5 + 4;
}

void HuffmanArchiver::putTable(std::ostream &out, const std::map<char, int> &frequency) {
    int size = frequency.size();
    out.write((char *) &size, 4);
    for (auto &symbol : frequency) {
        out.write(&symbol.first, 1);
        out.write((char *) &symbol.second, 4);
    }
    table_size = size * 5 + 4;
}

void HuffmanArchiver::createArchive(std::istream &in, std::ostream &out) {
    in.seekg(0, std::istream::end);
    int len = in.tellg();
    start_size = len;
    in.seekg(0, std::istream::beg);
    std::map<char, int> frequency;
    char symbol = 0;
    for (int i = 0; i < len; i++) {
        in.get(symbol);
        frequency[symbol]++;
    }
    HuffmanTree tree(frequency);
    putTable(out, frequency);
    out.write((char *) &len, 4);
    table_size += 4;

    in.seekg(0, std::istream::beg);
    for (int i = 0; i < len; i++) {
        in.get(symbol);
        putCode(out, tree.getNode(symbol));
    }
    putBit(out, 0, true);
    printDiff();
}

void HuffmanArchiver::putCode(std::ostream &out, HuffmanNode *node) {
    if (!node->getPrev()) {
        return;
    }
    putCode(out, node->getPrev());
    putBit(out, (node->getPrev()->getLeft() == node) ? 0 : 1, false);
}

void HuffmanArchiver::putBit(std::ostream &out, int bit, bool flush) {
    static char buff = 0;
    static int cur_pos = 0;
    if (flush) {
        if (cur_pos) {
            out.write(&buff, 1);
            result_size++;
        }
        return;
    }
    buff |= bit << cur_pos;
    cur_pos = (cur_pos + 1) & 7;
    if (!cur_pos) {
        out.write(&buff, 1);
        result_size++;
        buff = 0;
    }
}

void HuffmanArchiver::unpackArchive(std::istream &in, std::ostream &out) {
    std::map<char, int> frequency;
    readTable(in, frequency);
    HuffmanTree tree(frequency);
    HuffmanNode *node = tree.getRoot();
    int len = 0;
    in.read((char *) &len, 4);
    table_size += 4;

    char byte = 0;
    while (len) {
        if (!in.good()) {
            throw DecodingException();
        }
        start_size++;
        in.read(&byte, 1);
        for (int i = 0; i < 8 && len; i++) {
            int bit = (byte & (1 << i)) > 0;
            if (bit) {
                if (!node->getRight() && !node->isLeaf()) {
                    throw DecodingException();
                }
                if (!node->getRight()) {
                    node = tree.getRoot();
                }
                node = node->getRight();
                if (node->isLeaf()) {
                    out.put(node->getVal());
                    result_size++;
                    len--;
                }
            } else {
                if (!node->getLeft() && !node->isLeaf()) {
                    throw DecodingException();
                }
                if (!node->getLeft()) {
                    node = tree.getRoot();
                }
                node = node->getLeft();
                if (node->isLeaf()) {
                    out.put(node->getVal());
                    result_size++;
                    len--;
                }
            }
        }
    }
    printDiff();
}
