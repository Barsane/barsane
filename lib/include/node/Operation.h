//
// Created by souls on 13/05/2020.
//

#ifndef BARZANE_OPERATION_H
#define BARZANE_OPERATION_H

#include "../Node.h"
#include "../Indexer.h"
#include "../Symbol.h"
#include "../str.h"
#include "Term.h"

/**
* A node term class is used to determine a mathematical expression that
* only focus on addition and substitution operation. The left or right
* factor may be any type of operation. For example a left seems 1*2.
* Its definition looks like:
*       operation: {term} ("+" | "-") {operation} | {term}
*/
class Operation: public Node {

    public:
        /**
         * Constructor
         *
         * @param tokens: a indexer of a set of tokens.
         */
        Operation(Indexer<Symbol>* tokens);

        /**
         * Destructor
         *
         */
        virtual ~Operation();

        /**
         * It walks the indexer to extract the first token if it
         * is a term otherwise no action would be taken. Then if
         * the next token is an operator addition or substitution,
         * it would process the extraction to the right operation.
         */
        void construct();

        /**
         * A json representative object.
         *
         * @param indentSize: it is by default 1 and defines the total space
         * that represents an indentation for each json node
         * @return a string that represents the object node operation.
         */
        const string json(unsigned int indentSize = 1) const;

        /**
         * Get term.
         *
         * @return a term (@see Term).
         */
        Term *getTerm() const;

        /**
         * Get operator.
         *
         * @return a symbol (@see Symbol).
         */
        Symbol *getOperator() const;

        /**
         * Get operation.
         *
         * @return an operation (@see Operation).
         */
        Operation *getOperation() const;

    private:
        Term* term;
        Symbol* operator_;
        Operation* operation;
};


#endif //BARZANE_OPERATION_H
