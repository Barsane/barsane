//
// Created by souls on 18/05/2020.
//

#include "../../include/node/Instruction.h"

Instruction::Instruction(Indexer<Symbol> *tokens) : Node(tokens), declarations(0), affects(0), builtins(0) {
}

Instruction::~Instruction() {
    delete declarations;
    delete affects;
    delete builtins;
}

void Instruction::construct() {
    if (isDeclaration()) {
        declarations = new Declarations(indexer);
        declarations->construct();
    } else if (isAffect()) {
        affects = new Affects(indexer);
        affects->construct();
    } else if (isBuiltin()) {
        builtins = new Builtins(indexer);
        builtins->construct();
    } else {
        unsigned int line = current()->getLine();
        unsigned int colon = current()->getColon();
        string msg = "Unrecognized instruction.";
        Error error = Error(UNEXPECTED_ERROR, msg, line, colon);
        errorHandler.add(error);
        jump(SEMI_COLON);
        indexer->next();
    }
}

const string Instruction::json(unsigned int indentSize) const {
    return std::__cxx11::string();
}


Declarations *Instruction::getDeclarations() const {
    return declarations;
}

Affects *Instruction::getAffects() const {
    return affects;
}

Builtins *Instruction::getBuiltins() const {
    return builtins;
}
