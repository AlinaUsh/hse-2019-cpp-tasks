#include "doctest.h"
#include "Huffman.h"

TEST_CASE ("HuffmanTree()") {
    HuffmanTree tree;
            CHECK(tree.getRoot());
            CHECK(tree.getRoot()->isLeaf());
}

TEST_CASE ("HuffmanTree(...), frequency.size() == 0") {
    std::map<char, int> frequency;
    HuffmanTree tree(frequency);
            CHECK(!tree.getRoot()->getLeft());
            CHECK(!tree.getRoot()->getRight());
            CHECK(!tree.getRoot()->getPrev());
            CHECK_EQ(tree.getRoot()->getVal(), 0);
}

TEST_CASE ("HuffmanTree(...), frequency.size() == 1") {
    std::map<char, int> frequency;
    frequency['a'] = 10;
    HuffmanTree tree(frequency);
            CHECK(tree.getRoot());
            CHECK(!tree.getRoot()->getRight());
            CHECK(tree.getRoot()->getLeft());
            CHECK(tree.getRoot()->getLeft()->isLeaf());
            CHECK_EQ(tree.getRoot()->getLeft()->getVal(), 'a');
            CHECK(!tree.getRoot()->getPrev());
}

TEST_CASE ("HuffmanTree(...), frequency.size() == 2") {
    std::map<char, int> frequency;
    frequency['a'] = 10;
    frequency['b'] = 15;
    HuffmanTree tree(frequency);
            SUBCASE ("root") {
                CHECK(tree.getRoot());
                CHECK(!tree.getRoot()->getPrev());
    }
            SUBCASE ("left son") {
                CHECK(tree.getRoot()->getLeft());
                CHECK(tree.getRoot()->getLeft()->isLeaf());
                CHECK_EQ(tree.getRoot()->getLeft()->getVal(), 'a');
    }
            SUBCASE ("right son") {
                CHECK(tree.getRoot()->getRight());
                CHECK(tree.getRoot()->getRight()->isLeaf());
                CHECK_EQ(tree.getRoot()->getRight()->getVal(), 'b');
    }
}

TEST_CASE ("HuffmanTree(...), frequency.size() == 3") {
    std::map<char, int> frequency;
    frequency['a'] = 100;
    frequency['b'] = 1;
    frequency['c'] = 2;
    HuffmanTree tree(frequency);
            SUBCASE ("root") {
                CHECK(tree.getRoot());
                CHECK(!tree.getRoot()->getPrev());
    }
            CHECK(tree.getRoot()->getLeft());
            CHECK(tree.getRoot()->getLeft()->getLeft());
            CHECK(tree.getRoot()->getLeft()->getRight());
            CHECK_EQ(tree.getRoot()->getLeft()->getLeft()->getVal(), 'b');
            CHECK_EQ(tree.getRoot()->getLeft()->getRight()->getVal(), 'c');
            CHECK(tree.getRoot()->getLeft()->getLeft()->isLeaf());
            CHECK(tree.getRoot()->getLeft()->getRight()->isLeaf());

            CHECK(tree.getRoot()->getRight());
            CHECK(tree.getRoot()->getRight()->isLeaf());
            CHECK_EQ(tree.getRoot()->getRight()->getVal(), 'a');

}