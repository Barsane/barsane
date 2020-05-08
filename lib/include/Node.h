//
// Created by souls on 04/05/2020.
//

#ifndef BARZANE_NODE_H
#define BARZANE_NODE_H

#include <iostream>
#include <string>
#include "Indexer.h"
#include "Symbol.h"
#include "ErrorHandler.h"

using namespace std;

/**
 * This is a base of all AST node classes. It defines
 * a minimal requirement to construct a node occurring
 * in the source code.
 */
class Node {


    /**
     * A representative object of Node class.
     * @param out: a stream object.
     * @param node: A node to represent.
     * @return Get the given stream after push the representation string.
     */
    friend ostream& operator<<(ostream& out, const Node& node) { out << node.str(); }

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

        /**
         * A representative object of node class.
         * TODO: optional arg
         * @return a string represented the instantiated object.
         */
        virtual const string str(unsigned int indentSize = 1) const = 0;

    protected:
        Indexer<Symbol>& indexer;

        inline static ErrorHandler errorHandler; // C++17 (inline)

        inline static const char INDENT = ' ';

        Symbol* current() { return indexer.current(); };
};

#endif //BARZANE_NODE_H
