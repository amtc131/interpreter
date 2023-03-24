#include <token.h>
#include <iostream> 
#include <string>
#include <stdlib.h>
#include <stdio.h>

Token newToken(TokenType tokenType, char ch);
void readChar();
Token nextToken();

struct Lexer{
  std::string input;
  int position = 0;
  int readPosition = 0;
  char ch = '\0';

  void readChar(){
    //std::cout << "readChar  ch: " << ch << " readPosition: " << readPosition << "  input: " << input << " position: " << position << std::endl;
    if (readPosition >= input.length()){
      ch = 0;
    }else {
      ch = input[readPosition];
    }
    position = readPosition;
    readPosition++;
  }

  Token nextToken(){
    struct Token tok;
    switch (ch) {
      case '=':
        tok = newToken(ASSIGN, ch);
        break;
      case ';':
        tok = newToken(SEMICOLON, ch);
        break;
      case '(':
        tok = newToken(LPAREN, ch);
        break;
      case ')':
        tok = newToken(RPAREN, ch);
        break;
      case ',':
        tok = newToken(COMMA, ch);
        break;
      case '+':
        tok = newToken(PLUS, ch);
        break;
      case '{':
        tok = newToken(LBRACE, ch);
        break;
      case '}':
        tok = newToken(RBRACE, ch);
        break;
      case 0:
        tok.literal = "";
        tok.type = EO_F;
        break;
    }
    readChar();
    return tok;
  }

  Token newToken(TokenType tokenType, char ch){
    struct Token token;
    token.type = tokenType;
    token.literal = std::string(1,ch);
    return token;
  }
  Lexer newLexer(std::string input){
    struct Lexer lxr;
    lxr.input = input;
    lxr.readChar();
    return lxr;
  }

};


