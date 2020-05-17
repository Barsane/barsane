//
// Created by souls on 05/05/2020.
//

#ifndef BARZANE_AFFECT_H
#define BARZANE_AFFECT_H


#include "../Node.h"
#include "Id.h"
#include "Expression.h"

class Affect: public Node {
    public:
        Affect(Indexer<Symbol>* tokens);
        virtual ~Affect();

        void construct();
        const string json(unsigned int indentSize = 1) const;

        Id* getId() const;

        Expression *getExpression() const;

    private:
        Id* id;
        Expression* expression;
};


#endif //BARZANE_AFFECT_H
