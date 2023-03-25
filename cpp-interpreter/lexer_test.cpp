#include <token.h>
#include <iostream>
#include <string>
#include <vector>
#include <lexer.hpp>
#include <stdio.h>
#include <string.h>

using namespace std;

struct TestData{
  TokenType expectedType;
  std::string expectedLiteral;
};

void testNextToken(){
  std::string input;

   input.append("let five = 5;\n")
        .append("let ten = 10;\n")
        .append("let add = fn(x, y) {\n")
        .append("  x + y;\n")
        .append("}; \n")
        .append("let result = add(five, ten);");

  cout << "input: " << input << "\n\n"; 

  std::vector<TestData> test ={
    {LET, "let"},
    {IDENT, "five"},
    {ASSIGN, "="},
    {INT, "5"},
    {SEMICOLON, ";"},
    {LET, "let"},
    {IDENT, "ten"},
    {ASSIGN, "="},
    {INT, "10"},
    {SEMICOLON, ";"},
    {LET, "let"},
    {IDENT, "add"},
    {ASSIGN, "="},
    {FUNCTION, "fn"},
    {LPAREN, "("},
    {IDENT, "x"},
    {COMMA, ","},
    {IDENT, "y"},
    {RPAREN, ")"},
    {LBRACE, "{"},
    {IDENT, "x"},
    {PLUS, "+"},
    {IDENT, "y"},
    {SEMICOLON, ";"},
    {RBRACE, "}"},
    {SEMICOLON, ";"},
    {LET, "let"},
    {IDENT, "result"},
    {ASSIGN, "="},
    {IDENT, "add"},
    {LPAREN, "("},
    {IDENT, "five"},
    {COMMA, ","},
    {IDENT, "ten"},
    {RPAREN, ")"},
    {SEMICOLON, ";"},
    {EO_F, ""},
  };
  
  Lexer l; 
  Lexer lx = l.newLexer(input);
  int i =0;
  for(std::vector<TestData>::iterator it = test.begin(); it != test.end(); ++it){
    TestData element = *it;
    Token tok = lx.nextToken();
    if(tok.type.compare(element.expectedType) != 0){
      std::cout << "test "<< i << "- tokenType wrong. expected = " << element.expectedType << ", got= " << tok.type << "\n";
    } 
    if(tok.literal.compare(element.expectedLiteral) != 0){
      std::cout << "test "<< i << "- literal wrong. expected = " << element.expectedLiteral << ", got= " << tok.literal << "\n";
    }
    i++;
  }
}

int main(){
  testNextToken();
  return 0;
}
