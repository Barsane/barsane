//
// Created by souls on 29/04/2020.
//

#include <iostream>
#include "expect.h"
#include "SymbolTest.h"

using namespace std;

void testExpect() {
    string value(getenv("TEST_EXPECT"));
    if (value == "true") {
        expect("Should be OK",  1 == 1);
        expect("Should be OK", "Hello" == "Hello");
        expect("Should be not OK", "!=&" == "x");
    }
}

int main() {
    testExpect();
    SymbolTest().run();
    return 0;
}