//
// Created by souls on 09/05/2020.
//

#include "../include/IdTest.h"

void IdTest::run() {
    getId_When_CurrentIsEmpty();
    getId_When_NotConstruct();
    getId_When_BadToken();
    positionChanged_WhenConstruct();
    getName_When_CurrentIs();
}

void IdTest::getName_When_CurrentIs() {
    string text = "x";
    Symbol* symbol = new Symbol(text, 1, 1);
    vector<Symbol*> symbols = {symbol};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Id* id = new Id(indexer);
    id->construct();

    expect("Name should be x", *id->getName() == "x");

    delete id;
}

void IdTest::getId_When_CurrentIsEmpty() {
    vector<Symbol*> empty = {};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(empty);
    Id* id = new Id(indexer);
    id->construct();

    expect("Pointer of name should be 0", id->getName() == 0);

    delete id;
}

void IdTest::getId_When_NotConstruct() {
    vector<Symbol*> empty = {};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(empty);
    Id* id = new Id(indexer);

    expect("Pointer of name should be 0", id->getName() == 0);

    delete id;
}

void IdTest::getId_When_BadToken() {
    string text = "1x";
    Symbol* symbol = new Symbol(text, 1, 1);
    vector<Symbol*> symbols = {symbol};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Id* id = new Id(indexer);
    id->construct();

    expect("Pointer of name should be 0", id->getName() == 0);

    delete id;
}

void IdTest::positionChanged_WhenConstruct() {
    string text = "1x";
    string name = "myId";
    Symbol* bad = new Symbol(text, 1, 1);
    Symbol* good = new Symbol(name, 164, 125);
    vector<Symbol*> badBuf = {bad};
    vector<Symbol*> symbols = {bad, good};
    Indexer<Symbol>* ind = new Indexer<Symbol>(badBuf);
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);

    Id* id = new Id(ind);

    unsigned int previous = ind->position();
    id->construct();
    unsigned int current = ind->position();

    expect("Current index should be equal the previous because it is the last",
            previous + 1 == current);

    previous = indexer->position();
    Id* newId = new Id(indexer);
    newId->construct();
    current = indexer->position();

    expect("Current index should be the previous added 2",
           current == previous + 2);

    delete id;
    delete newId;
}
