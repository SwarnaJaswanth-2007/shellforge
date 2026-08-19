#ifndef LEXER_H
#define LEXER_H

#include "token.h"

/*
 * Lexical analyzer
 *
 * Converts the input command string into
 * a list of tokens.
 */
void lexer(const char *input,
           token_list_t *list);

#endif
