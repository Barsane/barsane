//
// Created by souls on 14/05/2020.
//

#include "../include/BooleanTest.h"

void BooleanTest::run() {
    getValue_When_CurrentIsEmpty();
    getValue_When_NotConstruct();
    getValue_When_CurrentIsTrue();
    getValue_When_CurrentIsFalse();
    getValue_When_BadToken();
    positionChanged_When_Construct();
}

void BooleanTest::getValue_When_CurrentIsEmpty() {
    vector<Symbol*> symbols = {};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Boolean* boolean = new Boolean(indexer);

    boolean->construct();

    expect("", boolean->getValue() == BooleanType::UNDEFINED);

    // delete boolean;
}

void BooleanTest::getValue_When_NotConstruct() {
    string ok = "true";
    Symbol* symbolOk = new Symbol(ok, 1, 2);
    vector<Symbol*> symbols = {symbolOk};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Boolean* boolean = new Boolean(indexer);

    expect("", boolean->getValue() == BooleanType::UNDEFINED);

    delete boolean;
}

void BooleanTest::getValue_When_CurrentIsTrue() {
    string ok = "true";
    Symbol* symbolOk = new Symbol(ok, 1, 2);
    vector<Symbol*> symbols = {symbolOk};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Boolean* boolean = new Boolean(indexer);

    boolean->construct();

    expect("", boolean->getValue() == BooleanType::TRUE);

    delete boolean;
}

void BooleanTest::getValue_When_CurrentIsFalse() {
    string ko = "false";
    Symbol* symbolKo = new Symbol(ko, 1, 2);
    vector<Symbol*> symbols = {symbolKo};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Boolean* boolean = new Boolean(indexer);

    boolean->construct();

    expect("", boolean->getValue() == BooleanType::FALSE);

    delete boolean;
}

void BooleanTest::getValue_When_BadToken() {
    string bad = "bad";
    Symbol* symbolBad = new Symbol(bad, 1, 2);
    vector<Symbol*> symbols = {symbolBad};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Boolean* boolean = new Boolean(indexer);

    boolean->construct();

    expect("", boolean->getValue() == BooleanType::UNDEFINED);

    delete boolean;
}

void BooleanTest::positionChanged_When_Construct() {
    string bad = "bad";
    Symbol* symbolBad = new Symbol(bad, 1, 2);
    vector<Symbol*> symbols = {symbolBad};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Boolean* boolean = new Boolean(indexer);

    unsigned int previous = indexer->position();
    boolean->construct();
    unsigned int current = indexer->position();

    expect("", current == previous + 1);

    delete boolean;
}
