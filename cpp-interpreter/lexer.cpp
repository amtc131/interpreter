#include <token.h>
#include <lexer.hpp>
#include <iostream> 
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

Token Lexer::nextToken(){
  struct Token tok;
  skipWhitespace();
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
    default:
      if (isLetter(ch)){
        tok.literal = readIdentifier();
        tok.type = lookupIdent(tok.literal);
        return tok;
      }else if(isDigit(ch)){
        tok.type = INT;
        tok.literal = readNumber();
        return tok;
      }else{
        tok = newToken(ILLEGAL, ch);
      }
  }
  readChar();
  return tok;
}

void Lexer::readChar(){
  //std::cout << "readChar  ch: " << ch << " readPosition: " << readPosition << "  input: " << input << " position: " << position << std::endl;
  if (readPosition >= input.length()){
    ch = 0;
  }else {
    ch = input[readPosition];
  }
  position = readPosition;
  readPosition++;
}

Lexer Lexer::newLexer(std::string input){
  Lexer lxr;
  lxr.input = input;
  lxr.readChar();
  return lxr;
}

Token Lexer::newToken(TokenType tokenType, char ch){
  struct Token token;
  token.type = tokenType;
  token.literal = std::string(1,ch);
  return token;
}

std::string Lexer::readIdentifier(){
  int pt = position;
  while(isLetter(ch)){
    readChar();
  }
  return input.substr(pt, position - pt);
}

bool isLetter(char ch){
  return 'a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z' || ch == '_';
}

void Lexer::skipWhitespace(){
  while (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r'){
    readChar();
  }
}

std::string Lexer::readNumber(){
  int p = position;
  while(isDigit(ch)){
    readChar();
  }
  return input.substr(p, position - p);
}

bool isDigit(char ch){
  return '0' <= ch && ch <= '9';
}
