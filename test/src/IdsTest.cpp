//
// Created by souls on 10/05/2020.
//

#include "../include/IdsTest.h"

void IdsTest::run() {
    getIds_When_CurrentIsEmpty();
    getIds_When_NotConstruct();
    getIds_When_MissingComa();
    positionChanged_WhenConstruct();
    getIds_When_OneId();
    getIds_When_MultipleId();
}

void IdsTest::getIds_When_CurrentIsEmpty() {
    vector<Symbol*> empty = {};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(empty);
    Ids* ids = new Ids(indexer);

    ids->construct();

    expect("Pointer of id should be 0", ids->getId() == 0);
    expect("Pointer of ids should be 0", ids->getIds() == 0);

    delete ids;
}

void IdsTest::getIds_When_NotConstruct() {
    string x = "x";
    string y = "y";
    Symbol* symbolX = new Symbol(x, 1, 1);
    Symbol* symbolY = new Symbol(y, 2, 3);
    vector<Symbol*> symbols = {symbolX, symbolY};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Ids* ids = new Ids(indexer);

    expect("Pointer of id should be 0", ids->getId() == 0);
    expect("Pointer of ids should be 0", ids->getIds() == 0);

    delete ids;
}

void IdsTest::getIds_When_MissingComa() {
    string x = "x";
    string y = "y";
    Symbol* symbolX = new Symbol(x, 1, 1);
    Symbol* symbolY = new Symbol(y, 2, 3);
    vector<Symbol*> symbols = {symbolX, symbolY};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Ids ids = Ids(indexer);
    ids.construct();

    expect("Pointer of id should not be 0", ids.getId() != 0);
    expect("The Pointer of id value should not be empty",
            !ids.getId()->getName()->empty());
    expect("Pointer of ids should be 0", ids.getIds() == 0);
}

void IdsTest::positionChanged_WhenConstruct() {
    string text = "1x";
    string coma = ",";
    string name = "myId";
    Symbol* bad = new Symbol(text, 1, 1);
    Symbol* symbolComa = new Symbol(coma, 30, 31);
    Symbol* good = new Symbol(name, 164, 125);
    vector<Symbol*> badBuf = {bad};
    vector<Symbol*> symbols = {bad, symbolComa, good};
    Indexer<Symbol>* ind = new Indexer<Symbol>(badBuf);
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);

    Ids* ids = new Ids(ind);

    unsigned int previous = ind->position();
    ids->construct();
    unsigned int current = ind->position();

    const unsigned int prev = indexer->position();
    Ids* newIds = new Ids(indexer);
    newIds->construct();
    const unsigned int curr = indexer->position();

    expect("Current index should be equal the previous because it is the last",
           previous + 1 == current);
    expect("Current index should be equal the previous added 3",
           prev + 3 == curr);

    delete ids;
    delete newIds;
}

void IdsTest::getIds_When_OneId() {
    string var = "var";
    Symbol* symbolVar = new Symbol(var, 1, 2);
    vector<Symbol*> buffer = {symbolVar};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(buffer);
    Ids* ids = new Ids(indexer);
    ids->construct();

    expect("Pointer of id should not be equal 0", ids->getId() != 0);
    expect("Pointer of ids should be equal 0", ids->getIds() == 0);

    delete ids;
}

void IdsTest::getIds_When_MultipleId() {
    string var = "var";
    string coma = ",";
    string y = "y";
    string otherComa = ",";
    string z = "z";
    Symbol* symbolVar = new Symbol(var, 1, 2);
    Symbol* symbolComa = new Symbol(coma, 30, 31);
    Symbol* symbolY = new Symbol(y, 164, 125);
    Symbol* symbolOtherComa = new Symbol(otherComa, 1, 1);
    Symbol* symbolZ = new Symbol(z, 164, 125);
    vector<Symbol*> buffer = {symbolVar, symbolComa, symbolY, symbolOtherComa, symbolZ};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(buffer);
    Ids* ids = new Ids(indexer);
    ids->construct();

    expect("Pointer of id should not be equal 0", ids->getId() != 0);
    expect("Pointer of ids should not be equal 0", ids->getIds() != 0);
    expect("Recursion pointer of id should not be equal 0", ids->getIds()->getId() != 0);

    delete ids;
}
