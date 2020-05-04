//
// Created by souls on 04/05/2020.
//

#ifndef BARZANE_PARSERTEST_H
#define BARZANE_PARSERTEST_H

#include "Test.h"
#include "expect.h"
#include "../include/Parser.h"
#include "../include/Lexer.h"
#include "../include/AST.h"
#include "../include/node/Declarations.h"
#include "../include/node/Affects.h"
#include "../include/node/Builtins.h"

class ParserTest: Test {

    public:
        void run();

    private:
        void getTree_When_LexerHasNotError();
        void raiseError_When_UnknownToken();
        void raiseError_When_MissingToken();

        void getTree_When_HasDecl();
        void getTree_When_HasAffect();
};


#endif //BARZANE_PARSERTEST_H
