//
// Created by souls on 09/05/2020.
//

#ifndef BARZANE_TYPETEST_H
#define BARZANE_TYPETEST_H

#include "Test.h"
#include "expect.h"
#include <node/Type.h>

class TypeTest: public Test {

    public:
        void run();

    private:
        void getType_When_CurrentIsEmpty();
        void getType_When_NotConstruct();
        void positionChanged_WhenConstruct();
        void getType_When_CurrentIsNumber();
        void getType_When_CurrentIsBoolean();
        void getType_When_CurrentIsString();
        void getType_When_BadToken();
};


#endif //BARZANE_TYPETEST_H
