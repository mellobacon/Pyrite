#include "Token.h"
TokenType Token::GetType()
{
    return tokentype;
}
std::list<Node*> Token::GetChildren()
{
    return {};
}
std::map<TokenType, std::string> Token::TryGetToken()
{
    return {std::pair<TokenType, std::string>(tokentype, tokentext)};
}

