//
// Created by souls on 04/05/2020.
//

#ifndef BARZANE_BUILTINS_H
#define BARZANE_BUILTINS_H

#include "../Node.h"
#include "Print.h"

class Builtins: public Node {

    public:
        Builtins(Indexer<Symbol>* tokens);
        ~Builtins();

        void construct();
        const string json(unsigned int indentSize = 1) const;

        Print *getPrint() const;

    private:
            Print* print;
};


#endif //BARZANE_BUILTINS_H
