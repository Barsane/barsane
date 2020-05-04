//
// Created by souls on 04/05/2020.
//

#ifndef BARZANE_AST_H
#define BARZANE_AST_H

#include "Node.h"
#include "node/Declarations.h"
#include "node/Affects.h"
#include "node/Builtins.h"


class AST: public Node {

    public:
        AST(Indexer<Symbol>& tokens);
        ~AST();

        void construct();

        Declarations* getDeclarations() const;
        Affects* getAffects() const;
        Builtins* getBuiltins() const;

    private:
        Declarations* declarations;
        Affects* affects;
        Builtins* builtins;
};

#endif //BARZANE_AST_H
