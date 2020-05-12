//
// Created by souls on 10/05/2020.
//

#include "../../include/node/Ids.h"

using namespace std;

Ids::Ids(Indexer<Symbol>* tokens) : Node(tokens), ids(0), id(0) {

}

Ids::~Ids() {
    delete ids;
    delete id;
}

void Ids::construct() {
    if (grantNext(current()->isId())) {
        id = new Id(indexer);
        id->construct();
    } else {
        string msg = "An id must be match this pattern: [a-zA-Z_][a-zA-Z0-9_]*";
        unsigned int line = current()->getLine();
        unsigned int colon = current()->getColon();
        Error error = Error(UNEXPECTED_TOKEN, msg, line, colon);
        errorHandler.add(error);
        indexer->next();
    }

    if (nextIf(current()->isComa())) {
        ids = new Ids(indexer);
        ids->construct();
    }
}

const string Ids::json(unsigned int indentSize) const {
    return std::__cxx11::string();
}

Id *Ids::getId() const {
    return id;
}

Ids *Ids::getIds() const {
    return ids;
}
