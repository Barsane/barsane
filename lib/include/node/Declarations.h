//
// Created by souls on 04/05/2020.
//

#ifndef BARZANE_DECLARATIONS_H
#define BARZANE_DECLARATIONS_H

#include "../Node.h"
#include "Declaration.h"

class Declarations: public Node {

    public:
        Declarations(Indexer<Symbol>* tokens);
        ~Declarations();

        void construct();

        const string json(unsigned int indentSize = 1) const;

        Declaration *getDeclaration() const;
        Declarations *getDeclarations() const;

    private:
        Declaration* declaration;
        Declarations* declarations;

        bool isNextDecl();
};


#endif //BARZANE_DECLARATIONS_H
