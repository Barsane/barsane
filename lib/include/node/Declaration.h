//
// Created by souls on 05/05/2020.
//

#ifndef BARZANE_DECLARATION_H
#define BARZANE_DECLARATION_H


#include "../Node.h"
#include "../Symbol.h"
#include "../Indexer.h"
#include "Ids.h"
#include "Type.h"


/**
* A node declaration class is used to define a variable
* of the Barzane abstract syntax grammar. Its definition looks like:
*      declaration: {ids} : type ";"
*/
class Declaration: Node {

    public:
        /**
         * Constructor
         *
         * @param tokens: indexer of a set of tokens.
         */
        Declaration(Indexer<Symbol>* tokens);

        /**
         * Destructor
         */
        virtual ~Declaration();

        /**
         * It walks the indexer to extracting the nodes ids and type
         * that defines a node. It might either node that be not set if
         * the grammar is not caught. In this case, this method raises
         * an error. In the end, the current index point at the beginning
         * of the next instruction meaning after the next semicolon token.
         */
        void construct();

        /**
         * A json representative object.
         *
         * @param indentSize: it is by default 1 and defines the total space
         * that represents an indentation for each json node
         * @return a string that represents the object node declaration.
         */
        const string json(unsigned int indentSize = 1) const;

        /**
         * Get recovered node ids.
         *
         * @return a node ids (@see Ids).
         */
        Ids* getIds() const;

        /**
         * Get recovered node type.
         *
         * @return a node type (@see Type).
         */
        Type* getType();

    private:
        Ids* ids;
        Type* type;

};


#endif //BARZANE_DECLARATION_H
