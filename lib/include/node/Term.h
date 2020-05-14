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
* A node term class is used to determine a mathematical expression that
* only focus on multiplication and division operation. The left or right
* factor may be any type of operation. For example a left seems 1+2.
* Its definition looks like:
*       term: {factor} ("*" | "/") {term} | {factor}
*/
class Term: public Node {

    public:
        /**
         * Constructor
         *
         * @param tokens: a indexer of a set of tokens.
         */
        Term(Indexer<Symbol>* tokens);

        /**
         * Destructor
         */
        virtual ~Term();

        /**
         * It walks the indexer to extract the first token if it
         * is a factor otherwise no action would be taken. Then if
         * the next token is an operator multiplication or division,
         * it would process the extraction to the right factor.
         */
        void construct();

        /**
         * A json representative object.
         *
         * @param indentSize: it is by default 1 and defines the total space
         * that represents an indentation for each json node
         * @return a string that represents the object node term.
         */
        const string json(unsigned int indentSize = 1) const;

        /**
         * Get factor.
         *
         * @return a factor (@see Factor).
         */
        Factor *getFactor() const;

        /**
         * Get operator.
         *
         * @return a symbol (@see Symbol).
         */
        Symbol *getOperator() const;

        /**
         * Get term.
         *
         * @return a term (@see Term).
         */
        Term *getTerm() const;

    private:
        Factor* factor;
        Symbol* operator_;
        Term* term;
};


#endif //BARZANE_TERM_H
