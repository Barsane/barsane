//
// Created by souls on 04/05/2020.
//

#ifndef BARZANE_NODE_H
#define BARZANE_NODE_H

#include <iostream>
#include <string>
#include <set>
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
    friend ostream& operator<<(ostream& out, const Node& node) { out << node.json(); return out; }

    public:
        /**
         * Constructor
         *
         * @param tokens: a indexer of a set of tokens.
         */
        Node(Indexer<Symbol>* tokens);

        /**
         * Destructor
         */
        virtual ~Node();

        /**
         * Construct a subtree to checking syntactic structure.
         */
        virtual void construct() = 0;

        /**
         * A representative object of node class.
         * TODO: optional arg
         * @return a string represented the instantiated object.
         */
        virtual const string json(unsigned int indentSize = 1) const = 0;

    protected:
        Indexer<Symbol>* indexer;

        inline static ErrorHandler errorHandler; // C++17 (inline)

        inline static const char INDENT = ' ';

        Symbol* current();

        bool validate(const bool cond, string msg);

        void jump(SymbolType type);

        bool nextIf(const bool cond);

        bool grantNext(const bool cond);

        bool isFactor();

        bool isExpression();

        bool isDeclaration();

        bool isAffect();

        bool isBuiltin();

    private:
        // Internal usage fo destructor
        inline static set<Indexer<Symbol>*> __indexers__;
};

#include "Node.hxx"

#endif //BARZANE_NODE_H
