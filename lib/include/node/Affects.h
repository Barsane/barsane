//
// Created by souls on 04/05/2020.
//

#ifndef BARZANE_AFFECTS_H
#define BARZANE_AFFECTS_H

#include "../Node.h"
#include "Affect.h"

/**
* A node affects class is used to represent a set of node affect
* of the Barzane abstract syntax grammar. Its definition looks like:
*      affects: {affect} | {affect} {affects}
*/
class Affects: public Node {

    public:
        /**
         * Construct
         *
         * @param tokens: a indexer of a set of tokens.
         */
        Affects(Indexer<Symbol>* tokens);

        /**
         * Destructor
         */
        ~Affects();

       /**
         * This methods builds a set of node affect in checking
         * first if the current and next tokens are respectively an id and equal.
         * If it is not the case, it raises an error. Then, it gets recursively all
         * node affect while catching a affect grammar.
         * In the end, it points on the next token regarding the indexer.
         */
        void construct();

       /**
         * A json representative object.
         *
         * @param indentSize: it is by default 1 and defines the total space
         * that represents an indentation for each json node
         * @return a string that represents the object node affects.
         */
        const string json(unsigned int indentSize = 1) const;

        /**
         * Get affect.
         *
         * @return a node affect.
         */
        Affect *getAffect() const;

        /**
         * Get affects.
         *
         * @return a node affects.
         */
        Affects *getAffects() const;

    private:
        Affect* affect;
        Affects* affects;

        bool isNextAffect();
};


#endif //BARZANE_AFFECTS_H
