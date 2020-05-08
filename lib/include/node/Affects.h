//
// Created by souls on 04/05/2020.
//

#ifndef BARZANE_AFFECTS_H
#define BARZANE_AFFECTS_H

#include "../Node.h"
#include "Affect.h"

class Affects: public Node {

    public:
        Affects(Indexer<Symbol>& tokens);
        ~Affects();

        void construct();
        const string str(unsigned int indentSize = 1) const;

        Affect *getAffect() const;
        Affects *getAffects() const;

    private:
        Affect* affect;
        Affects* affects;

        bool isNextAffect();
};


#endif //BARZANE_AFFECTS_H
