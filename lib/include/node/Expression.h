//
// Created by souls on 14/05/2020.
//

#ifndef BARZANE_EXPRESSION_H
#define BARZANE_EXPRESSION_H


#include "../Symbol.h"
#include "../Node.h"
#include "Boolean.h"
#include "Operation.h"
#include "String.h"


/**
* A node expression class is used to determine if a token is
* an operation, string or boolean of the Barzane abstract syntax grammar.
* Its definition looks like:
*       expression: {operation} | {string} | {boolean}
*/
class Expression: public Node {
    public:
        /**
         * Constructor.
         *
         * @param tokens: a indexer of a set of tokens.
         */
        Expression(Indexer<Symbol>* tokens);

        /**
         * Destructor
         */
        virtual ~Expression();

        /**
         * It checks if the current token is start with a first
         * token operation to extract operation if it is a boolean
         * or a string. Otherwise it raises an error. In the end, this
         * one is recovered like an operation or boolean or string since
         * the condition statement.
         */
        void construct();

        /**
         * A json representative object.
         *
         * @param indentSize: it is by default 1 and defines the total space
         * that represents an indentation for each json node
         * @return a string that represents the object node expression.
         */
        const string json(unsigned int indentSize = 1) const;

        /**
         * Get operation.
         *
         * @return a node operation (@see Operation).
         */
        Operation *getOperation() const;

        /**
         * Get string.
         *
         * @return a node string (@see String)
         */
        String *getString() const;

        /**
         * Get boolean.
         *
         * @return a node boolean (@see Boolean).
         */
        Boolean* getBoolean() const;

    private:
      Operation* operation;
      String* stringExpr;
      Boolean* boolean;
};


#endif //BARZANE_EXPRESSION_H
