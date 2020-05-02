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
    expect(", token type should be COMA", symbolComa.isComa());
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
    string minus = "-";
    Symbol symbolMinus = Symbol(minus, 1, 1);
    expect("- token type should be MINUS", symbolMinus.isMinus());
}

void SymbolTest::symbolIsLeftBracket_When_TokenIs()  {
    string leftBracket = "(";
    Symbol symbolLeftBracket = Symbol(leftBracket, 1, 1);
    expect("( token type should be LEFT_BRACKET", symbolLeftBracket.isLeftBracket());
}

void SymbolTest::symbolIsRightBracket_When_TokenIs() {
    string rightBracket = ")";
    Symbol symbolRightBracket = Symbol(rightBracket, 1, 1);
    expect(") token type should be RIGHT_BRACKET", symbolRightBracket.isRightBracket());
}

void SymbolTest::symbolIsTermOperator_When_TokenIs() {
    string minus = "*";
    Symbol symbolMinus = Symbol(minus, 1, 1);
    expect("* token type should be term operator", symbolMinus.isTermOperator());

    string plus = "+";
    Symbol symbolPlus = Symbol(plus, 1, 1);
    expect("+ token type should be term operator", symbolPlus.isTermOperator());
}

void SymbolTest::symbolIsOperationOperator_When_TokenIs() {
    string minus = "-";
    Symbol symbolMinus = Symbol(minus, 1, 1);
    expect("- token type should be operation operator", symbolMinus.isOperationOperator());

    string plus = "+";
    Symbol symbolPlus = Symbol(plus, 1, 1);
    expect("+ token type should be operation operator", symbolPlus.isOperationOperator());
}

void SymbolTest::symbolIsAssignment_When_TokenIs() {
    string assignment = "=";
    Symbol symbolAssignment = Symbol(assignment, 1, 1);
    expect("= token type should be assignment", symbolAssignment.isAssignment());
}

void SymbolTest::symbolIsPrint_When_TokenIs() {
    string print = "print";
    Symbol symbolPrint = Symbol(print, 1, 1);
    expect("print token type should be PRINT", symbolPrint.isPrint());
}

void SymbolTest::getToken_When_TokenIs() {
    vector<string> tokens = {"print", "=", ",", ":", ";", "+", "-", "hello", "\"hello world\"", "1"};
    for (auto token : tokens) {
        Symbol symbol = Symbol(token, 1, 1);
        expect(token + " should be itself", symbol.getToken() == token);
    }
}

void SymbolTest::getType_When_TokenIs() {
    map<string, SymbolType> tokens;

    tokens["print"] = PRINT;
    tokens["="] = ASSIGNMENT;
    tokens[","] = COMA;
    tokens[":"] = COLON;
    tokens[";"] = SEMI_COLON;
    tokens["+"] = OPERATION_OPERATOR;
    tokens["-"] = OPERATION_OPERATOR;
    tokens["*"] = TERM_OPERATOR;
    tokens["/"] = TERM_OPERATOR;
    tokens["("] = LEFT_BRACKET;
    tokens[")"] = RIGHT_BRACKET;
    tokens["number"] = TYPE;
    tokens["boolean"] = TYPE;
    tokens["string"] = TYPE;
    tokens["123"] = VALUE;
    tokens["\"Barzane\""] = VALUE;
    tokens["true"] = VALUE;
    tokens["false"] = VALUE;
    tokens["cou"] = ID;
    tokens["ùµpmr"] = UNKNOWN;
    tokens["1g"] = UNKNOWN;

    for (auto token : tokens) {
        string str = token.first;
        SymbolType type = token.second;
        Symbol symbol = Symbol(str, 1, 1);
        expect(str + " should be expected type",
                symbol.getType() == type && Symbol::typeOf(str) == type);
    }
}

void SymbolTest::getStringType_When_TypeIs() {
    map<string, SymbolType> types;

    types["PRINT"] = PRINT;
    types["ASSIGNMENT"] = ASSIGNMENT;
    types["COMA"] = COMA;
    types["COLON"] = COLON;
    types["SEMI_COLON"] = SEMI_COLON;
    types["OPERATION_OPERATOR"] = OPERATION_OPERATOR;
    types["TERM_OPERATOR"] = TERM_OPERATOR;
    types["LEFT_BRACKET"] = LEFT_BRACKET;
    types["RIGHT_BRACKET"] = RIGHT_BRACKET;
    types["TYPE"] = TYPE;
    types["VALUE"] = VALUE;
    types["ID"] = ID;
    types["UNKNOWN"] = UNKNOWN;

    for (auto type : types) {
        expect("Representative type",
                Symbol::stringOf(type.second) == type.first);
    }
}

void SymbolTest::getLine_When_ItIs() {
    string number = "number";
    Symbol symbolNumber = Symbol(number, 1, 1);
    expect("Line should be 1", symbolNumber.getLine() == 1);

    string boolTrue = "true";
    Symbol symbolBoolTrue = Symbol(boolTrue, 1000, 1);
    expect("Line should be 1000", symbolNumber.getLine() == 1000);
}

void SymbolTest::getColon_When_ItIs() {
    string number = "number";
    Symbol symbolNumber = Symbol(number, 1, 1546);
    expect("Colon should be 1546", symbolNumber.getColon() == 1546);

    string boolTrue = "true";
    Symbol symbolBoolTrue = Symbol(boolTrue, 1000, 33);
    expect("Colon should be 33", symbolNumber.getColon() == 33);
}

void SymbolTest::catchException_When_LineIsLessThanOne() {
    bool caught = false;
    string token = "token";
    try {
        Symbol badToken = Symbol(token, 0, 1);
    } catch (...) {
        caught = true;
    }

    expect("Attempt to catch an error", caught == true);

}

void SymbolTest::catchException_When_ColonIsLessThanOne() {
    bool caught = false;
    string token = "token";
    try {
        Symbol badToken = Symbol(token, 2, 0);
    } catch (...) {
        caught = true;
    }

    expect("Attempt to catch an error", caught == true);
}

void SymbolTest::run() {
    symbolIsValue_When_TokenIs();
    symbolIsId_When_TokenIs();
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
    getStringType_When_TypeIs();
    getLine_When_ItIs();
    getColon_When_ItIs();

    catchException_When_LineIsLessThanOne();
    catchException_When_ColonIsLessThanOne();
}
