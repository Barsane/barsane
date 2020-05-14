//
// Created by souls on 14/05/2020.
//

#include "../../include/node/Boolean.h"


Boolean::Boolean(Indexer<Symbol> *tokens) : Node(tokens), value(BooleanType::UNDEFINED) {
}

Boolean::~Boolean() {
}

void Boolean::construct() {
    if (grantNext(current()->getToken() == "true"))
        value = BooleanType::TRUE;
    else if (grantNext(current()->getToken() == "false"))
        value = BooleanType::FALSE;
    else {
        string msg = "Expected 'true' or 'false' keywords.";
        unsigned int line = current()->getLine();
        unsigned int colon = current()->getColon();
        Error error = Error(UNEXPECTED_TOKEN, msg, line, colon);
        errorHandler.add(error);
    }

    indexer->next();
}

const string Boolean::json(unsigned int indentSize) const {
    return std::__cxx11::string();
}

BooleanType::Value Boolean::getValue() const {
    return value;
}
