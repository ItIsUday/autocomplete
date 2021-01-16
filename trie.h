#ifndef AUTOCOMPLETE_TRIE_H
#define AUTOCOMPLETE_TRIE_H

#include <vector>
#include <string>

const int ALPHABETS_SIZE = 26;

char index_to_char(int);
int char_to_index(char);

class TrieNode {
public:
    bool end_of_word = false;
    TrieNode *children[ALPHABETS_SIZE]{};
};

class Trie {
public:
    TrieNode root = TrieNode();

    void insert(std::string);
    std::vector<std::string> suggestions(std::string);
    Trie();
};

#endif
