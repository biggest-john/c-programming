#ifndef NLP_ENGINE_H
#define NLP_ENGINE_H

#define MAX_WORDS 6280
#define MAX_STR_LEN 128
#define MAX_TOKEN_LEN 50
#define MAX_TOKENS 20

typedef struct DictionaryEntry {
    char word[MAX_STR_LEN];
    char pos[MAX_STR_LEN];
    char ipa[MAX_STR_LEN];
    char gloss[MAX_STR_LEN];
}DictionaryEntry;

extern DictionaryEntry lexicon[MAX_WORDS];
extern int total_word_count;

extern char token_array[MAX_TOKENS][MAX_TOKEN_LEN];
extern int token_count;

// error_handler
void sys_error(char *msg);
void prog_error(char *error_type,char *msg);
void syntax_error(DictionaryEntry **m_e);

// lexical_analyzer
int tokenize_sentence(char *sentence);
void analyze_tokens(DictionaryEntry **m_e);
int has_pos_match(const char *search_word, const char *target_pos);

//syntax_validator
void validate_syntax(DictionaryEntry **m_e);


#endif