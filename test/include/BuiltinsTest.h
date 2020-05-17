//
// Created by souls on 17/05/2020.
//

#ifndef BARZANE_BUILTINSTEST_H
#define BARZANE_BUILTINSTEST_H

#include "Test.h"
#include "expect.h"
#include <node/Builtins.h>

class BuiltinsTest: Test {

    public:
        void run();

    private:
        void getBuiltin_When_CurrentIsEmpty();
        void getBuiltin_When_NotConstruct();
        void getBuiltin_WhenPrint();
        void positionChanged_When_Construct();
};


#endif //BARZANE_BUILTINSTEST_H
