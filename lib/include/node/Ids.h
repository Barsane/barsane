//
// Created by souls on 10/05/2020.
//

#ifndef BARZANE_IDS_H
#define BARZANE_IDS_H


#include "../Node.h"
#include "Id.h"
#include <string>

/**
* A node ids class is used to represent a set of node id
* of the Barzane abstract syntax grammar. Its definition looks like:
*      ids: {id} | {id} "," {ids}
*/
class Ids: public Node {

    public:
        /**
         * Constructor
         *
         * @param tokens: indexer of a set of tokens.
         */
        Ids(Indexer<Symbol>* tokens);

        /**
         * Destructor
         */
        virtual ~Ids();

        /**
         * This methods builds a set of node id in checking
         * first if the current token is an id. If it is not the
         * case, it raises an error. Then, it gets recursively all node id while
         * the next token after each id is a coma. In the end, it points
         * on the next token regarding the indexer.
         */
        void construct();

        /**
         * A json representative object.
         *
         * @param indentSize: it is by default 1 and defines the total space
         * that represents an indentation for each json node
         * @return a string that represents the object node ids.
         */
        const string json(unsigned int indentSize = 1) const;

        /**
         * Get the recovered id.
         *
         * @return a node id.
         */
        Id *getId() const;

        /**
         * Get the recovered ids.
         *
         * @return a node ids.
         */
        Ids *getIds() const;

    private:
        Id* id;
        Ids* ids;
};


#endif //BARZANE_IDS_H
