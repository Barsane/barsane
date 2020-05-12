//
// Created by souls on 10/05/2020.
//

#ifndef BARZANE_IDS_H
#define BARZANE_IDS_H


#include "../Node.h"
#include "Id.h"
#include <string>

class Ids: public Node {

    public:
        Ids(Indexer<Symbol>* tokens);
        virtual ~Ids();

        void construct();
        const string json(unsigned int indentSize = 1) const;

        Id *getId() const;
        Ids *getIds() const;

    private:
        Id* id;
        Ids* ids;
};


#endif //BARZANE_IDS_H
