//
// Created by souls on 05/05/2020.
//

#ifndef BARZANE_NUMBER_H
#define BARZANE_NUMBER_H

#include "../Node.h"
#include "../str.h"

namespace NumberType {
    enum type {
        INTEGER,
        REAL,
        UNDEFINED
    };
}

/**
 * number: [0-9\.]+
 */
class Number: public Node {

    public:
        Number(Indexer<Symbol>& tokens);
        virtual ~Number();

        void construct();

        const string json(unsigned int indentSize = 1) const;

        int *getInteger() const;
        float *getReal() const;
        NumberType::type getType() const;

    private:
        int *integer;
        float *real;
        NumberType::type type;

        void evaluate();
};


#endif //BARZANE_NUMBER_H
