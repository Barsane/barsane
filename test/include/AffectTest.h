//
// Created by souls on 15/05/2020.
//

#ifndef BARZANE_AFFECTTEST_H
#define BARZANE_AFFECTTEST_H

#include "Test.h"
#include "expect.h"
#include <node/Affect.h>

/**
 * affect: {id} "=" {expression} ";"
 */
class AffectTest: public Test {

    public:
        void run();

    private:
        void getAffect_When_CurrentIsEmpty();
        void getAffect_When_NotConstruct();
        void positionChanged_When_Construct();
        void getAffect_When_MissingId();
        void getAffect_When_MissingEqual();
        void getAffect_When_MissingExpression();
        void getAffect_When_MissingSemicolon();
        void getAffect_When_BadId();
        void getAffect_When_BadAfterId();
        void getAffect_When_BadExpression();
};


#endif //BARZANE_AFFECTTEST_H
