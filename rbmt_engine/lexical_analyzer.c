#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "nlp_engine.h"


static DictionaryEntry* find_word(const char *word) {
    // this function takes a word and matches it to a particular entry in the lexicon.
    for (int i = 0; i < total_word_count;i++) {
        if (strcasecmp(lexicon[i].word, word) == 0) {
            return &lexicon[i]; //returns lexicon entry for the matched word.
        }
    }
    return NULL;
}

int tokenize_sentence(char *sentence) {
    const char *tok_ptr = strtok(sentence, " \t\n");
    while (tok_ptr != NULL) {
        if (token_count >= MAX_TOKENS)  break; // ensuring that we do not go beyond the bounds of the array.
        strncpy(token_array[token_count], tok_ptr, MAX_TOKEN_LEN - 1);
        token_array[token_count][MAX_TOKEN_LEN-1] = '\0'; //  always ensuring that each of the tokens are null terminated
        token_count++;

        tok_ptr = strtok(NULL, " \t\n");
    }
    return token_count;
}

void analyze_tokens(DictionaryEntry **m_e) {
    // m_e means matched_entries, visibly tracking the matched_entries.
    printf("*-----------------*Starting the lexical analysis pipeline*-----------------*\n");

    for (int i=0; i < token_count;i++) {
        DictionaryEntry *matched_entry = find_word(token_array[i]);

        if (matched_entry == NULL) {
            char err_msg_buff[128];
            snprintf(err_msg_buff, sizeof(err_msg_buff),"Unrecognized token '%s' found.\nThis word does not exist in our dictionary.\n\n", token_array[i]);
            prog_error("LEXICAL ERROR", err_msg_buff);
            exit(2); // this is to satisfy the code linter. the prog_err definitely exits.
        }

        printf("Token [%d]: '%s' -> Matched POS: [%s] | Phonetic IPA: %s\n",
            i,
            matched_entry->word,
            matched_entry->pos,
            matched_entry->ipa);

        m_e[i] = matched_entry;
    }
    printf("\n[SUCCESS]: All tokens validated cleanly against the lexicon database.\n");
}


int has_pos_match(const char *search_word, const char *target_pos) {
    // helper function that checks if a word exists in the dictionary with a SPECIFIC part of speech
    // it is used in the syntax checker module only
    for (int i = 0; i < total_word_count; i++) {
        if (strcasecmp(lexicon[i].word, search_word) == 0 &&
            strcmp(lexicon[i].pos, target_pos) == 0) {
            return 1; // that means that this word can act as this part of speech
            }
    }
    return 0; // it cannot act as this part of speech
}