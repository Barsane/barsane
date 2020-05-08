//
// Created by souls on 05/05/2020.
//

#ifndef BARZANE_TYPE_H
#define BARZANE_TYPE_H


#include "../Node.h"
#include "../Symbol.h"
#include "../Indexer.h"

class Type: public Node {

    public:
        Type(Indexer<Symbol>& tokens);
        virtual ~Type();

        void construct();
        const string str(unsigned int indentSize = 1) const;

        string *getValue() const;

    private:
        string* value;

};


#endif //BARZANE_TYPE_H
