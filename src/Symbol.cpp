//
// Created by souls on 29/04/2020.
//

#include "../include/Symbol.h"

Symbol::Symbol(string &token, const unsigned int line, const unsigned int colon)
    : token(token), line(line), colon(colon), type(typeOf(token)) {

}

Symbol::~Symbol() {

}

bool Symbol::isValue() const {
    return false;
}

bool Symbol::isId() const {
    return false;
}

bool Symbol::isDoubleQuotation() const {
    return false;
}

bool Symbol::isType() const {
    return false;
}

bool Symbol::isComa() const {
    return false;
}

bool Symbol::isColon() const {
    return false;
}

bool Symbol::isSemiColon() const {
    return false;
}

bool Symbol::isMinus() const {
    return false;
}

bool Symbol::isLeftBracket() const {
    return false;
}

bool Symbol::isRightBracket() const {
    return false;
}

bool Symbol::isTermOperator() const {
    return false;
}

bool Symbol::isOperationOperator() const {
    return false;
}

bool Symbol::isAssignment() const {
    return false;
}

bool Symbol::isPrint() const {
    return false;
}

SymbolType Symbol::typeOf(const string &token) {
    return COMA;
}

string Symbol::stringOf(const SymbolType type) {
    return std::__cxx11::string();
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
