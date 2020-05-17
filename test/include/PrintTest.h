//
// Created by souls on 17/05/2020.
//

#ifndef BARZANE_PRINTTEST_H
#define BARZANE_PRINTTEST_H

#include "Test.h"
#include "expect.h"
#include <node/Print.h>

class PrintTest: public Test {

    public:
        void run();

    private:
        void getPrint_When_CurrentIsEmpty();
        void getPrint_When_NotConstruct();
        void positionChanged_When_Construct();
        void getPrint_When_MissingKeyword();
        void getPrint_When_MissingExpr();
        void getPrint_When_MissingSemicolon();
        void getPrint_When_BadKeyword();
        void getPrint_When_BadExpr();
        void getPrint_When_Ok();
};


#endif //BARZANE_PRINTTEST_H
