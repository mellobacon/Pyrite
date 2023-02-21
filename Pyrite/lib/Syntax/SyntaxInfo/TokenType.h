#pragma once

enum class TokenType {
    NUMBER = 0,
    STRING = 1,
    KEYWORD = 2,
    VARIABLE = 3,
    
    PLUS = 4,
    MINUS = 5,
    SLASH = 6,
    STAR = 7,
    MOD = 8,
    EQUAL = 9,
    
    LEFT_PAREN = 10,
    RIGHT_PAREN = 11,
    LEFT_BRACKET = 12,
    RIGHT_BRACKET = 13,
    
    PIPE = 14,
    AND = 15,
    DOUBLE_PIPE = 16,
    DOUBLE_AND = 17,
    
    DOUBLE_COLON = 18,
    COLON = 19,
    SEMICOLON = 20,
    
    DOUBLE_EQUAL = 21,
    PLUS_EQUAL = 22,
    MINUS_EQUAL = 23,
    STAR_EQUAL = 24,
    SLASH_EQUAL = 25,
    MOD_EQUAL = 26,
    
    BANG = 27,
    BANG_EQUAL = 28,
    
    HAT = 29,
    
    LESS_THAN = 30,
    MORE_THAN = 31,
    LESS_EQUAL = 32,
    MORE_EQUAL = 33,

    LITERAL_EXPRESSION = 34,
    BINARY_EXPRESSION = 35,
    
    EOF_TOKEN = 36,
    BAD_TOKEN = 37
};

