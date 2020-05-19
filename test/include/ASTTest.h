//
// Created by souls on 17/05/2020.
//

#ifndef BARZANE_ASTTEST_H
#define BARZANE_ASTTEST_H

#include "Test.h"
#include "expect.h"
#include <AST.h>

class ASTTest: public Test {

    public:
        void run();

    private:
        void getTree_When_CurrentIsEmpty();
        void getTree_When_NotConstruct();
        void getTree_When_Instructions();
        void getTree_When_BadToken();
        void positionChanged_When_Construct();
};


#endif //BARZANE_ASTTEST_H
