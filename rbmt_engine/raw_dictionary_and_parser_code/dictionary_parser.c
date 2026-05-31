/*
 * this is to prune the dictionary and drop any unwanted attributes we do not want.
 * the attributes we are extracting are: WORD, POS, IPA, GLOSS
 * then we write it out to pruned_lexicon.txt file, this file would delimit these values using a pipe
 * for words with no IPA, we default to the string NO-IPA.
 * WORD | NOUN | IPA | GLOSS
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

#define BUFFER_SIZE 65536 // 64KB per JSON line maximum limit
#define MAX_FIELD_LEN 128

void error(char *errmsg) {
    fprintf(stderr, "%s : %s\n", errmsg, strerror(errno));
    exit(1);
}
void extract_field(const char *json_line, const char *anchor, char *output, int offset) {
    const char *start = strstr(json_line, anchor);
    if (start == NULL) {
        strcpy(output, "");
        return;
    }
    start += offset;
    int i=0;
    // copying each of the value into the output value.
    while ((start[i] != '\"') && (start[i] != '\0')) {
        output[i] = start[i];
        i++;
    }
    output[i] = '\0';
}

int main (int argc, char *argv[]) {
    char line_buffer[BUFFER_SIZE];
    FILE *input_file = fopen("kaikki.org-dictionary-Yoruba.jsonl", "r");
    FILE *output_file = fopen("../pruned_lexicon.txt", "w");
    if (input_file == NULL || output_file == NULL) {
        error("Unable to open input or output file.");
    }
    while (fgets(line_buffer, sizeof(line_buffer), input_file)) {
        char pos_buffer[20];
        extract_field(line_buffer, "\"pos\": \"", pos_buffer, 8);
        if (strcmp(pos_buffer, "character") == 0) { continue; } // skip over an entry if it is just a character not a word

        // continued processing.

        char word_buffer[MAX_FIELD_LEN], ipa_buffer[MAX_FIELD_LEN], gloss_buffer[2048]; // gloss_buffer more size, definitions can be long
        extract_field(line_buffer, "\"word\": \"", word_buffer, 9);
        extract_field(line_buffer, "\"ipa\": \"", ipa_buffer, 8);
        extract_field(line_buffer, "\"glosses\": [\"", gloss_buffer, 13);

        if (strlen(word_buffer) == 0 || strlen(pos_buffer) == 0){ continue; }
        if (strlen(ipa_buffer) == 0) {
            strcpy(ipa_buffer, "[NO-IPO]");
        }
        if ( strlen(gloss_buffer) == 0) {
            strcpy(gloss_buffer, "[NO-DEFINITION]");
        }
        // printing the cleaned stream into the pruned_lexicon.txt file.
        fprintf(output_file, "%s|%s|%s|%s\n", word_buffer, pos_buffer, ipa_buffer, gloss_buffer);
    }

    fclose(input_file);
    fclose(output_file);

    fprintf(stdout, "successfully pruned the dictionary!\n");
    return 0;
}
