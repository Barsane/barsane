//
// Created by souls on 05/05/2020.
//

#ifndef BARZANE_TYPE_H
#define BARZANE_TYPE_H


#include "../Node.h"
#include "../Symbol.h"
#include "../Indexer.h"

/**
 * Possible computed type
 */
namespace NodeType {
    enum type {
        NUMBER,
        BOOLEAN,
        STRING,
        UNDEFINED
    };
}

/**
 * A node type class is used to construct the possible computed type
 * of the Barzane abstract syntax grammar. Its definition looks like:
 *      type: "number" | "boolean" | "string"
 */
class Type: public Node {

    public:
        /**
         * Constructor
         *
         * @param tokens: indexer of a set of tokens.
         */
        Type(Indexer<Symbol>* tokens);

        /**
         * Destructor
         */
        virtual ~Type();

        /**
         * This method checks if the current token is one of the
         * keywords type. In this case it recovers this latter then
         * points the indexer to the next token.
         * When the current token is unexpected, it raises an error and
         * the type value would be undefined.
         */
        void construct();

        /**
         * A json representative object.
         *
         * @param indentSize: it is by default 1 and defines the total space
         * that represents an indentation for each json node
         * @return a string that represents the object node type.
         */
        const string json(unsigned int indentSize = 1) const;

        /**
         * Get the recovered type.
         * @return a type (@see NodeType::type)
         */
        NodeType::type getType() const;

    private:
            NodeType::type type;

};


#endif //BARZANE_TYPE_H
