//
// Created by souls on 04/05/2020.
//

#ifndef BARZANE_NODE_H
#define BARZANE_NODE_H

#include "Indexer.h"
#include "Symbol.h"

class Node {

    public:
        Node(Indexer<Symbol>& tokens): indexer(tokens) {};
        virtual ~Node() {};

        virtual void construct() = 0;

        Symbol* current() { return indexer.current(); };

    protected:
        Indexer<Symbol>& indexer;
};


#endif //BARZANE_NODE_H
