//
// Created by souls on 13/05/2020.
//

#ifndef BARZANE_OPERATIONTEST_H
#define BARZANE_OPERATIONTEST_H

#include "Test.h"
#include "expect.h"
#include <node/Operation.h>

class OperationTest: public Test {

    public:
        void run();

    private:
        void getOperation_When_CurrentIsEmpty();
        void getOperation_When_NotConstruct();
        void getOperation_When_BadToken();
        void positionChanged_WhenConstruct();
        void getOperation_When_CurrentIsMinus();
        void getOperation_When_CurrentIsLeftBracket();
        void getOperation_When_CurrentIsId();
        void getOperation_When_CurrentIsNumber();
        void getOperation_When_MissingTerm();
        void getOperation_When_MissingOperation();
        void getOperation_When_MissingOperator();
        void getOperation_When_OnlyTerm();
};


#endif //BARZANE_OPERATIONTEST_H
