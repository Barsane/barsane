//
// Created by souls on 05/05/2020.
//

#ifndef BARZANE_PRINT_H
#define BARZANE_PRINT_H

#include "../Node.h"
#include "Id.h"

class Print: public Node {

    public:
        Print(Indexer<Symbol>& tokens);
        virtual ~Print();

        void construct();

        const string str(unsigned int indentSize = 1) const;

        Id *getId() const;

private:
        Id* id;
};


#endif //BARZANE_PRINT_H
