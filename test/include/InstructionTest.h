//
// Created by souls on 18/05/2020.
//

#ifndef BARZANE_INSTRUCTIONTEST_H
#define BARZANE_INSTRUCTIONTEST_H

#include "Test.h"
#include "expect.h"
#include <node/Instruction.h>

class InstructionTest: public Test {

    public:
        void run();

    private:
        void getInstruction_When_CurrentIsEmpty();
        void getInstruction_When_NotConstruct();
        void positionChanged_When_Construct();
        void getInstruction_When_Declaration();
        void getInstruction_When_Affect();
        void getInstruction_When_Builtin();
        void getInstruction_When_BadToken();
};


#endif //BARZANE_INSTRUCTIONTEST_H
