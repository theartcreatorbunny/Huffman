//
// Created by erixon on 21.03.2020.
//

#include "Huffman.h"
#include <map>
#include <vector>
#include <queue>
void Huffman::BuildTree(const std::string& s) {
    std::map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    auto comparator = [](Node* lhs, Node* rhs) {
        if (lhs -> count == rhs -> count) {
            return lhs->symbol != 0;//priority to non-symbol node
        }
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
        queue.pop();
        Node* new_node = new Node(0, lesser_node->count + greater_node->count, greater_node, lesser_node);
        queue.push(new_node);
    }

    root = queue.top();

    assignCodesToNodes(root);
}


std::string Huffman::encode(const std::string &s) {
    BuildTree(s);
    std::string encoded_string;
    for (char c: s) {
        encoded_string += codeDictionary[c];
    }
    return encoded_string;
}

void Huffman::assignCodesToNodes(Node *node) {
    if (node->left != nullptr) {
        node->left->code = node->code + "0";
        assignCodesToNodes(node->left);
    }
    if (node -> right != nullptr) {
        node->right-> code = node->code + "1";
        assignCodesToNodes(node->right);
    }

    if (node->symbol != 0) {
        codeDictionary[node->symbol] = node->code;
    }
}

std::string Huffman::decode(const std::string &s) {
    std::string decoded_string;
    Node* node = root;
    for (char c : s) {
        //every c either 1 or 0
        if (c == '0') {
            node = node ->left;
            if (node -> symbol != 0) {
                decoded_string += node->symbol;
                node = root;
            }
        }
        else if (c == '1') {
            node = node -> right;
            if (node -> symbol != 0) {
                decoded_string += node ->symbol;
                node = root;
            }
        }
    }
    return decoded_string;
}

