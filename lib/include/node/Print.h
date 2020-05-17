//
// Created by souls on 05/05/2020.
//

#ifndef BARZANE_PRINT_H
#define BARZANE_PRINT_H

#include "../Node.h"
#include "Expression.h"

class Print: public Node {

    public:
        Print(Indexer<Symbol>* tokens);
        virtual ~Print();

        void construct();

        const string json(unsigned int indentSize = 1) const;

        Expression *getExpression() const;

    private:
        Expression* expression;
};


#endif //BARZANE_PRINT_H
