//
// Created by souls on 13/05/2020.
//

#ifndef BARZANE_TERMTEST_H
#define BARZANE_TERMTEST_H

#include "Test.h"
#include "expect.h"
#include <node/Term.h>
#include <node/Operation.h>

/**
 * term: {factor} ("*" | "/") {term} | {factor}
 */
class TermTest: public Test {

    public:
        void run();

    private:
        void getTerm_When_CurrentIsEmpty();
        void getTerm_When_NotConstruct();
        void getTerm_When_BadToken();
        void positionChanged_WhenConstruct();
        void getTerm_When_CurrentIsMinus();
        void getTerm_When_CurrentIsLeftBracket();
        void getTerm_When_CurrentIsId();
        void getTerm_When_CurrentIsNumber();
        void getTerm_When_MissingLeftFactor();
        void getTerm_When_MissingRightFactor();
        void getTerm_When_MissingOperator();
        void getTerm_When_OnlyFactor();
        void getTerm_When_NestedDeep();
};


#endif //BARZANE_TERMTEST_H
