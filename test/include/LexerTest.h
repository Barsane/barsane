//
// Created by souls on 30/04/2020.
//

#ifndef BARZANE_LEXERTEST_H
#define BARZANE_LEXERTEST_H


#include <vector>
#include <algorithm>
#include "Test.h"
#include "expect.h"
#include "../include/Lexer.h"
#include "../include/Symbol.h"

using namespace std;

class LexerTest: public Test {

    public:
        void run();

    private:
        void getTokens_When_TextIs();
        void getLength_When_TextIs();

        // Rule: None of token must be UNKNOWN type.
        void raiseError_When_InvalidChar();
};



#endif //BARZANE_LEXERTEST_H
