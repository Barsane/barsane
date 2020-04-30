//
// Created by souls on 30/04/2020.
//

#ifndef BARZANE_ERRORHANDLERTEST_H
#define BARZANE_ERRORHANDLERTEST_H

#include "Test.h"
#include "expect.h"
#include "../include/ErrorHandler.h"
#include "../include/Error.h"

class ErrorHandlerTest: public Test {

    public:
        void run();

    private:
        void verifyEmpty_WhenAdd();
        void verifyEmpty_When_Initiate();
        void getErrors_When_Empty();
        void getErrors_WhenAdd();


};


#endif //BARZANE_ERRORHANDLERTEST_H
