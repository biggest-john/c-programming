#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nlp_engine.h"


DictionaryEntry lexicon[MAX_WORDS];
int total_word_count = 0;

char token_array [MAX_TOKENS][MAX_TOKEN_LEN];
int token_count = 0;

int load_dictionary(const char *file_name) {
    // this function read our
    FILE *dictionary = fopen(file_name, "r");
    if (dictionary == NULL) {
        sys_error("Problem while opening up the dictionary.");
    }
    while (fscanf(dictionary," %128[^|]|%128[^|]|%128[^|]|%2048[^\n]\n",
        lexicon[total_word_count].word,
        lexicon[total_word_count].pos,
        lexicon[total_word_count].ipa,
        lexicon[total_word_count].gloss) == 4) {

        total_word_count++;

        if (total_word_count >= MAX_WORDS) {
            // control: avoid loading entries in to the memory more than available space can permit!
            fprintf(stderr, "capacity of in-memory lexicon has been exceeded,"
                            "\nloading has been truncated at %d entries\n", MAX_WORDS);
            break;
        }
    }
    fclose(dictionary);
    return total_word_count;
}

int main() {
    // load dictionary and add error catching logic
    if (load_dictionary("pruned_lexicon.txt") == 0) {
        return 1;
    };
    // getting user's sentence
    char input_buffer[MAX_TOKENS * MAX_TOKEN_LEN];
    printf("input your sentence >>>> ");
    fscanf(stdin, "%[^\n]", input_buffer);
    // checking to see if the user actually inputted tokens
    if (tokenize_sentence(input_buffer) == 0) {
        return 0;
    };
    // lexical analysis.
    DictionaryEntry *matched_entries[MAX_TOKENS]; // to track/hold DictionaryEntries of validated tokes.
    analyze_tokens(matched_entries);
    // syntax validation
    validate_syntax(matched_entries);

    return 0;
}