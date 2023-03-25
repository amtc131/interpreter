#include <token.h>
#include <iostream>
#include <string>
#include <map>

using namespace std;

typedef std::map<std::string, TokenType> KeyWordMap;
KeyWordMap keywords = {{"fn", FUNCTION}, {"let", LET}};

TokenType lookupIdent(std::string ident){
  if(auto search = keywords.find(ident); search != keywords.end()){
    return search->second;
  }
  return IDENT;
}

