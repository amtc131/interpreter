#include <token.h>
#include <iostream> 
#include <string>

bool isLetter(char ch);
bool isDigit(char ch);

class Lexer {
public:
  std::string input;
  char ch = '\0';
  Token nextToken();
  Lexer newLexer(std::string input);
private:
  int position = 0;
  int readPosition = 0;
  void readChar();
  Token newToken(TokenType tokenType, char ch);
  std::string readIdentifier();
  void skipWhitespace();
  std::string readNumber();
}; 


