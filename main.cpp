#include <iostream>
#include <readline/history.h>
#include <readline/readline.h>
#include "trie.h"

#define GREEN "\e[1;32m"
#define RESET "\e[0m"

Trie trie;

char *completion_generator(const char *text, int state) {
    static std::vector<std::string> matches;
    static size_t match_index = 0;

    if (state == 0) {
        matches.clear();
        match_index = 0;
        matches = trie.suggestions(std::string(text));
    }

    if (match_index >= matches.size())
        return nullptr;
    else
        return strdup(matches[match_index++].c_str());
}

char **completer(const char *text, int, int) {
    rl_attempted_completion_over = 1;
    return rl_completion_matches(text, completion_generator);
}

int main() {
    std::cout << "\t\tWelcome to autocompletion program!!" << std::endl;
    std::cout << "Press <TAB> for autocompletion and press <TAB> twice for displaying all matching words" << std::endl;

    trie = Trie("words.txt");
    rl_attempted_completion_function = completer;
    char *buffer;
    char prompt[] = GREEN ">>> " RESET;

    while ((buffer = readline(prompt)) != nullptr) {
        if (strlen(buffer) > 0)
            add_history(buffer);
        std::cout << '[' << buffer << ']' << std::endl;
        free(buffer);
    }

    return 0;
}
