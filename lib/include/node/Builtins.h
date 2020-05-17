//
// Created by souls on 04/05/2020.
//

#ifndef BARZANE_BUILTINS_H
#define BARZANE_BUILTINS_H

#include "../Node.h"
#include "Print.h"

/**
* A node builtins class is used to represent a set of builtins functions
* of the Barzane abstract syntax grammar.
* Its definition looks like:
*     builtins: {print}
*/
class Builtins: public Node {

    public:
        /**
         * Constructor
         *
         * @param tokens: a indexer of a set of tokens.
         */
        Builtins(Indexer<Symbol>* tokens);

        /**
         * Destructor
         */
        ~Builtins();

        /**
         * It checks if the current token is one of the keywords
         * regarding the builtins functions defined by the grammar
         * Barzane. If it is met, it gets the corresponding node.
         */
        void construct();

        /**
         * A json representative object.
         *
         * @param indentSize: it is by default 1 and defines the total space
         * that represents an indentation for each json node
         * @return a string that represents the object node builtins.
         */
        const string json(unsigned int indentSize = 1) const;

        /**
         * Get print.
         *
         * @return a node print.
         */
        Print *getPrint() const;

    private:
            Print* print;
};


#endif //BARZANE_BUILTINS_H
