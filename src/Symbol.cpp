//
// Created by souls on 29/04/2020.
//

#include "../include/Symbol.h"

Symbol::Symbol(string &token, const unsigned int line, const unsigned int colon)
    : token(token), line(line), colon(colon), type(typeOf(token)) {
    if (line == 0)
        throw "line attribute must be greater than 0";
    if (colon == 0)
        throw "colon attribute must be greater than 0";
}

Symbol::~Symbol() {
}

bool Symbol::isValue() const {
    return type == VALUE;
}

bool Symbol::isId() const {
    return type == ID;
}

bool Symbol::isType() const {
    return type == TYPE;
}

bool Symbol::isComa() const {
    return type == COMA;
}

bool Symbol::isColon() const {
    return type == COLON;
}

bool Symbol::isSemiColon() const {
    return type == SEMI_COLON;
}

bool Symbol::isMinus() const {
    return token == "-";
}

bool Symbol::isLeftBracket() const {
    return type == LEFT_BRACKET;
}

bool Symbol::isRightBracket() const {
    return type == RIGHT_BRACKET;
}

bool Symbol::isTermOperator() const {
    return type == TERM_OPERATOR;
}

bool Symbol::isOperationOperator() const {
    return type == OPERATION_OPERATOR;
}

bool Symbol::isAssignment() const {
    return type == ASSIGNMENT;
}

bool Symbol::isPrint() const {
    return type == PRINT;
}

SymbolType Symbol::typeOf(const string &token) {
    // TODO: Handle value outside
    str key = str(token);
    str first = str(token[0]);
    if (key.isNumeric() || key.isExpression() ||
        token == "true" || token == "false")
        return VALUE;
    if (first.isAlphaUnd() && key.isAlphaNumUnd())
        return ID;
    // TODO: Handle type outside
    if (token == "number" || token == "boolean" || token == "string")
        return TYPE;
    if (token == ",")
        return COMA;
    if (token == ":")
        return COLON;
    if (token == ";")
        return SEMI_COLON;
    if (token == "(")
        return LEFT_BRACKET;
    if (token == ")")
        return RIGHT_BRACKET;
    //TODO: Handle term operator outside
    if (token == "*" || token == "/")
        return TERM_OPERATOR;
    //TODO: Handle operation operator outside
    if (token == "+" || token == "")
        return OPERATION_OPERATOR;
    if (token == "=")
        return ASSIGNMENT;
    if (token == "print")
        return PRINT;
    return UNKNOWN;
}

string Symbol::stringOf(const SymbolType type) {
    if (type == VALUE)                  return "VALUE";
    if (type == ID)                     return "ID";
    if (type == TYPE)                   return "TYPE";
    if (type == COMA)                   return "COMA";
    if (type == COLON)                  return "COLON";
    if (type == SEMI_COLON)             return "SEMI_COLON";
    if (type == LEFT_BRACKET)           return "LEFT_BRACKET";
    if (type == RIGHT_BRACKET)          return "RIGHT_BRACKET";
    if (type == OPERATION_OPERATOR)     return "OPERATION_OPERATOR";
    if (type == TERM_OPERATOR)          return "TERM_OPERATOR";
    if (type == ASSIGNMENT)             return "ASSIGNMENT";
    if (type == PRINT)                  return "PRINT";

    return "UNKNOWN";
}

string &Symbol::getToken() const {
    return token;
}

unsigned int Symbol::getLine() const {
    return line;
}

unsigned int Symbol::getColon() const {
    return colon;
}

SymbolType Symbol::getType() const {
    return type;
}
