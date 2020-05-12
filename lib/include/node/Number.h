//
// Created by souls on 05/05/2020.
//

#ifndef BARZANE_NUMBER_H
#define BARZANE_NUMBER_H

#include "../Node.h"
#include "../str.h"

/**
 * Possible number type
 */
namespace NumberType {
    enum type {
        INTEGER,
        REAL,
        UNDEFINED
    };
}

/**
 * A node number class is used to represent an integer or real number
 * of the Barzane abstract syntax grammar. Its definition looks like:
 *      number: [0-9\.]+
 */
class Number: public Node {

    public:
        /**
         * Constructor
         *
         * @param tokens: indexer of a set of tokens.
         */
        Number(Indexer<Symbol>* tokens);

        /**
         * Destructor
         */
        virtual ~Number();

        /**
         * It checks if the current token is a numeric then it sets
         * the type since it is an integer or real. It he current token
         * is not a numeric, it raises an error and the type would have
         * undefined like value.
         */
        void construct();

        /**
         * A json representative object.
         *
         * @param indentSize: it is by default 1 and defines the total space
         * that represents an indentation for each json node
         * @return a string that represents the object node number.
         */
        const string json(unsigned int indentSize = 1) const;

        /**
         * Get the recovered integer.
         *
         * @return an integer value
         */
        int *getInteger() const;

        /**
         * Get the recovered real.
         *
         * @return a float value.
         */
        float *getReal() const;

        /**
         * Get the recovered type.
         * @return a type (@see NumberType::type)
         */
        NumberType::type getType() const;

    private:
        int *integer;
        float *real;
        NumberType::type type;

        void evaluate();
};


#endif //BARZANE_NUMBER_H
