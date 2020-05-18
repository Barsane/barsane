//
// Created by souls on 18/05/2020.
//

#include "../../include/node/Instructions.h"

Instructions::Instructions(Indexer<Symbol> *tokens) : Node(tokens), instructions(0), instruction(0) {
}

Instructions::~Instructions() {
    delete instruction;
    delete instructions;
}

void Instructions::construct() {
    instruction = new Instruction(indexer);
    instruction->construct();

    if (isDeclaration() || isAffect() || isBuiltin()) {
        instructions = new Instructions(indexer);
        instructions->construct();
    }
}

const string Instructions::json(unsigned int indentSize) const {
    return std::__cxx11::string();
}

Instructions *Instructions::getInstructions() const {
    return instructions;
}

Instruction *Instructions::getInstruction() const {
    return instruction;
}
