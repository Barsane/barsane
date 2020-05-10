//
// Created by souls on 10/05/2020.
//

#include "Ids.h"

Ids::Ids(Indexer<Symbol> &tokens) : Node(tokens) {

}

Ids::~Ids() {

}

void Ids::construct() {

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
