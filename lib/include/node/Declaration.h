//
// Created by souls on 05/05/2020.
//

#ifndef BARZANE_DECLARATION_H
#define BARZANE_DECLARATION_H


#include "../Node.h"
#include "../Symbol.h"
#include "../Indexer.h"
#include "Ids.h"
#include "Type.h"

class Declaration: Node {

    public:
        Declaration(Indexer<Symbol>* tokens);
        virtual ~Declaration();

        void construct();
        const string json(unsigned int indentSize = 1) const;

        Ids* getIds() const;
        Type* getType();

    private:
        Ids* ids;
        Type* type;

};


#endif //BARZANE_DECLARATION_H
