//
// Created by souls on 18/05/2020.
//

#ifndef BARZANE_INSTRUCTIONS_H
#define BARZANE_INSTRUCTIONS_H

#include "../Node.h"
#include "Instruction.h"

class Instructions: public Node {

    public:
        Instructions(Indexer<Symbol>* tokens);

        virtual ~Instructions();

        void construct();

        const string json(unsigned int indentSize = 1) const;

        Instructions *getInstructions() const;

        Instruction *getInstruction() const;

    private:
        Instructions* instructions;
        Instruction* instruction;
};


#endif //BARZANE_INSTRUCTIONS_H
