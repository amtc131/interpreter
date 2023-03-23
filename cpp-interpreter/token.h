#include <string>
#include <iostream>
#define ILLEGAL "ILLEGAL"
#define EO_F "EOF"
#define IDENT "IDENT"
#define INT "INT"
#define ASSIGN "="
#define PLUS "+"
#define COMMA ","
#define SEMICOLON ";"
#define LPAREN "("
#define RPAREN ")"
#define LBRACE "{"
#define RBRACE "}"
#define FUNCTION "FUNCTION"
#define LET "LET"

typedef std::string TokenType;

#ifndef TOKEN_H
#define TOKEN_H

struct Token {
  TokenType type;
  std::string literal;
};

#endif 



