//
// Created by souls on 04/05/2020.
//

#ifndef BARZANE_NODE_H
#define BARZANE_NODE_H

#include "Indexer.h"
#include "Symbol.h"

/**
 * This is a base of all AST node classes. It defines
 * a minimal requirement to construct a node occurring
 * in the source code.
 */
class Node {

    public:
        /**
         * Constructor
         *
         * @param tokens: a indexer of a set of tokens.
         */
        Node(Indexer<Symbol>& tokens): indexer(tokens) {};

        /**
         * Destructor
         */
        virtual ~Node() {};

        /**
         * Construct a subtree to checking syntactic structure.
         */
        virtual void construct() = 0;

    protected:
        Indexer<Symbol>& indexer;

        Symbol* current() { return indexer.current(); };
};


#endif //BARZANE_NODE_H
