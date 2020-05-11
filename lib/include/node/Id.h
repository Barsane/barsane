//
// Created by souls on 05/05/2020.
//

#ifndef BARZANE_ID_H
#define BARZANE_ID_H


#include "../Node.h"

/**
 * id: [a-zA-Z_][a-zA-Z0-9_]*
 */
class Id: public Node {

    public:
        Id(Indexer<Symbol>* tokens);
        virtual ~Id();

        void construct();

        const string json(unsigned int indentSize = 1) const;

        string *getName() const;

    private:
        string* name;
};


#endif //BARZANE_ID_H
