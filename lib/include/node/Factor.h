//
// Created by souls on 13/05/2020.
//

#ifndef BARZANE_FACTOR_H
#define BARZANE_FACTOR_H

#include "../Node.h"
#include "Id.h"
#include "Number.h"
#include "../Indexer.h"
#include "../Symbol.h"
#include "../str.h"

class Operation;


/**
* A node factor class is used to determine a mathematical expression
* of the Barzane abstract syntax grammar. It recursively constructs
* the syntax by creating node id, number or operation.
* Its definition looks like:
*      factor: ["-"] {id} | ["-"] {number} | "(" {operation} ")"
*/
class Factor: public Node {

    public:
        /**
         * Constructor
         *
         * @param tokens: a indexer of a set of tokens.
         */
        Factor(Indexer<Symbol>* tokens);

        /**
         * Destructor
         */
        virtual ~Factor();

        /**
         * It walks the indexer to extract first minus like the
         * beginning token if it exists. The next token of indexer
         * is also processed as a id if it is a login or as a number
         * or again if it is a left bracket token.
         */
        void construct();

        /**
         * A json representative object.
         *
         * @param indentSize: it is by default 1 and defines the total space
         * that represents an indentation for each json node
         * @return a string that represents the object node factor.
         */
        const string json(unsigned int indentSize = 1) const;

        /**
         * Get minus.
         *
         * @return a symbol (@see Symbol).
         */
        Symbol *getMinus() const;

        /**
         * Get id.
         *
         * @return a node id (@see Id).
         */
        Id *getId() const;

        /**
         * Get number.
         *
         * @return a node number (@see Number).
         */
        Number *getNumber() const;

        /**
         * Get left bracket.
         *
         * @return a symbol (@see Symbol).
         */
        Symbol *getLeftBracket() const;

        /**
         * Get right bracket.
         *
         * @return a symbol (@see Symbol).
         */
        Symbol *getRightBracket() const;

        /**
         * Get operation.
         *
         * @return an operation (@see Operation).
         */
        Operation *getOperation() const;

    private:
        Symbol* minus;
        Id* id;
        Number* number;
        Symbol* leftBracket;
        Symbol* rightBracket;
        Operation* operation;

        bool isNumber();
};


#endif //BARZANE_FACTOR_H
