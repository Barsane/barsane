//
// Created by souls on 09/05/2020.
//

#include "../include/TypeTest.h"

void TypeTest::run() {
    getType_When_CurrentIsEmpty();
    getType_When_NotConstruct();
    positionChanged_WhenConstruct();
    getType_When_CurrentIsNumber();
    getType_When_CurrentIsBoolean();
    getType_When_CurrentIsString();
    getType_When_BadToken();
}

void TypeTest::getType_When_CurrentIsEmpty() {
    vector<Symbol*> empty = {};
    Indexer<Symbol> indexer = Indexer<Symbol>(empty);
    Type type = Type(indexer);
    type.construct();

    expect("Pointer of type should be 0", type.getType() == NodeType::UNDEFINED);
}

void TypeTest::getType_When_NotConstruct() {
    vector<Symbol*> empty = {};
    Indexer<Symbol> indexer = Indexer<Symbol>(empty);
    Type type = Type(indexer);

    expect("Pointer of type should be 0", type.getType() == NodeType::UNDEFINED);
}

void TypeTest::positionChanged_WhenConstruct() {
    string number = "number";
    string bad = "bool";
    Symbol* symbolNum = new Symbol(number, 1, 1);
    Symbol* symbolBad = new Symbol(bad, 164, 125);
    vector<Symbol*> small = {symbolNum};
    vector<Symbol*> medium = {symbolBad, symbolNum};
    Indexer<Symbol>* ind = new Indexer<Symbol>(small);
    Indexer<Symbol>* indexer = new Indexer<Symbol>(medium);
    Type type = Type(*ind);

    unsigned int previous = ind->position();
    type.construct();
    unsigned int current = ind->position();

    expect("Current index should be equal the previous because it is the last",
            previous + 1 == current);

    previous = indexer->position();
    Type newType = Type(*indexer);
    newType.construct();
    current = indexer->position();

    expect("Current index should be the previous added 2",
           current == previous + 2);

}

void TypeTest::getType_When_CurrentIsNumber() {
    string text = "number";
    Symbol* symbol = new Symbol(text, 1, 1);
    vector<Symbol*> symbols = {symbol};
    Indexer<Symbol> indexer = Indexer<Symbol>(symbols);
    Type type = Type(indexer);
    type.construct();

    expect("Type should be number", type.getType() == NodeType::NUMBER);
}

void TypeTest::getType_When_CurrentIsBoolean() {
    string text = "boolean";
    Symbol* symbol = new Symbol(text, 1, 1);
    vector<Symbol*> symbols = {symbol};
    Indexer<Symbol> indexer = Indexer<Symbol>(symbols);
    Type type = Type(indexer);
    type.construct();

    expect("Type should be boolean", type.getType() == NodeType::BOOLEAN);
}

void TypeTest::getType_When_CurrentIsString() {
    string text = "string";
    Symbol* symbol = new Symbol(text, 1, 1);
    vector<Symbol*> symbols = {symbol};
    Indexer<Symbol> indexer = Indexer<Symbol>(symbols);
    Type type = Type(indexer);
    type.construct();

    expect("Type should be string", type.getType() == NodeType::STRING);
}

void TypeTest::getType_When_BadToken() {
    string text = "integer";
    Symbol* symbol = new Symbol(text, 1, 1);
    vector<Symbol*> symbols = {symbol};
    Indexer<Symbol> indexer = Indexer<Symbol>(symbols);
    Type type = Type(indexer);
    type.construct();

    expect("Type should be Undefined", type.getType() == NodeType::UNDEFINED);
}
