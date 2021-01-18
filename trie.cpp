#include "trie.h"
#include <fstream>
#include <iostream>

void Trie::insert(std::string word) {
    if (is_valid(word)) {
        TrieNode *temp = &root;
        for (char level : word) {
            int index = char_to_index(level);
            if (!temp->children[index]) {
                temp->children[index] = new TrieNode;
            }
            temp = temp->children[index];
        }
        temp->end_of_word = true;
    }
}

std::vector<std::string> Trie::suggestions(std::string word) {
    std::vector<std::string> words;

    if(!is_valid(word))
        return words;

    TrieNode *temp = &root;
    int index;

    for (const char &letter : word) {
        index = char_to_index(letter);
        if (!temp->children[index])
            return words;
        temp = temp->children[index];
    }

    get_words(words, temp, word);
    return words;
}

Trie::Trie() {

}

void Trie::get_words(std::vector<std::string> &words, TrieNode *node, std::string word) {
    if (node->end_of_word)
        words.push_back(word);
    if (node->is_leaf())
        return;

    for (int i = 0; i < ALPHABETS_SIZE; i++) {
        if (node->children[i]) {
            word.push_back(index_to_char(i));
            get_words(words, node->children[i], word);
            word.pop_back();
        }
    }
}

Trie::Trie(std::string filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string word;
        while (file >> word)
            insert(word);
    } else {
        std::cout << filename << " not found" << std::endl;
    }
    file.close();
}

char index_to_char(int val) {
    return (char) (val + (int) 'a');
}

int char_to_index(char val) {
    return (int) val - (int) 'a';
}

bool is_valid(std::string &word) {
    return std::all_of(word.begin(), word.end(), [](unsigned char c){ return std::islower(c); });
}

bool TrieNode::is_leaf() {
    for (TrieNode *node : children) {
        if (node)
            return false;
    }
    return true;
}
