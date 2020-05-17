//
// Created by souls on 16/05/2020.
//

#ifndef BARZANE_AFFECTSTEST_H
#define BARZANE_AFFECTSTEST_H


#include "Test.h"
#include "expect.h"
#include <node/Affects.h>

class AffectsTest: public Test {

    public:
        void run();

    private:
        void getAffects_When_CurrentIsEmpty();
        void getAffects_When_NotConstruct();
        void positionChanged_When_Construct();
        void getAffects_When_OneAffect();
        void getAffects_When_MultipleAffects();
        void getAffects_When_BadId();
};


#endif //BARZANE_AFFECTSTEST_H
