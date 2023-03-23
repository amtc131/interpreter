#include <token.h>
#include <iostream> 
#include <string>
Token newToken(TokenType tokenType, char ch);
void readChar();
Token nextToken();

struct Lexer{
  std::string input;
  int position;
  int readPosition;
  char ch;

  void readChar(){
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
//    std::cout << "----" << ch << std::endl;
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
    std::cout << "-----" << tok.literal << "\n";
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


