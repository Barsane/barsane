//
// Created by souls on 30/04/2020.
//

#include "LexerTest.h"

void LexerTest::getLength_When_TextIs() {
    // Given
    string text = "x: number;\nx = 1;\nprint x;";
    Lexer lexer = Lexer(text);

    // Then
    expect("Lexer length should be 11", lexer.length() == 11);
}

void LexerTest::getTokens_When_TextIs() {

    // Given
    string text = "x: number;\nx = 1;\nprint x;";
    Lexer lexer = Lexer(text);

    string id = "x";
    Symbol symbolId11 = Symbol(id, 1, 1);
    Symbol symbolId21 = Symbol(id, 2, 1);
    Symbol symbolId37 = Symbol(id, 3, 7);

    string colon = ":";
    Symbol colon12 = Symbol(colon, 1, 2);

    string semiColon = ";";
    Symbol semiColon110 = Symbol(semiColon, 1, 10);
    Symbol semiColon26 = Symbol(semiColon, 2, 6);
    Symbol semiColon38 = Symbol(semiColon, 3, 8);

    string type = "number";
    Symbol symbolType = Symbol(type, 1, 4);

    string assignment = "=";
    Symbol assignment23 = Symbol(assignment, 2, 3);

    string value = "1";
    Symbol value25 = Symbol(value, 2, 5);

    string print = "print";
    Symbol print31 = Symbol(print, 3, 8);

    vector<Symbol> tokens = {
            symbolId11,
            symbolId21,
            symbolId37,
            colon12,
            semiColon110,
            semiColon26,
            semiColon38,
            symbolType,
            assignment23,
            value25,
            print31
    };

    //Then
    /*for (auto symbol : tokens) {
        lexer.getTokens().
        expect("Lexer has a token whose value is " + symbol.getToken(),
                )
    }*/
    expect("Lexer length should be 11", lexer.length() == 11);
}

void LexerTest::catchException_When_MatchUnknownType() {
}

void LexerTest::run() {
    getLength_When_TextIs();
    getTokens_When_TextIs();
    catchException_When_MatchUnknownType();
}