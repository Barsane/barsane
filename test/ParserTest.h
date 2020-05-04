//
// Created by souls on 04/05/2020.
//

#ifndef BARZANE_PARSERTEST_H
#define BARZANE_PARSERTEST_H

#include "Test.h"

class ParserTest: Test {

    public:
        void run();

    private:
        void getTree_When_LexerHasNotError();
        void getTree_When_HasErrors();
        void raiseError_When_UnknownToken();
        void raiseError_When_MissingToken();

        void getTree_When_HasDecl();
        void getTree_When_HasAffect();
        void getTree_When_HasPrint();
        void getTree_When_HasAllStatement();
        void getTree_When_NoneStatement();

};


#endif //BARZANE_PARSERTEST_H
