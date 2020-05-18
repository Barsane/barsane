//
// Created by souls on 18/05/2020.
//

#ifndef BARZANE_INSTRUCTION_H
#define BARZANE_INSTRUCTION_H

#include "../Node.h"
#include "Declarations.h"
#include "Affects.h"
#include "Builtins.h"

/**
* A node instruction class is used to define an instruction that can
 * be a declaration, an assignment or a call to a builtin function
* of the Barzane abstract syntax grammar. Its definition looks like:
*      instruction: {declarations} | {affects} | {builtins}
*/
class Instruction: public Node {
    public:
        /**
         * Construct
         *
         * @param tokens: an indexer of a set of tokens.
         */
        Instruction(Indexer<Symbol>* tokens);

        /**
         * Destructor
         */
        virtual ~Instruction();

        /**
         * It checks if the current token is a declaration or
         * an assignment or a call builtin function. It if it is
         * the case, it constructs the corresponding node. Otherwise
         * it raises an error.
         */
        void construct();


        /**
         * A json representative object.
         *
         * @param indentSize: it is by default 1 and defines the total space
         * that represents an indentation for each json node
         * @return a string that represents the object node instruction.
         */
        const string json(unsigned int indentSize = 1) const;

        /**
         * Get declarations.
         *
         * @return a node declarations.
         */
        Declarations *getDeclarations() const;

        /**
         * Get affects.
         *
         * @return a node affects.
         */
        Affects *getAffects() const;

        /**
         * Get builtins.
         *
         * @return a node builtins.
         */
        Builtins *getBuiltins() const;

    private:
        Declarations* declarations;
        Affects* affects;
        Builtins* builtins;
};


#endif //BARZANE_INSTRUCTION_H
