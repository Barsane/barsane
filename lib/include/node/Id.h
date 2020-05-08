//
// Created by souls on 05/05/2020.
//

#ifndef BARZANE_ID_H
#define BARZANE_ID_H


#include "../Node.h"

class Id: public Node {

    public:
        Id(Indexer<Symbol>& tokens);
        virtual ~Id();

        void construct();

        const string str(unsigned int indentSize = 1) const;

    private:
        string* name;
};


#endif //BARZANE_ID_H
