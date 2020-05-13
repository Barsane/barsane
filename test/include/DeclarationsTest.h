//
// Created by souls on 13/05/2020.
//

#ifndef BARZANE_DECLARATIONSTEST_H
#define BARZANE_DECLARATIONSTEST_H

#include "Test.h"
#include "expect.h"
#include <node/Declarations.h>

class DeclarationsTest: public Test {

    public:
        void run();

    private:
        void getDeclarations_When_CurrentIsEmpty();
        void getDeclarations_When_NotConstruct();
        void positionChanged_WhenConstruct();
        void getDeclarations_When_OneDeclaration();
        void getDeclarations_When_MultipleDeclaration();
};

#endif //BARZANE_DECLARATIONSTEST_H
