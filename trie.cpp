#include "trie.h"

void Trie::insert(std::string word) {

}

std::vector<std::string> Trie::suggestions(std::string word) {
    return std::vector<std::string>();
}

Trie::Trie() {

}

char index_to_char(int val) {
    return (char) (val + (int) 'a');
}

int char_to_index(char val) {
    return (int) val - (int) 'a';
}
