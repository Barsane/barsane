//
// Created by souls on 04/05/2020.
//

#include "../../include/node/Builtins.h"

Builtins::Builtins(Indexer<Symbol> &tokens) : Node(tokens), print(0) {
}

Builtins::~Builtins() {
    delete print;
}

void Builtins::construct() {
    // TODO: recursive buitlins
    if (current()->isPrint()) {
        print = new Print(indexer);
        print->construct();
    }
}

const string Builtins::str(unsigned int indentSize) const {
    stringstream repr;
    string indent(indentSize, INDENT);
    string backIndent(indentSize - 1, INDENT);
    if (print)
        repr << "[\n" << indent << print->str(indentSize + 1);
    repr << "\n" << backIndent << "]";
    return repr.str();
}

Print *Builtins::getPrint() const {
    return print;
}
