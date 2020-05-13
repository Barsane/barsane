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
 * operation: {term} ("+" | "-") {operation} | {term}
 */
class Operation: public Node {

    public:
        /**
         * TODO
         * @param tokens
         */
        Operation(Indexer<Symbol>* tokens);

        /**
         * TODO
         */
        virtual ~Operation();

        /**
         * TODO
         */
        void construct();

        /**
         * TODO
         * @param indentSize
         * @return
         */
        const string json(unsigned int indentSize = 1) const;

        /**
         * TODO
         * @return
         */
        Term *getTerm() const;

        /**
         * TODO
         * @return
         */
        Symbol *getOperator() const;

        /**
         * TODO
         * @return
         */
        Operation *getOperation() const;

    private:
        Term* term;
        Symbol* operator_;
        Operation* operation;
};


#endif //BARZANE_OPERATION_H
