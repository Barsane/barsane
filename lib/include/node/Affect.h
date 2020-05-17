//
// Created by souls on 05/05/2020.
//

#ifndef BARZANE_AFFECT_H
#define BARZANE_AFFECT_H


#include "../Node.h"
#include "Id.h"
#include "Expression.h"

/**
* A node affect class is used to represent a assignment value
* to a variable of the Barzane abstract syntax grammar.
* Its definition looks like:
*      affect: {id} "=" {expression} ";"
*/
class Affect: public Node {
    public:
       /**
         * Construct
         *
         * @param tokens: a indexer of a set of tokens.
         */
        Affect(Indexer<Symbol>* tokens);

        /**
         * Destructor.
         */
        virtual ~Affect();

        /**
         * It walks the indexer to extracting the nodes id and expression
         * that defines a node. It might either node that be not set if
         * the grammar is not caught. In this case, this method raises
         * an error. In the end, the current index point at the beginning
         * of the next instruction meaning after the next semicolon token.
         */
        void construct();

        /**
         * A json representative object.
         *
         * @param indentSize: it is by default 1 and defines the total space
         * that represents an indentation for each json node
         * @return a string that represents the object node affect.
         */
        const string json(unsigned int indentSize = 1) const;

        /**
         * Get id.
         * @return a node id.
         */
        Id* getId() const;

        /**
         * Get expression.
         *
         * @return a node expression.
         */
        Expression *getExpression() const;

    private:
        Id* id;
        Expression* expression;
};


#endif //BARZANE_AFFECT_H
