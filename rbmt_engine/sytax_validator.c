#include "nlp_engine.h"
#include <stdio.h>
#include <string.h>
#include <strings.h>

static void print_contextual_ipa(const char *search_word, const char *resolved_pos) {
    for (int i = 0; i < total_word_count; i++) {
        // Finding the line that matches BOTH spelling AND the successful syntax role
        if (strcasecmp(lexicon[i].word, search_word) == 0 &&
            strcmp(lexicon[i].pos, resolved_pos) == 0) {

            // Print the tone-marked representation string
            printf("%s ", lexicon[i].ipa);
            return;
            }
    }
    // Fallback protection string if an entry disappears
    printf("[%s] ", search_word);
}
void validate_syntax(DictionaryEntry **m_e) {
    printf("\n*-----------------*Starting the syntax analysis pipeline*-----------------*\n");

    if (token_count == 0) return;

    int current_index = 0;
    // list that tracks our successfully resolved grammatical roles
    char resolved_roles[MAX_TOKENS][20];

    //STEP 1: Optional Subject Verification
    if (has_pos_match(m_e[current_index]->word, "noun")) {
        strcpy(resolved_roles[current_index], "noun");
        current_index++;
    } else if (has_pos_match(m_e[current_index]->word, "pron")) {
        strcpy(resolved_roles[current_index], "pron");
        current_index++;
    }

    if (current_index == token_count) {
        prog_error("SYNTAX ERROR", "Sentence ended prematurely.");
        return;
    }

    // STEP 2: Verb Core Action Path
    if (has_pos_match(m_e[current_index]->word, "verb")) {
        strcpy(resolved_roles[current_index], "verb");
        current_index++;

        // STEP 3: The Flowing Object Tail (can also accept serial verbs)
        while (current_index < token_count) {
            if (has_pos_match(m_e[current_index]->word, "noun")) {
                strcpy(resolved_roles[current_index], "noun");
                current_index++;
            } else if (has_pos_match(m_e[current_index]->word, "pron")) {
                strcpy(resolved_roles[current_index], "pron");
                current_index++;
            } else if (has_pos_match(m_e[current_index]->word, "verb")) {
                strcpy(resolved_roles[current_index], "verb");
                current_index++;
            } else {
                char err_msg_buff[256];
                snprintf(err_msg_buff, sizeof(err_msg_buff),"[SYNTAX ERROR]: Unexpected token '%s' found in predicate tail.\n", m_e[current_index]->word);
                prog_error("SYNTAX ERROR", err_msg_buff);
            }
        }

        // If we reached here, syntax is 100% successful!
        printf("[SYNTAX SUCCESS]: Valid flowing grammatical sentence sequence compiled!\n");
        printf("\n>>> PHONETIC PRONUNCIATION OUTPUT: ");
        for (int i = 0; i < token_count; i++) {
            print_contextual_ipa(m_e[i]->word, resolved_roles[i]);
        }
        printf("\n");
        return;
    }

    // STEP 4: Alternative Subject-Adjective path
    else if (current_index == 1 && has_pos_match(m_e[current_index]->word, "adj")) {
        strcpy(resolved_roles[current_index], "adj");

        printf("[SYNTAX SUCCESS]: Valid flowing S-Adj sentence compiled!\n");
        printf("\n>>> PHONETIC PRONUNCIATION OUTPUT: ");
        for (int i = 0; i < token_count; i++) {
            print_contextual_ipa(m_e[i]->word, resolved_roles[i]);
        }
        printf("\n");
        return;
    }

    fprintf(stderr, "[SYNTAX ERROR]: Structural template could not be matched by the streaming compiler engine.\n");
}