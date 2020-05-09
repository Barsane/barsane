//
// Created by souls on 09/05/2020.
//

#ifndef BARZANE_NUMBERTEST_H
#define BARZANE_NUMBERTEST_H

#include <string>
#include <vector>
#include "Test.h"
#include "expect.h"
#include <Lexer.h>
#include <node/Number.h>

using namespace std;

class NumberTest: public Test {

    public:
        void run();

    private:
        void getNumber_When_IndexerIsEmpty();
        void getNumber_When_CurrentIsNotCatchable();
        void getNumber_When_CurrentIsDigit();
        void getNumber_When_CurrentIsReal();
        void getNumber_When_NotConstruct();
        void getNumber_When_BadReal();
        void positionChanged_WhenConstruct();
};


#endif //BARZANE_NUMBERTEST_H
