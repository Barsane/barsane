//
// Created by souls on 29/04/2020.
//

#include <iostream>
#include "expect.h"
#include "SymbolTest.h"
#include "IndexerTest.h"
#include "ErrorHandlerTest.h"

using namespace std;

void testExpect() {
    char* var = getenv("TEST_EXPECT");
    string value = var == NULL ? "false" : var;
    if (value == "true") {
        expect("Should be OK",  1 == 1);
        expect("Should be OK", "Hello" == "Hello");
        expect("Should be not OK", "!=&" == "x");
    }
}

int main() {
    testExpect();

    SymbolTest().run();
    IndexerTest().run();
    ErrorHandlerTest().run();

    print_rst();

    return 0;
}