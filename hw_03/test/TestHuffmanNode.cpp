#include "doctest.h"
#include "Huffman.h"

TEST_CASE ("HuffmanNode()") {
    auto *node = new HuffmanNode();
            CHECK(!node->getLeft());
            CHECK(!node->getRight());
            CHECK(!node->getPrev());
            CHECK(node->getVal() == 0);
            CHECK(node->isLeaf());
}

TEST_CASE ("HuffmanNode('a', nullptr, nullptr, nullptr)") {
    auto *node = new HuffmanNode('a', nullptr, nullptr, nullptr);
            CHECK(!node->getLeft());
            CHECK(!node->getRight());
            CHECK(node->getVal() == 'a');
            CHECK(node->isLeaf());
}

TEST_CASE ("HuffmanNode('a', left, nullptr, nullptr)") {
    auto *left_son = new HuffmanNode('l', nullptr, nullptr, nullptr);
    auto *node = new HuffmanNode('a', left_son, nullptr, nullptr);
            CHECK_EQ(node->getVal(), 'a');
            CHECK(node->getLeft());
            CHECK_EQ(node->getLeft()->getVal(), 'l');
            CHECK(node->getLeft()->getPrev());
            CHECK_EQ(node->getLeft()->getPrev()->getVal(), 'a');
            CHECK_EQ(node->getId(), node->getLeft()->getPrev()->getId());
            CHECK(!node->isLeaf());
            CHECK(!node->getRight());
}

TEST_CASE ("HuffmanNode('a', nullptr, right, nullptr)") {
    auto *right_son = new HuffmanNode('r', nullptr, nullptr, nullptr);
    auto *node = new HuffmanNode('a', nullptr, right_son, nullptr);
            CHECK_EQ(node->getVal(), 'a');
            CHECK(node->getRight());
            CHECK_EQ(node->getRight()->getVal(), 'r');
            CHECK(right_son->getPrev());
            CHECK_EQ(right_son->getPrev()->getVal(), 'a');
            CHECK_EQ(node->getId(), right_son->getPrev()->getId());
            CHECK(!node->isLeaf());
            CHECK(!node->getPrev());
            CHECK(!node->getLeft());
}

TEST_CASE ("HuffmanNode('a', left, right, nullptr)") {
    auto *left_son = new HuffmanNode('l', nullptr, nullptr, nullptr);
    auto *right_son = new HuffmanNode('r', nullptr, nullptr, nullptr);
    auto *node = new HuffmanNode('a', left_son, right_son, nullptr);
    SUBCASE("Left") {
                CHECK_EQ(node->getVal(), 'a');
                CHECK(node->getLeft());
                CHECK_EQ(node->getLeft()->getVal(), 'l');
                CHECK(left_son->getPrev());
                CHECK_EQ(left_son->getPrev()->getVal(), 'a');
                CHECK_EQ(node->getId(), node->getLeft()->getPrev()->getId());
    }
    SUBCASE("Right") {
                CHECK(node->getRight());
                CHECK_EQ(node->getRight()->getVal(), 'r');
                CHECK(right_son->getPrev());
                CHECK_EQ(right_son->getPrev()->getVal(), 'a');
                CHECK_EQ(node->getId(), node->getRight()->getPrev()->getId());
    }
            CHECK(!node->getPrev());
            CHECK(!node->isLeaf());
}