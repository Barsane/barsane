//
// Created by souls on 18/05/2020.
//

#ifndef BARZANE_INSTRUCTION_H
#define BARZANE_INSTRUCTION_H

#include "../Node.h"
#include "Declarations.h"
#include "Affects.h"
#include "Builtins.h"

class Instruction: public Node {
    public:
        Instruction(Indexer<Symbol>* tokens);
        virtual ~Instruction();

        void construct();

        const string json(unsigned int indentSize = 1) const;

        Declarations *getDeclarations() const;

        Affects *getAffects() const;

        Builtins *getBuiltins() const;

private:
        Declarations* declarations;
        Affects* affects;
        Builtins* builtins;
};


#endif //BARZANE_INSTRUCTION_H
