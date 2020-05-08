//
// Created by souls on 04/05/2020.
//

#include "../../include/node/Affects.h"

Affects::Affects(Indexer<Symbol> &tokens) : Node(tokens) {
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

    if (isNextAffect()) {
        affects = new Affects(indexer);
        affects->construct();
    }
}

const string Affects::str(unsigned int indentSize) const {
    stringstream repr;
    string indent(indentSize, INDENT);
    string backIndent(indentSize - 1, INDENT);
    if (affect)
        repr << "[\n" << indent << affect->str(indentSize + 1);
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

bool Affects::isNextAffect() {
    // Check id
    if (!indexer.end() && current()->isId()) {
        indexer.next();

        // check =
        if(!indexer.end() && current()->isAssignment()) {
            indexer.back();
            return true;
        }
    }

    return false;
}
