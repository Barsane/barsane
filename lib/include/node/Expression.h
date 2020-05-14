//
// Created by souls on 14/05/2020.
//

#ifndef BARZANE_EXPRESSION_H
#define BARZANE_EXPRESSION_H


#include "../Symbol.h"
#include "../Node.h"
#include "Boolean.h"
#include "Operation.h"
#include "String.h"

/*
 * expression: {operation} | {string} | {boolean}
 */
class Expression: public Node {
    public:
        Expression(Indexer<Symbol>* tokens);

        virtual ~Expression();

        void construct();

        const string json(unsigned int indentSize = 1) const;

        Operation *getOperation() const;

        String *getStringExpr() const;

        Boolean* getBoolean() const;

    private:
      Operation* operation;
      String* stringExpr;
      Boolean* boolean;
};


#endif //BARZANE_EXPRESSION_H
