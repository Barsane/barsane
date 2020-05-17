//
// Created by souls on 05/05/2020.
//

#ifndef BARZANE_PRINT_H
#define BARZANE_PRINT_H

#include "../Node.h"
#include "Expression.h"

/**
* A node print class is used to print an expression
* of the Barzane abstract syntax grammar.
* Its definition looks like:
*       print: "print" {expression} ";"
*/
class Print: public Node {

    public:
        /**
         * Construct
         *
         * @param tokens: a indexer of a set of tokens.
         */
        Print(Indexer<Symbol>* tokens);

        /**
         * Destructor
         */
        virtual ~Print();

        /**
         * It checks if the current token is 'print' keyword
         * then it recovers the next token if it is an expression.
         * The fact these conditions are not met, raises an error.
         * In the end, a semicolon must be matched otherwise an error
         * kind of expect ';' at the end is throw.
         */
        void construct();

        /**
         * A json representative object.
         *
         * @param indentSize: it is by default 1 and defines the total space
         * that represents an indentation for each json node
         * @return a string that represents the object node print.
         */
        const string json(unsigned int indentSize = 1) const;

        /**
         * Get expression.
         *
         * @return a node expression.
         */
        Expression *getExpression() const;

    private:
        Expression* expression;
};


#endif //BARZANE_PRINT_H
