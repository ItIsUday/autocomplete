#ifndef AUTOCOMPLETE_TRIE_H
#define AUTOCOMPLETE_TRIE_H

#include <vector>
#include <string>

const int ALPHABETS_SIZE = 26;

char int_to_char(int);
int char_to_int(char);

class TrieNode {
public:
    bool end_of_word;
    TrieNode *children[ALPHABETS_SIZE];

    TrieNode();
};

class Trie {
public:
    TrieNode *root;

    void insert(std::string);
    std::vector<std::string> suggestions(std::string);
    Trie();
};

#endif
