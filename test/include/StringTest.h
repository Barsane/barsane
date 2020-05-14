//
// Created by souls on 14/05/2020.
//

#ifndef BARZANE_STRINGTEST_H
#define BARZANE_STRINGTEST_H

#include "Test.h"
#include "expect.h"
#include <vector>
#include <node/String.h>

class StringTest: public Test {

    public:
        void run();

    private:
        void getValue_When_CurrentIsEmpty();
        void getValue_When_NotConstruct();
        void getValue_When_CurrentIs();
        void getValue_When_CurrentMissingLeftQuote();
        void getValue_When_CurrentMissingRightQuote();
        void getValue_When_BadToken();
        void positionChanged_When_Construct();
        void getValue_When_SingleQuote();
};


#endif //BARZANE_STRINGTEST_H
