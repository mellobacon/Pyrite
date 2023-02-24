#include "../Pyrite/lib/Syntax/Lexer/Lexer.h"
#include "../Pyrite/lib/Syntax/SyntaxInfo/Token.h"
#include "gtest/gtest.h"

std::map<std::string, TokenType> GetTokens()
{
  std::map<std::string, TokenType> tokens = {
    {"1", TokenType::NUMBER},
    {"100", TokenType::NUMBER},
    {"+", TokenType::PLUS},
    {"-", TokenType::MINUS},
    {"*", TokenType::STAR},
    {"%", TokenType::MOD},
    {"/", TokenType::SLASH},
    {"=", TokenType::EQUAL},
    {"(", TokenType::LEFT_PAREN},
    {")", TokenType::RIGHT_PAREN},
    {"test", TokenType::BAD_TOKEN}
  };
  return tokens;
}

TEST(Lexer, InputIsLexed)
{
  const auto tokeninput = GetTokens();
  for (const auto& t : tokeninput)
  {
    Lexer lexer(t.first);
    while (true)
    {
      Token token = lexer.Lex();
      if (token.tokentype == TokenType::EOF_TOKEN) break;
      if (token.tokentype == TokenType::BAD_TOKEN)
      {
        ASSERT_EQ(token.tokentext, "");
        ASSERT_EQ(token.tokentype, t.second);
      }
      else
      {
        ASSERT_EQ(token.tokentype, t.second);
        ASSERT_EQ(token.tokentext, t.first);
      }
    }
  }
}