//
// Created by souls on 18/05/2020.
//

#ifndef BARZANE_INSTRUCTIONSTEST_H
#define BARZANE_INSTRUCTIONSTEST_H

#include "Test.h"
#include "expect.h"
#include <node/Instructions.h>

class InstructionsTest: public Test {
    public:
        void run();

    private:
        void getInstructions_When_CurrentIsEmpty();
        void getInstructions_When_NotConstruct();
        void getInstructions_When_OneInstr();
        void getInstructions_When_MultipleInstrs();
        void positionChanged_When_Construct();
};


#endif //BARZANE_INSTRUCTIONSTEST_H
