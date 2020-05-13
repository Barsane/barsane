//
// Created by souls on 12/05/2020.
//

#ifndef BARZANE_DECLARATIONTEST_H
#define BARZANE_DECLARATIONTEST_H

#include "Test.h"
#include "expect.h"
#include <node/Declaration.h>

class DeclarationTest: public Test {

    public:
        void run();

    private:
        void getDeclaration_When_CurrentIsEmpty();
        void getDeclaration_When_NotConstruct();
        void getDeclaration_When_MissingColon();
        void getDeclaration_When_MissingSemiColon();
        void getDeclaration_When_MissingType();
        void getDeclaration_When_BadId();
        void positionChanged_WhenConstruct();
        void getDeclaration_When_OneId();
        void getDeclaration_When_MultipleId();
};


#endif //BARZANE_DECLARATIONTEST_H
