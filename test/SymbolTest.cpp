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
    string doubleQuotation = "\"";
    Symbol symbolDoubleQuot = Symbol(doubleQuotation, 1, 1);
    expect("\" token type should be DOUBLE_QUOTATION",
            symbolDoubleQuot.isDoubleQuotation());

    string quotation = "'";
    Symbol symbolQuot = Symbol(quotation, 4, 5);
    expect("\" token type should not be DOUBLE_QUOTATION",
           !symbolQuot.isDoubleQuotation());

    string backQuotation = "`";
    Symbol symbolBackQuotation = Symbol(backQuotation, 2, 3);
    expect("` token type should not be DOUBLE_QUOTATION",
           !symbolDoubleQuot.isDoubleQuotation());
}

void SymbolTest::symbolIsType_When_TokenIs() {
    string number = "number";
    string boolean = "boolean";
    string str = "string";

    Symbol symbolNumber = Symbol(number, 1, 1);
    Symbol symbolBoolean = Symbol(boolean, 1, 1);
    Symbol symbolStr = Symbol(str, 1, 1);

    expect("number token type should be TYPE", symbolNumber.isType());
    expect("boolean token type should be TYPE", symbolBoolean.isType());
    expect("string token type should be TYPE", symbolStr.isType());
}

void SymbolTest::symbolIsComa_When_TokenIs() {
    string coma = ",";
    Symbol symbolComa = Symbol(coma, 1, 1);
    expect(", token type should be COLON", symbolComa.isComa());
}

void SymbolTest::symbolIsColon_When_TokenIs() {
    string colon = ":";
    Symbol symbolColon = Symbol(colon, 1, 1);
    expect(": token type should be COLON", symbolColon.isColon());
}

void SymbolTest::symbolIsSemiColon_When_TokenIs() {
    string semiColon = ";";
    Symbol symbolSemiColon = Symbol(semiColon, 1, 1);
    expect("; token type should be SEMI_COLON", symbolSemiColon.isSemiColon());
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
