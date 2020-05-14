//
// Created by souls on 29/04/2020.
//

#include <iostream>
#include "../include/expect.h"
#include "../include/SymbolTest.h"
#include "../include/IndexerTest.h"
#include "../include/ErrorHandlerTest.h"
#include "../include/StrTest.h"
#include "../include/LexerTest.h"
#include "../include/NumberTest.h"
#include "../include/IdTest.h"
#include "../include/TypeTest.h"
#include "../include/IdsTest.h"
#include "../include/DeclarationTest.h"
#include "../include/DeclarationsTest.h"
#include "../include/FactorTest.h"
#include "../include/TermTest.h"
#include "../include/OperationTest.h"
#include "../include/BooleanTest.h"
#include "../include/StringTest.h"
#include "../include/ExpressionTest.h"

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
    StrTest().run();
    ErrorHandlerTest().run();
    LexerTest().run();
    NumberTest().run();
    IdTest().run();
    TypeTest().run();
    IdsTest().run();
    DeclarationTest().run();
    DeclarationsTest().run();
    FactorTest().run();
    TermTest().run();
    OperationTest().run();
    BooleanTest().run();
    StringTest().run();
    ExpressionTest().run();

    print_rst();

    return 0;
}