#include "Lexer.h"

void Lexer::Advance()
{
    _position++;
    if ((size_t)_position >= text.length())
    {
        _current = '\0';
    }
    else
    {
        _current = text[_position];
    }
}
char Lexer::Peek(const int offset) const
{
    const size_t index = _position + offset;
    if (index >= text.length())
    {
        return '\0';
    }
    return text[_position + offset];
}

void Lexer::LexNumber()
{
    while (std::isdigit(_current) || _current == '_')
    {
        _current_string += _current;
        Advance();
    }
}

Token Lexer::Lex()
{
    _start = _position;
    _type = TokenType::BAD_TOKEN;

    switch (_current)
    {
    case '\0':
        _type = TokenType::EOF_TOKEN;
        break;
    case '+':
        _type = TokenType::PLUS;
        _current_string = _current;
        Advance();
        break;
    case '-':
        _type = TokenType::MINUS;
        _current_string = _current;
        Advance();
        break;
    case '/':
        _type = TokenType::SLASH;
        _current_string = _current;
        Advance();
        break;
    case '*':
        _type = TokenType::STAR;
        _current_string = _current;
        Advance();
        break;
    case '%':
        _type = TokenType::MOD;
        _current_string = _current;
        Advance();
        break;
    case '=':
        _type = TokenType::EQUAL;
        _current_string = _current;
        Advance();
        break;
    case '(':
        _type = TokenType::LEFT_PAREN;
        _current_string = _current;
        Advance();
        break;
    case ')':
        _type = TokenType::RIGHT_PAREN;
        _current_string = _current;
        Advance();
        break;
    default:
        if (std::isdigit(_current))
        {
            _type = TokenType::NUMBER;
            LexNumber();
            Advance();
            break;
        }
        _type = TokenType::BAD_TOKEN;
        Advance();
        break;
    }

    auto token = Token{_current_string, _type};
    _current_string = "";
    return token;
}
