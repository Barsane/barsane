//
// Created by souls on 29/04/2020.
//

#include "SymbolTest.h"


void SymbolTest::symbolIsValue_When_TokenIs() {
    // Test number
    string twelve = "12";
    Symbol symbolTwelve = Symbol(twelve, 50, 50);
    expect("12 token type Should be VALUE", symbolTwelve.isValue());

    // Test boolean
    string boolTrue = "true";
    string boolFalse = "false";
    Symbol symbolBoolTrue = Symbol(boolTrue, 1, 1);
    Symbol symbolBoolFalse = Symbol(boolFalse, 50, 50);
    expect("true token type should be VALUE", symbolBoolTrue.isValue());
    expect("false token type should be VALUE", symbolBoolFalse.isValue());

    // Test string
    string expr = "\"%£$\tbgoier1\nngbre( pm\"";
    Symbol symbolExpr = Symbol(expr, 12, 1);
    expect("\"%£$\\tbgoier1\\nngbre( pm\" token type should be VALUE",
            symbolExpr.isValue());

    // Out of scope
    string outOfScope = "abc";
    Symbol symbolOutOfScope = Symbol(outOfScope, 5, 1);
    expect("abc token type should not be VALUE",
            !symbolOutOfScope.isValue());
}

void SymbolTest::symbolIsId_When_TokenIs() {
    string smallId = "x";
    Symbol symbolSmallId = Symbol(smallId, 3, 4);
    expect("x token type Should be VALUE", symbolSmallId.isId());

    string simpleId = "y_name";
    Symbol symbolSimpleId = Symbol(simpleId, 4, 5);
    expect("y_name token type Should be ID", symbolSimpleId.isId());

    string startedWithNum = "1p";
    Symbol symbolStartedWithNum = Symbol(startedWithNum, 3, 4);
    expect("1p token type Should not be ID",
            !symbolStartedWithNum.isId());

    string specialCharIn = "hel%";
    Symbol symbolSpecialCharIn = Symbol(specialCharIn, 3, 4);
    expect("hel% token type Should not be ID",
            !symbolStartedWithNum.isId());

}

void SymbolTest::symbolIsDoubleQuotation_When_TokenIs() {

}
void SymbolTest::symbolIsType_When_TokenIs() {

}
void SymbolTest::symbolIsComa_When_TokenIs() {

}
void SymbolTest::symbolIsColon_When_TokenIs() {

}
void SymbolTest::symbolIsSemiColon_When_TokenIs() {

}
void SymbolTest::symbolIsMinus_When_TokenIs() {

}
void SymbolTest::symbolIsLeftBracket_When_TokenIs()  {

}
void SymbolTest::symbolIsRightBracket_When_TokenIs() {

}
void SymbolTest::symbolIsTermOperator_When_TokenIs() {

}
void SymbolTest::symbolIsOperationOperator_When_TokenIs() {

}
void SymbolTest::symbolIsAssignment_When_TokenIs() {

}
void SymbolTest::symbolIsPrint_When_TokenIs() {

}

void SymbolTest::getToken_When_TokenIs() {

}
void SymbolTest::getType_When_TokenIs() {

}
void SymbolTest::getLine_When_ItIs() {

}
void SymbolTest::getColon_When_ItIs() {

}

void SymbolTest::run() {
    symbolIsValue_When_TokenIs();
    symbolIsId_When_TokenIs();
    symbolIsDoubleQuotation_When_TokenIs();
    symbolIsType_When_TokenIs();
    symbolIsComa_When_TokenIs();
    symbolIsColon_When_TokenIs();
    symbolIsSemiColon_When_TokenIs();
    symbolIsMinus_When_TokenIs();
    symbolIsLeftBracket_When_TokenIs() ;
    symbolIsRightBracket_When_TokenIs();
    symbolIsTermOperator_When_TokenIs();
    symbolIsOperationOperator_When_TokenIs();
    symbolIsAssignment_When_TokenIs();
    symbolIsPrint_When_TokenIs();

    getToken_When_TokenIs();
    getType_When_TokenIs();
    getLine_When_ItIs();
    getColon_When_ItIs();
}
