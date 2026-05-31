#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "nlp_engine.h"

void sys_error(char *msg) {
    fprintf(stderr, " %s : %s\n", msg ,strerror(errno));
    puts("exiting programme...");
    exit(1);
}

void prog_error(char *error_type,char *msg) {
    // this makes our error handling modular.
    fprintf(stderr, "[%s] : %s\n", error_type,msg);
    puts("exiting programme...");
    exit(2);
}

void syntax_error(DictionaryEntry **m_e) {
    fprintf(stderr, "\n[SYNTAX ERROR]: Sentence structural layout is invalid.\n");
    fprintf(stderr, "You entered the following grammatical sequence:\n -> ");

    for (int i = 0; i < token_count; i++) {
        fprintf(stderr, "[%s]", m_e[i]->pos);
        if (i < token_count - 1) {
            fprintf(stderr, " -> ");
        }
    }
    fprintf(stderr, "\n\nThis sequence does not match any known grammar templates (SV, SVO, S-Adj).\n");
    printf("Parsing aborted due to compilation errors.\n");

    exit(3);
}
