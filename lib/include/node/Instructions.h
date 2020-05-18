//
// Created by souls on 18/05/2020.
//

#ifndef BARZANE_INSTRUCTIONS_H
#define BARZANE_INSTRUCTIONS_H

#include "../Node.h"
#include "Instruction.h"


/**
* A node instructions class is used to define a set of instruction
* of the Barzane abstract syntax grammar. Its definition looks like:
*      instructions: {instruction} | {instruction} {instructions}
*/
class Instructions: public Node {
    public:
        /**
         * Construct
         *
         * @param tokens: an indexer of a set of tokens.
         */
        Instructions(Indexer<Symbol>* tokens);

        /**
         * Destructor
         */
        virtual ~Instructions();

        /**
         * This methods builds a set of node instruction in checking
         * first if the current is an instruction. If it is not the case,
         * it raises an error. Then, it gets recursively all node instruction
         * while catching a instruction grammar.
         * In the end, it points on the next token regarding the indexer.
         */
        void construct();

        /**
         * A json representative object.
         *
         * @param indentSize: it is by default 1 and defines the total space
         * that represents an indentation for each json node
         * @return a string that represents the object node instructions.
         */
        const string json(unsigned int indentSize = 1) const;

        /**
         * Get instructions.
         *
         * @return a node instructions.
         */
        Instructions *getInstructions() const;

        /**
         * Get instruction.
         *
         * @return a node instruction.
         */
        Instruction *getInstruction() const;

    private:
        Instructions* instructions;
        Instruction* instruction;
};


#endif //BARZANE_INSTRUCTIONS_H
