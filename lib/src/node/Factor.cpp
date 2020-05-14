//
// Created by souls on 13/05/2020.
//

#include "../../include/node/Factor.h"
#include "../../include/node/Operation.h"

Factor::Factor(Indexer<Symbol> *tokens)
    : Node(tokens), minus(0), id(0), number(0), leftBracket(0),
      rightBracket(0), operation(0) {

}

Factor::~Factor() {
    // Do not delete symbols (minus, leftBracket and rightBracket)
    // because the destructor base (~Node) is called and that handles
    // this action
    delete id;
    delete number;
    delete operation;
}

void Factor::construct() {
    // "-"
    if (grantNext(current()->isMinus())) {
        minus = current();
        indexer->next();
    }

    if (grantNext(current()->isId())) { // id
        id = new Id(indexer);
        id->construct();
    } else if (isNumber()) { // number
        number = new Number(indexer);
        number->construct();
    } else if (!minus && grantNext(current()->isLeftBracket())) { // "("
        leftBracket = current();
        indexer->next();

        // operation
        operation = new Operation(indexer);
        operation->construct();

        // ")"
        if (validate(current()->isRightBracket(), "Expected ')' at end of operation")) {
            indexer->back();
            rightBracket = current();
            indexer->next();
        }

    } else {
        string msg = "Expected factor that must start with id, number or left bracket.";
        unsigned int line = current()->getLine();
        unsigned int colon = current()->getColon();
        Error error = Error(UNEXPECTED_TOKEN, msg, line, colon);
        errorHandler.add(error);
        indexer->next();
    }
}

const string Factor::json(unsigned int indentSize) const {
    return std::__cxx11::string();
}

Symbol *Factor::getMinus() const {
    return minus;
}

Id *Factor::getId() const {
    return id;
}

Number *Factor::getNumber() const {
    return number;
}

Symbol *Factor::getLeftBracket() const {
    return leftBracket;
}

Symbol *Factor::getRightBracket() const {
    return rightBracket;
}

Operation *Factor::getOperation() const {
    return operation;
}

bool Factor::isNumber() {
    str token = str(current()->getToken());
    return token.isNumeric();
}

