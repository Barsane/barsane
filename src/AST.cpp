//
// Created by souls on 04/05/2020.
//

#include "../include/AST.h"

AST::AST(Indexer<Symbol> &tokens) : Node(tokens) {

}

AST::~AST() {

}

void AST::construct() {

}

Declarations *AST::getDeclarations() const {
    return nullptr;
}

Affects *AST::getAffects() const {
    return nullptr;
}

Builtins *AST::getBuiltins() const {
    return nullptr;
}
