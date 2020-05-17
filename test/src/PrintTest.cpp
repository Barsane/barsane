//
// Created by souls on 17/05/2020.
//

#include "../include/PrintTest.h"

void PrintTest::run() {
    getPrint_When_CurrentIsEmpty();
    getPrint_When_NotConstruct();
    positionChanged_When_Construct();
    getPrint_When_MissingKeyword();
    getPrint_When_MissingExpr();
    getPrint_When_MissingSemicolon();
    getPrint_When_BadKeyword();
    getPrint_When_BadExpr();
    getPrint_When_Ok();
}

void PrintTest::getPrint_When_CurrentIsEmpty() {
    vector<Symbol*> symbols = {};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Print* print = new Print(indexer);

    print->construct();

    expect("", print->getExpression() == 0);

    delete print;
}

void PrintTest::getPrint_When_NotConstruct() {
    string expr = "x";
    Symbol* symbol = new Symbol(expr, 1, 5);
    vector<Symbol*> symbols = {symbol};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Print* print = new Print(indexer);

    expect("", print->getExpression() == 0);

    delete print;
}

void PrintTest::positionChanged_When_Construct() {
    string key = "print";
    string expr = "x";
    string semicolon = ";";
    Symbol* symbolPrint = new Symbol(key, 1, 2);
    Symbol* symbolExpr = new Symbol(expr, 1, 5);
    Symbol* symbolSemicolon = new Symbol(semicolon, 1, 8);
    vector<Symbol*> symbols = {symbolPrint, symbolExpr, symbolSemicolon};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Print* print = new Print(indexer);

    unsigned int previous = indexer->position();
    print->construct();
    unsigned int current = indexer->position();

    expect("", current == previous + 3);

    delete print;
}

void PrintTest::getPrint_When_MissingKeyword() {
    string expr = "x";
    string semicolon = ";";
    Symbol* symbolExpr = new Symbol(expr, 1, 5);
    Symbol* symbolSemicolon = new Symbol(semicolon, 1, 8);
    vector<Symbol*> symbols = {symbolExpr, symbolSemicolon};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Print* print = new Print(indexer);

    print->construct();

    expect("", print->getExpression() == 0);

    delete print;
}

void PrintTest::getPrint_When_MissingExpr() {
    string key = "print";
    string semicolon = ";";
    Symbol* symbolPrint = new Symbol(key, 1, 2);
    Symbol* symbolSemicolon = new Symbol(semicolon, 1, 8);
    vector<Symbol*> symbols = {symbolPrint, symbolSemicolon};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Print* print = new Print(indexer);

    print->construct();

    expect("", print->getExpression() == 0);

    delete print;
}

void PrintTest::getPrint_When_MissingSemicolon() {
    string key = "print";
    string expr = "x";
    Symbol* symbolPrint = new Symbol(key, 1, 2);
    Symbol* symbolExpr = new Symbol(expr, 1, 5);
    vector<Symbol*> symbols = {symbolPrint, symbolExpr};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Print* print = new Print(indexer);

    print->construct();

    expectIf("", print->getExpression() != 0, [&]() {
       Expression* expression = print->getExpression();
       expect("", expression->getString() == 0);
       expect("", expression->getBoolean() == 0);
       expect("", expression->getOperation() != 0);
    });

    delete print;
}

void PrintTest::getPrint_When_BadKeyword() {
    string key = "printf";
    string expr = "x";
    string semicolon = ";";
    Symbol* symbolPrint = new Symbol(key, 1, 2);
    Symbol* symbolExpr = new Symbol(expr, 1, 5);
    Symbol* symbolSemicolon = new Symbol(semicolon, 1, 8);
    vector<Symbol*> symbols = {symbolPrint, symbolExpr, symbolSemicolon};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Print* print = new Print(indexer);

    print->construct();

    expect("", print->getExpression() == 0);

    delete print;
}

void PrintTest::getPrint_When_BadExpr() {
    string key = "print";
    string expr = "!";
    string semicolon = ";";
    Symbol* symbolPrint = new Symbol(key, 1, 2);
    Symbol* symbolExpr = new Symbol(expr, 1, 5);
    Symbol* symbolSemicolon = new Symbol(semicolon, 1, 8);
    vector<Symbol*> symbols = {symbolPrint, symbolExpr, symbolSemicolon};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Print* print = new Print(indexer);

    print->construct();

    expect("", print->getExpression() == 0);

    delete print;
}

void PrintTest::getPrint_When_Ok() {
    string key = "print";
    string expr = "x";
    string semicolon = ";";
    Symbol* symbolPrint = new Symbol(key, 1, 2);
    Symbol* symbolExpr = new Symbol(expr, 1, 5);
    Symbol* symbolSemicolon = new Symbol(semicolon, 1, 8);
    vector<Symbol*> symbols = {symbolPrint, symbolExpr, symbolSemicolon};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Print* print = new Print(indexer);

    print->construct();

    expectIf("", print->getExpression() != 0, [&]() {
        Expression* expression = print->getExpression();
        expect("", expression->getString() == 0);
        expect("", expression->getBoolean() == 0);
        expect("", expression->getOperation() != 0);
    });

    delete print;
}
