//
// Created by souls on 13/05/2020.
//

#ifndef BARZANE_FACTORTEST_H
#define BARZANE_FACTORTEST_H

#include <vector>
#include "Test.h"
#include "expect.h"
#include <node/Factor.h>

/**
 * factor: ["-"] {id} | ["-"] {number} | "(" {operation} ")"
 */
class FactorTest: Test {

    public:
        void run();

    private:
        void getFactor_When_CurrentIsEmpty();
        void getFactor_When_NotConstruct();
        void getFactor_When_BadToken();
        void positionChanged_WhenConstruct();
        void getFactor_When_CurrentIsMinus();
        void getFactor_When_CurrentIsLeftBracket();
        void getFactor_When_CurrentIsId();
        void getFactor_When_CurrentIsNumber();
};


#endif //BARZANE_FACTORTEST_H
