//
// Created by souls on 04/05/2020.
//

#include "../../include/node/Affects.h"

Affects::Affects(Indexer<Symbol>* tokens) : Node(tokens) {
    affects = 0;
    affect = 0;
}

Affects::~Affects() {
    delete affects;
    delete affect;
}

void Affects::construct() {
    affect = new Affect(indexer);
    affect->construct();

    if (isAffect()) {
        affects = new Affects(indexer);
        affects->construct();
    }
}

const string Affects::json(unsigned int indentSize) const {
    stringstream repr;
    string indent(indentSize, INDENT);
    string backIndent(indentSize - 1, INDENT);
    if (affect)
        repr << "[\n" << indent << affect->json(indentSize + 1);
    if (affects)
        repr << ",\n" << indent << affects->getAffect();

    repr << "\n" << backIndent << "]";
    return repr.str();
}

Affect *Affects::getAffect() const {
    return affect;
}

Affects *Affects::getAffects() const {
    return affects;
}
