#include "trie.h"

void Trie::insert(std::string word)
{
    TrieNode *temp = &root;

    for(char level : word)
    {
        int index = char_to_index(level);

        if(!temp->children[index])
        {
            temp->children[index] = new TrieNode;
        }
        temp = temp->children[index];
    }

    temp->end_of_word = true;
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
