//
// Created by souls on 04/05/2020.
//

#include "../../include/node/Builtins.h"

Builtins::Builtins(Indexer<Symbol>* tokens) : Node(tokens), print(0) {
}

Builtins::~Builtins() {
    delete print;
}

void Builtins::construct() {
    if (current()->isPrint()) {
        print = new Print(indexer);
        print->construct();
    } else {
        string msg = "Invalid builtin function.";
        unsigned int line = current()->getLine();
        unsigned int colon = current()->getColon();
        Error error = Error(UNEXPECTED_ERROR, msg, line, colon);
        errorHandler.add(error);
    }
}

const string Builtins::json(unsigned int indentSize) const {
    stringstream repr;
    string indent(indentSize, INDENT);
    string backIndent(indentSize - 1, INDENT);
    if (print)
        repr << "[\n" << indent << print->json(indentSize + 1);
    repr << "\n" << backIndent << "]";
    return repr.str();
}

Print *Builtins::getPrint() const {
    return print;
}
