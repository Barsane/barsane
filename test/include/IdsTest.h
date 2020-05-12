//
// Created by souls on 10/05/2020.
//

#ifndef BARZANE_IDSTEST_H
#define BARZANE_IDSTEST_H

#include "Test.h"
#include "expect.h"
#include <node/Ids.h>

class IdsTest: public Test {

    public:
        void run();

    private:
        void getIds_When_CurrentIsEmpty();
        void getIds_When_NotConstruct();
        void getIds_When_MissingComa();
        void positionChanged_WhenConstruct();
        void getIds_When_OneId();
        void getIds_When_MultipleId();
};


#endif //BARZANE_IDSTEST_H
