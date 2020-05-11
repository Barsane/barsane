//
// Created by souls on 04/05/2020.
//

#include "../include/Parser.h"

Parser::Parser(Lexer &lexer) {
    tree = new AST(lexer.getTokens());
    tree->construct();
}

Parser::~Parser() {
    delete tree;
}

AST *Parser::getTree() const {
    return tree;
}

void Parser::display() {
    cout << *tree;
}

void Parser::displayErrors() {
    tree->getErrorHandler().display();
}

bool Parser::hasErrors() {
    return !tree->getErrorHandler().empty();
}

