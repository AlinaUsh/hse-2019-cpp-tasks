#ifndef HW_03_HUFFMAN_H
#define HW_03_HUFFMAN_H

#include <map>

class HuffmanNode;

class HuffmanTree;

class HuffmanNode {
    friend class HuffmanTree;
public:
    HuffmanNode();
    ~HuffmanNode();
    HuffmanNode(char val, HuffmanNode *left, HuffmanNode *right, HuffmanNode *prev);

    char getVal() const { return val; }
    HuffmanNode* getLeft() const { return left; }
    HuffmanNode* getRight() const { return right; }
    HuffmanNode* getPrev() const { return prev; }
    int getId() const { return id; }
    bool isLeaf() { return (!left && !right); }

private:
    int getNextId() const;

    char val = 0;
    int id;
    HuffmanNode *left = nullptr;
    HuffmanNode *right = nullptr;
    HuffmanNode *prev = nullptr;
};

class HuffmanTree {
public:
    HuffmanTree();
    HuffmanTree(const std::map<char, int> &frequency);
    ~HuffmanTree();

    HuffmanNode* getNode(char symbol) { return pos[symbol]; }
    HuffmanNode* getRoot() { return root; }

private:
    HuffmanTree(const HuffmanTree& other);
    HuffmanTree operator=(const HuffmanTree& other);

    HuffmanNode* root;
    std::map<char, HuffmanNode*> pos;
};

#endif //HW_03_HUFFMAN_H
