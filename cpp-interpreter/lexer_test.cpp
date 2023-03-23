#include <token.h>
#include <iostream>
#include <string>
#include <vector>
#include <lexer.cpp>

struct TestData{
  TokenType expectedType;
  std::string expectedLiteral;
};

void testNextToken(){
  std::string input = "=+(){},;";
  
  std::vector<TestData> test ={
    {ASSIGN, "="},
    {PLUS, "+"},
    {LPAREN, "("},
    {RPAREN, ")"},
    {LBRACE, "{"},
    {RBRACE, "}"},
    {COMMA, ","},
    {SEMICOLON, ";"},
    {EO_F, ""},
  };
  
  Lexer l; 

  struct Lexer lx =l.newLexer(input);
  for(std::vector<TestData>::iterator it = test.begin(); it != test.end(); ++it){
    TestData element = *it;
    struct Token tok = lx.nextToken();
    if(tok.type.compare(element.expectedType) != 0){
      std::cout << "test - tokenType wrong. expected = " << element.expectedType << ", got= " << tok.type << "\n";
    } 
    //std::cout << tok.literal << std::endl;
    if(tok.literal.compare(element.expectedLiteral) != 0){
      std::cout << "test - literal wrong. expected = " << element.expectedLiteral << ", got= " << tok.literal << "\n";
    }
//    std::cout << element.expectedType << std::endl;
  }
}

int main(){
  testNextToken();
  return 0;
}
