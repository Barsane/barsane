//
// Created by souls on 14/05/2020.
//

#ifndef BARZANE_BOOLEAN_H
#define BARZANE_BOOLEAN_H

#include "../Node.h"
#include "../str.h"

namespace BooleanType {
    enum Value {
        TRUE,
        FALSE,
        UNDEFINED
    };
}

/**
* A node boolean class is used to determine a boolean value that
* may only true or false of the Barzane abstract syntax grammar.
* Note it initialize to UNDEFINED meaning the instance is
* not constructed or it raises an error while walking the sequence.
* Its definition looks like:
*       boolean: "true" | "false"
*/
class Boolean: public Node {

    public:
        /**
         * Constructor
         *
         * @param tokens: a indexer of a set of tokens.
         */
        Boolean(Indexer<Symbol>* tokens);

        /**
         * Destructor.
         */
        virtual ~Boolean();

        /**
         * It checks if the current token is true or false as
         * value then recovers it. Otherwise it raises an error.
         * In the end the indexer is pointed on the next token.
         */
        void construct();

        /**
         * A json representative object.
         *
         * @param indentSize: it is by default 1 and defines the total space
         * that represents an indentation for each json node
         * @return a string that represents the object node boolean.
         */
        const string json(unsigned int indentSize = 1) const;

        /**
         * Get recovered value.
         *
         * @return a boolean type (@see BooleanType::Value).
         */
        BooleanType::Value getValue() const;

    private:
        BooleanType::Value value;
};


#endif //BARZANE_BOOLEAN_H
