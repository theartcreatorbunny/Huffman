//
// Created by erixon on 21.03.2020.
//

#ifndef GRIGRORY_HUFFMAN_CODE_HUFFMAN_H
#define GRIGRORY_HUFFMAN_CODE_HUFFMAN_H

#include <string>
#include "Node.cpp"

class Huffman {
public:
    std::string encode(const std::string& s);
    std::string decode(const std::string& s);

private:
    Node* root;
    void BuildTree(const std::string& s);
};


#endif //GRIGRORY_HUFFMAN_CODE_HUFFMAN_H
