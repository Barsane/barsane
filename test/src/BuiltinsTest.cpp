//
// Created by souls on 17/05/2020.
//

#include "../include/BuiltinsTest.h"

void BuiltinsTest::run() {
    getBuiltin_When_CurrentIsEmpty();
    getBuiltin_When_NotConstruct();
    getBuiltin_WhenPrint();
    positionChanged_When_Construct();
}

void BuiltinsTest::getBuiltin_When_CurrentIsEmpty() {
    vector<Symbol*> symbols = {};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Builtins* builtins = new Builtins(indexer);

    builtins->construct();

    expect("", builtins->getPrint() == 0);

    delete builtins;
}

void BuiltinsTest::getBuiltin_When_NotConstruct() {
    string key = "print";
    string expr = "x";
    string semicolon = ";";
    Symbol* symbolPrint = new Symbol(key, 1, 2);
    Symbol* symbolExpr = new Symbol(expr, 1, 5);
    Symbol* symbolSemicolon = new Symbol(semicolon, 1, 8);
    vector<Symbol*> symbols = {symbolPrint, symbolExpr, symbolSemicolon};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Builtins* builtins = new Builtins(indexer);

    expect("", builtins->getPrint() == 0);

    delete builtins;
}

void BuiltinsTest::getBuiltin_WhenPrint() {
    string key = "print";
    string expr = "x";
    string semicolon = ";";
    Symbol* symbolPrint = new Symbol(key, 1, 2);
    Symbol* symbolExpr = new Symbol(expr, 1, 5);
    Symbol* symbolSemicolon = new Symbol(semicolon, 1, 8);
    vector<Symbol*> symbols = {symbolPrint, symbolExpr, symbolSemicolon};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Builtins* builtins = new Builtins(indexer);

    builtins->construct();

    expectIf("", builtins->getPrint() != 0, [&]() {
       expect("", builtins->getPrint()->getExpression() != 0);
    });

    delete builtins;
}

void BuiltinsTest::positionChanged_When_Construct() {
    string key = "print";
    string expr = "x";
    string semicolon = ";";
    Symbol* symbolPrint = new Symbol(key, 1, 2);
    Symbol* symbolExpr = new Symbol(expr, 1, 5);
    Symbol* symbolSemicolon = new Symbol(semicolon, 1, 8);
    vector<Symbol*> symbols = {symbolPrint, symbolExpr, symbolSemicolon};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Builtins* builtins = new Builtins(indexer);

    unsigned int previous = indexer->position();
    builtins->construct();
    unsigned int current = indexer->position();

    expect("", current == previous + 3);

    delete builtins;
}
