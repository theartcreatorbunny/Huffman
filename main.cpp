#include <iostream>

#include "src/Huffman.h"
#include <string>
int main() {
    using namespace std;
    Huffman huffman;
    string s = "etoahutehautahoutnehaouthaeogueaohp.;rcagunjtehau";
    const std::string& encoded_string = huffman.encode(s);
    cout << encoded_string << '\n';

    const std::string& decoded_string = huffman.decode(encoded_string);
    cout << decoded_string << '\n';
    return 0;
}