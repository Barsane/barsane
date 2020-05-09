//
// Created by souls on 09/05/2020.
//

#ifndef BARZANE_IDTEST_H
#define BARZANE_IDTEST_H


#include "Test.h"
#include "expect.h"
#include <node/Id.h>


class IdTest: public Test {

    public:
        void run();

    private:
        void getId_When_CurrentIsEmpty();
        void getId_When_NotConstruct();
        void getId_When_BadToken();
        void positionChanged_WhenConstruct();
        void getName_When_CurrentIs();
};


#endif //BARZANE_IDTEST_H
