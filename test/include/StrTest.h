//
// Created by souls on 02/05/2020.
//

#ifndef BARZANE_STRTEST_H
#define BARZANE_STRTEST_H

#include <map>
#include <vector>
#include "Test.h"
#include "expect.h"
#include "../include/str.h"

// TODO: Test case when numeric ends up with "." (should not be accepted).

class StrTest: public Test{

    public:
        void run();

    private:
        void getType_When_KeyIs();
        void getValue_When_KeyIs();

        void strIsSpace_When_KeyIs();
        void strIsNumeric_When_KeyIs();
        void strIsAlphaUnd_When_KeyIs();
        void strIsAlphaNumUnd_WHen_KeyIs();
        void strIsSpecial_When_KeyIs();
        void strIsExpression_When_KeyIs();
};


#endif //BARZANE_STRTEST_H
