//
// Created by souls on 05/05/2020.
//

#ifndef BARZANE_NUMBER_H
#define BARZANE_NUMBER_H


#include "../Node.h"
#include <string>
#include <sstream>
#include <algorithm>

class Number: public Node {

    public:
        Number(Indexer<Symbol>& tokens);
        virtual ~Number();

        void construct();

        const string str(unsigned int indentSize = 1) const;

        int *getInteger() const;
        float *getReal() const;

    private:
        int *integer;
        float *real;
};


#endif //BARZANE_NUMBER_H
