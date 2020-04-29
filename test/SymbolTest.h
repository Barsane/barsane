//
// Created by souls on 29/04/2020.
//

#ifndef BARZANE_SYMBOLTEST_H
#define BARZANE_SYMBOLTEST_H

#include "Test.h"

class SymbolTest: public Test {

    public:
        void run();

    private:
        void symbolIsValue_When_TokenIs();
        void symbolIsId_When_TokenIs();
        void symbolIsDoubleQuotation_When_TokenIs();
        void symbolIsType_When_TokenIs();
        void symbolIsComa_When_TokenIs();
        void symbolIsColon_When_TokenIs();
        void symbolIsSemiColon_When_TokenIs();
        void symbolIsMinus_When_TokenIs();
        void symbolIsLeftBracket_When_TokenIs() ;
        void symbolIsRightBracket_When_TokenIs();
        void symbolIsTermOperator_When_TokenIs();
        void symbolIsOperationOperator_When_TokenIs();
        void symbolIsAssignment_When_TokenIs();
        void symbolIsPrint_When_TokenIs();

        void getToken_When_TokenIs();
        void getType_When_TokenIs();
        void getLine_When_ItIs();
        void getColon_When_ItIs();
};


#endif //BARZANE_SYMBOLTEST_H
