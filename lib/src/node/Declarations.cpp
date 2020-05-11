//
// Created by souls on 04/05/2020.
//

#include "../../include/node/Declarations.h"

Declarations::Declarations(Indexer<Symbol>* tokens) : Node(tokens) {
    declarations = 0;
    declaration = 0;
}

Declarations::~Declarations() {
    delete declarations;
    delete declaration;
}

void Declarations::construct() {
    declaration = new Declaration(indexer);
    declaration->construct();

    if (declarations) {
        declarations = new Declarations(indexer);
        declarations->construct();
    }
}

const string Declarations::json(unsigned int indentSize) const {
    stringstream repr;
    string indent(indentSize, INDENT);
    string backIndent(indentSize - 1, INDENT);
    if (declaration)
        repr << "[\n" << indent << declaration->json(indentSize + 1);
    if (declarations)
        repr << ",\n" << indent << declarations->getDeclaration();

    repr << "\n" << backIndent << "]";
    return repr.str();
}

Declaration *Declarations::getDeclaration() const {
    return declaration;
}

Declarations *Declarations::getDeclarations() const {
    return declarations;
}

bool Declarations::isNextDecl() {
    // Check id
    if (!indexer->end() && current()->isId()) {
        indexer->next();

        // check :
        if(!indexer->end() && current()->isColon()) {
            indexer->back();
            return true;
        }
    }

    return false;
}
