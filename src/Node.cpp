//
// Created by erixon on 21.03.2020.
//
#include <string>

struct Node {
    char symbol;
    int count;
    std::string code;
    Node(char symbol, int count, Node* left, Node* right):
        symbol(symbol), count(count), left(left), right(right){}
    Node *left;
    Node *right;

    ~Node() {
        delete left;
        delete right;
    }
};
