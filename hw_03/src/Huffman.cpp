#include <set>
#include <iostream>
#include "Huffman.h"

HuffmanTree::HuffmanTree() {
    root = new HuffmanNode();
}

HuffmanTree::~HuffmanTree() {
    delete (root);
}

HuffmanTree::HuffmanTree(const std::map<char, int> &frequency) {
    auto cmp = [](const std::pair<int, HuffmanNode *> &p1, const std::pair<int, HuffmanNode *> &p2) -> bool {
        if (p1.first != p2.first) {
            return (p1.first < p2.first);
        }
        return p1.second->getId() < p2.second->getId();
    };
    std::set<std::pair<int, HuffmanNode *>, decltype(cmp)> storage(cmp);
    for (auto &symbol : frequency) {
        auto *node = new HuffmanNode(symbol.first, nullptr, nullptr, nullptr);
        storage.insert({symbol.second, node});
        pos[symbol.first] = node;
    }
    if (storage.empty()) {
        root = new HuffmanNode();
        return;
    }

    if (storage.size() == 1) {
        root = new HuffmanNode();
        root->left = storage.begin()->second;
        root->left->prev = root;
        return;
    }

    while (storage.size() > 1) {
        auto l = *storage.begin();
        storage.erase(storage.begin());
        auto r = *storage.begin();
        storage.erase(storage.begin());
        auto *new_node = new HuffmanNode(0, l.second, r.second, nullptr);
        storage.insert({l.first + r.first, new_node});
    }
    root = storage.begin()->second;
}

HuffmanNode::HuffmanNode() : val(0), left(nullptr), right(nullptr), prev(nullptr) {
    id = getNextId();
};

HuffmanNode::HuffmanNode(char val, HuffmanNode *left, HuffmanNode *right, HuffmanNode *prev) :
        val(val), left(left), right(right), prev(prev) {
    id = getNextId();
    if (left) {
        left->prev = this;
    }
    if (right) {
        right->prev = this;
    }
}

int HuffmanNode::getNextId() const {
    static int cur_id = -1;
    cur_id++;
    return cur_id;
}

HuffmanNode::~HuffmanNode() {
    if (left) {
        delete left;
    }
    if (right) {
        delete right;
    }
}

