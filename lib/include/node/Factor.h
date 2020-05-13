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
 * factor: ["-"] {id} | ["-"] {number} | "(" {operation} ")"
 */
class Factor: public Node {

    public:
        /**
         * TODO
         * @param tokens
         */
        Factor(Indexer<Symbol>* tokens);

        /**
         * TODO
         */
        virtual ~Factor();

        /**
         * TODO
         */
        void construct();

        /**
         * TODO
         */
        const string json(unsigned int indentSize = 1) const;

        /**
         * TODO
         * @return
         */
        Symbol *getMinus() const;

        /**
         * TODO
         * @return
         */
        Id *getId() const;

        /**
         * TODO
         * @return
         */
        Number *getNumber() const;

        /**
         * TODO
         * @return
         */
        Symbol *getLeftBracket() const;

        /**
         * TODO
         * @return
         */
        Symbol *getRightBracket() const;

        /**
         * TODO
         * @return
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
