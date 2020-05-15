//
// Created by souls on 14/05/2020.
//

#ifndef BARZANE_STRING_H
#define BARZANE_STRING_H


#include "../Node.h"
#include "../str.h"


/**
* A node string class is used to determine a string expression
* surrounded by double quotation mark of the Barzane abstract syntax grammar.
* Its definition looks like:
*       string: ".*"
*/
class String: public Node {

    public:
        /**
         * Constructor.
         *
         * @param tokens: a indexer of a set of tokens.
         */
        String(Indexer<Symbol>* tokens);

        /**
         * Destructor.
         */
        virtual ~String();

        /**
         * It gets the current token if it is an expression that
         * is a sequence character surrounded by double quotation
         * mark. In other case, an error is pointed. Then the indexer is
         * pointed on the next token.
         */
        void construct();

        /**
         * A json representative object.
         *
         * @param indentSize: it is by default 1 and defines the total space
         * that represents an indentation for each json node
         * @return a string that represents the object node string.
         */
        const string json(unsigned int indentSize = 1) const;

        /**
         * Get pointer of value.
         *
         * @return a string pointer.
         */
        string *getValue() const;

    private:
        string* value;
};


#endif //BARZANE_STRING_H
