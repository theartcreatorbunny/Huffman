//
// Created by erixon on 21.03.2020.
//

#include "Huffman.h"
#include <map>
#include <vector>
#include "Node.cpp"
#include <iostream>
#include <queue>
void Huffman::BuildTree(const std::string& s) {

    //abbbcddbcccda
    std::map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    auto comparator = [](Node* lhs, Node* rhs) {
        return lhs->count > rhs -> count;
    };

    std::priority_queue<Node*, std::vector<Node*>, decltype(comparator)> queue(comparator);
    for (const auto& [sym, count] : freq) {
        Node* node = new Node(sym, count, nullptr, nullptr);
        queue.push(node);
    }

    while(queue.size() > 1) {
        Node* lesser_node = queue.top();
        queue.pop();
        Node* greater_node = queue.top();
        queue.top();
        Node* new_node = new Node(0, lesser_node->count + greater_node->count, greater_node, lesser_node);
        queue.push(new_node);
    }

    root = queue.top();
}


std::string Huffman::encode(const std::string &s) {

    BuildTree(s);
}