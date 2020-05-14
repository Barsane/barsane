//
// Created by souls on 14/05/2020.
//

#ifndef BARZANE_STRING_H
#define BARZANE_STRING_H


#include "../Node.h"
#include "../str.h"

/**
 * string: ".*"
 */
class String: public Node {

    public:
        String(Indexer<Symbol>* tokens);

        virtual ~String();

        void construct();

        const string json(unsigned int indentSize = 1) const;

        string *getValue() const;

    private:
        string* value;
};


#endif //BARZANE_STRING_H
