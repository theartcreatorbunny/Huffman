#include <iostream>

//#include "src/Huffman.h"
#include <string>
#include <map>
#include <iostream>
#include <vector>
#include "src/Node.cpp"
#include <queue>
int main() {
    using namespace std;
//    map<string,int> dict;
//
//    dict["test"]  = 12;
//    dict["test"]  = 13;
//    dict["not a test"]  = -1;
//    cout << dict.size() << '\n';
//
////    cout << dict.at("xx") << '\n';
//    cout << dict["xx"] << '\n';
//
//
//    const map<string,int>& const_map  = dict;
//
//    cout << const_map.at("test") << '\n';
//
//    for (const auto& pair : dict) {
//        cout << pair.first << " " << pair.second << '\n';
//    }
//
//    for (const auto& [key, val] : dict) {
//        cout << key << " " << val << '\n';
//    }

    string s = "test_abc_tost";
    map<char, int> freq;
    for (char c : s) {
//        cout << c << '\n';
        freq[c]++;
    }

    //std::string === std::vector<char>

    for (const auto& [sym, freq] : freq) {
//        cout<< sym << "= " << freq << '\n';
    }


    std::vector<Node> nodes;

    for (const auto& [sym, count] : freq) {
        nodes.emplace_back(Node(sym, count));
    }

    for (Node& node: nodes) {
//        std::cout << node.symbol << " " << node.count << '\t';
    }


    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> queue;

    queue.push(Node('t', 12, nullptr, nullptr));
    queue.push(Node('x', 6, nullptr, nullptr));
    queue.push(Node('a', 1, nullptr, nullptr));
    queue.push(Node('s', 0, nullptr, nullptr));

    cout << queue.top().symbol;


    return 0;
}