//
// Created by erixon on 21.03.2020.
//

#ifndef GRIGRORY_HUFFMAN_CODE_HUFFMAN_H
#include <string>
#include "Node.cpp"
#include <map>
#define GRIGRORY_HUFFMAN_CODE_HUFFMAN_H



class Huffman {
public:
    std::string encode(const std::string& s);
    std::string decode(const std::string& s);

private:
    Node* root;
    std::map<char,std::string> codeDictionary;
    void BuildTree(const std::string& s);
    void assignCodesToNodes(Node* node);
};


#endif //GRIGRORY_HUFFMAN_CODE_HUFFMAN_H
