//
// Created by souls on 04/05/2020.
//

#ifndef BARZANE_AST_H
#define BARZANE_AST_H

#include "Node.h"
#include "node/Declarations.h"
#include "node/Affects.h"
#include "node/Builtins.h"
#include "Error.h"

/**
 * It is a tree of the abstract syntactic structure of source
 * code. it is considered parent node of a program which it is
 * used to perform validation and produce compile code.
 *
 * AST inherits @class Node then it redefines the construct method
 * to build the the nodes children:
 *      declarations type of @class Declarations
 *      affects type of @class Affects
 *      builtins type of @class Builtins
 *
 */
class AST: public Node {

    public:
        /**
         * Constructor
         *
         * @param tokens: a indexer of a set of tokens.
         */
        AST(Indexer<Symbol>* tokens);

        /**
         * Destructor
         */
        ~AST();

        /**
         * Construct the high level syntactic structure meaning
         * the declarations, affects and builtins instructions.
         */
        void construct();

        /**
         * A representative object of node class.
         * TODO: arg
         * @return a string represented the instantiated object.
         */
        const string json(unsigned int indentSize) const;

        /**
         * Get declarations.
         *
         * @return a pointer of declarations (@see Declarations).
         */
        Declarations* getDeclarations() const;

        /**
         * Get affects.
         *
         * @return a pointer of affects (@see Affects).
         */
        Affects* getAffects() const;

        /**
         * Get builtins functions.
         *
         * @return a pointer of builtins (@see Builtins).
         */
        Builtins* getBuiltins() const;

        /**
         * Get error handler.
         *
         * @return errors container whose the content is populate while
         * constructing the tree.
         */
        ErrorHandler& getErrorHandler() const;

    private:
        Declarations* declarations;
        Affects* affects;
        Builtins* builtins;

        void buildNodeStartWithId();
        void buildBuiltins();
};

#endif //BARZANE_AST_H
