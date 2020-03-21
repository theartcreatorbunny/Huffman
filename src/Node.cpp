//
// Created by erixon on 21.03.2020.
//

struct Node {
    char symbol;
    int count;
    Node(char symbol, int count, Node* left, Node* right):
        symbol(symbol), count(count), left(left), right(right){}
    Node *left;
    Node *right;

    ~Node() {
        delete left;
        delete right;
    }
};
