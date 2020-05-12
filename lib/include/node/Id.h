//
// Created by souls on 05/05/2020.
//

#ifndef BARZANE_ID_H
#define BARZANE_ID_H


#include "../Node.h"


/**
* A node id class is used to represent a login that may a name
* of variable or function of the Barzane abstract syntax grammar.
* Its definition looks like:
*      id: [a-zA-Z_][a-zA-Z0-9_]*
*/
class Id: public Node {

    public:
        /**
         * Constructor
         *
         * @param tokens: indexer of a set of tokens.
         */
        Id(Indexer<Symbol>* tokens);

        /**
         * Destructor
         */
        virtual ~Id();

        /**
         * This method recover a login from the current token in
         * checking first this one respect Barzane grammar id. If this
         * latter is not matched, it raises an error. In the end, it points
         * the indexer on the next token.
         */
        void construct();

        /**
         * A json representative object.
         *
         * @param indentSize: it is by default 1 and defines the total space
         * that represents an indentation for each json node
         * @return a string that represents the object node id.
         */
        const string json(unsigned int indentSize = 1) const;

        /**
         * Get the recovered login
         *
         * @return a string.
         */
        string *getName() const;

    private:
        string* name;
};


#endif //BARZANE_ID_H
