//
// Created by souls on 14/05/2020.
//

#ifndef BARZANE_EXPRESSIONTEST_H
#define BARZANE_EXPRESSIONTEST_H

#include "Test.h"
#include "expect.h"
#include <node/Expression.h>
#include <vector>
#include <Indexer.h>
#include <Symbol.h>

class ExpressionTest: public Test {

    public:
        void run();

    private:
        void getValue_When_CurrentIsEmpty();
        void getValue_When_NotConstruct();
        void getValue_When_CurrentIsOperation();
        void getValue_When_CurrentIsBoolean();
        void getValue_When_CurrentIsString();
        void getValue_When_BadToken();
        void positionChanged_When_Construct();

};


#endif //BARZANE_EXPRESSIONTEST_H
