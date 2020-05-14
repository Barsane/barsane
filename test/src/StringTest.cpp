//
// Created by souls on 14/05/2020.
//

#include "../include/StringTest.h"

void StringTest::run() {
    getValue_When_CurrentIsEmpty();
    getValue_When_NotConstruct();
    getValue_When_CurrentIs();
    getValue_When_CurrentMissingLeftQuote();
    getValue_When_CurrentMissingRightQuote();
    getValue_When_BadToken();
    positionChanged_When_Construct();
    getValue_When_SingleQuote();
}

void StringTest::getValue_When_CurrentIsEmpty() {
    vector<Symbol*> symbols = {};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    String* stringExpr = new String(indexer);

    stringExpr->construct();

    expect("", stringExpr->getValue() == 0);

    delete stringExpr;
}

void StringTest::getValue_When_NotConstruct() {
    string great = "\"Hello world\"";
    Symbol* symbol = new Symbol(great, 1, 1);
    vector<Symbol*> symbols = {symbol};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    String* stringExpr = new String(indexer);

    expect("", stringExpr->getValue() == 0);

    delete stringExpr;
}

void StringTest::getValue_When_CurrentIs() {
    string great = "\"Hello world\"";
    Symbol* symbol = new Symbol(great, 1, 1);
    vector<Symbol*> symbols = {symbol};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    String* stringExpr = new String(indexer);

    stringExpr->construct();

    expectIf("", stringExpr->getValue() != 0, [&]() {
        expect("", *stringExpr->getValue() == great);
    });

    delete stringExpr;
}

void StringTest::getValue_When_CurrentMissingLeftQuote() {
    string great = "Hello world\"";
    Symbol* symbol = new Symbol(great, 1, 1);
    vector<Symbol*> symbols = {symbol};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    String* stringExpr = new String(indexer);

    stringExpr->construct();

    expect("", stringExpr->getValue() == 0);

    delete stringExpr;
}

void StringTest::getValue_When_CurrentMissingRightQuote() {
    string great = "\"Hello world";
    Symbol* symbol = new Symbol(great, 1, 1);
    vector<Symbol*> symbols = {symbol};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    String* stringExpr = new String(indexer);

    stringExpr->construct();

    expect("", stringExpr->getValue() == 0);

    delete stringExpr;
}

void StringTest::getValue_When_BadToken() {
    string great = "Hello world";
    Symbol* symbol = new Symbol(great, 1, 1);
    vector<Symbol*> symbols = {symbol};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    String* stringExpr = new String(indexer);

    stringExpr->construct();

    expect("", stringExpr->getValue() == 0);

    delete stringExpr;
}

void StringTest::positionChanged_When_Construct() {
    string great = "\"Hello world\"";
    Symbol* symbol = new Symbol(great, 1, 1);
    vector<Symbol*> symbols = {symbol};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    String* stringExpr = new String(indexer);

    unsigned int previous = indexer->position();
    stringExpr->construct();
    unsigned int current = indexer->position();

    expect("", current == previous + 1);

    delete stringExpr;
}

void StringTest::getValue_When_SingleQuote() {
    string great = "'Hello world'";
    Symbol* symbol = new Symbol(great, 1, 1);
    vector<Symbol*> symbols = {symbol};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    String* stringExpr = new String(indexer);

    stringExpr->construct();

    expect("", stringExpr->getValue() == 0);

    delete stringExpr;
}
