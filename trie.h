#ifndef AUTOCOMPLETE_TRIE_H
#define AUTOCOMPLETE_TRIE_H

#include <vector>
#include <string>

using namespace std;
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

    void insert(string);
    vector<string> suggestions(string);
    Trie();
};

#endif
