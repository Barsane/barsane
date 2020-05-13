//
// Created by souls on 13/05/2020.
//

#ifndef BARZANE_TERM_H
#define BARZANE_TERM_H

#include "../Node.h"
#include "../Symbol.h"
#include "../Indexer.h"
#include "Factor.h"

/**
 * term: {factor} ("*" | "/") {term} | {factor}
 */
class Term: public Node {

    public:
        /**
         * TODO
         * @param tokens
         */
        Term(Indexer<Symbol>* tokens);

        /**
         * TODO
         */
        virtual ~Term();

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
        Factor *getFactor() const;

        /**
         * TODO
         * @return
         */
        Symbol *getOperator() const;

        /**
         * TODO
         * @return
         */
        Term *getTerm() const;

    private:
        Factor* factor;
        Symbol* operator_;
        Term* term;
};


#endif //BARZANE_TERM_H
