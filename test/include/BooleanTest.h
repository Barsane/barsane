//
// Created by souls on 14/05/2020.
//

#ifndef BARZANE_BOOLEANTEST_H
#define BARZANE_BOOLEANTEST_H

#include <vector>
#include "Test.h"
#include "expect.h"
#include <node/Boolean.h>
#include <Symbol.h>
#include <Indexer.h>


class BooleanTest: public Test {

    public:
        void run();

    private:
        void getValue_When_CurrentIsEmpty();
        void getValue_When_NotConstruct();
        void getValue_When_CurrentIsTrue();
        void getValue_When_CurrentIsFalse();
        void getValue_When_BadToken();
        void positionChanged_When_Construct();
};


#endif //BARZANE_BOOLEANTEST_H
