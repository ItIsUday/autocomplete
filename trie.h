#ifndef AUTOCOMPLETE_TRIE_H
#define AUTOCOMPLETE_TRIE_H

#include <vector>
#include <string>

const int ALPHABETS_SIZE = 26;

char index_to_char(int);
int char_to_index(char);
bool is_valid(std::string &);

class TrieNode {
public:
    bool end_of_word = false;
    TrieNode *children[ALPHABETS_SIZE]{nullptr};

    bool is_leaf();
};

class Trie {
    static void get_words(std::vector<std::string> &, TrieNode *, std::string);
public:
    TrieNode root = TrieNode();

    void insert(std::string);
    std::vector<std::string> suggestions(std::string);
    Trie();
    Trie(std::string);
};

#endif
