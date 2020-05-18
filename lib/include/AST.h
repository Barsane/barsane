//
// Created by souls on 04/05/2020.
//

#ifndef BARZANE_AST_H
#define BARZANE_AST_H

#include "Node.h"
#include "node/Instructions.h"

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
         * A json representative object.
         *
         * @param indentSize: it is by default 1 and defines the total space
         * that represents an indentation for each json node
         * @return a string that represents the object node ast.
         */
        const string json(unsigned int indentSize) const;

        /**
         * Get error handler.
         *
         * @return errors container whose the content is populate while
         * constructing the tree.
         */
        ErrorHandler& getErrorHandler() const;

        /**
         * Get instructions.
         *
         * @return a node instructions.
         */
        Instructions *getInstructions() const;

    private:
        Instructions* instructions;
};

#endif //BARZANE_AST_H
