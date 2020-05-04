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
    Symbol print31 = Symbol(print, 3, 1);

    // "x: number;\nx = 1;\nprint x;";
    vector<Symbol> tokens = {
            symbolId11,
            colon12,
            symbolType,
            semiColon110,
            symbolId21,
            assignment23,
            value25,
            semiColon26,
            print31,
            symbolId37,
            semiColon38
    };

    //Then
    Indexer<Symbol>* symbols = lexer.getTokens();
    while (!symbols->end()) {
        Symbol* symbol = symbols->current();
        vector<Symbol>::iterator it = find_if(tokens.begin(), tokens.end(),
                [symbol] (const Symbol& s) { return s.getToken() == symbol->getToken() &&
                                                         s.getLine() == symbol->getLine() &&
                                                         s.getColon() == symbol->getColon();}
        );
        expect("Token " + symbol->getToken() + " should be found",
               it != tokens.end());
        symbols->next();
    }
}

void LexerTest::raiseError_When_InvalidChar() {
    bool caught = false;
    string text = "x: µnumber;\nx = 1;\nprint x;";

    Lexer lexer = Lexer(text);

    expect("An error should be raised", lexer.hasErrors());
}

void LexerTest::run() {
    getLength_When_TextIs();
    getTokens_When_TextIs();
    raiseError_When_InvalidChar();
}