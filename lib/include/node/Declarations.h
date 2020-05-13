//
// Created by souls on 04/05/2020.
//

#ifndef BARZANE_DECLARATIONS_H
#define BARZANE_DECLARATIONS_H

#include "../Node.h"
#include "Declaration.h"

/**
* A node declarations class is used to define a set of definition variables
* of the Barzane abstract syntax grammar. Its definition looks like:
*      declarations: {declaration} | {declaration} | {declarations}
*/
class Declarations: public Node {

    public:

        /**
         * Constructor
         *
         * @param tokens: indexer of a set of tokens.
         */
        Declarations(Indexer<Symbol>* tokens);

        /**
         * Destructor
         */
        ~Declarations();

        /**
         * This methods builds a set of node declaration in checking
         * first if the current and next tokens are respectively an id and colon.
         * If it is not the case, it raises an error. Then, it gets recursively all
         * node declaration while catching a declaration grammar.
         * In the end, it points on the next token regarding the indexer.
         */
        void construct();

        /**
         * A json representative object.
         *
         * @param indentSize: it is by default 1 and defines the total space
         * that represents an indentation for each json node
         * @return a string that represents the object node declarations.
         */
        const string json(unsigned int indentSize = 1) const;

        /**
         * Get recovered declaration.
         *
         * @return a node declaration (@see declaration).
         */
        Declaration *getDeclaration() const;

        /**
         * Get recovered declarations.
         *
         * @return a node declarations.
         */
        Declarations *getDeclarations() const;

    private:
        Declaration* declaration;
        Declarations* declarations;
};


#endif //BARZANE_DECLARATIONS_H
