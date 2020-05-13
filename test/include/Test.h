//
// Created by souls on 29/04/2020.
//

#ifndef BARZANE_TEST_H
#define BARZANE_TEST_H

#include <string>
#include "expect.h"


class Test {

    public:
        virtual void run() = 0;
};

template<typename F> void expectIf(std::string description, bool cond, F func) {
    expect(description, cond);
    if (cond)
        func();
}

#endif //BARZANE_TEST_H
