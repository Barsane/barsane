//
// Created by souls on 09/05/2020.
//

#include "../include/NumberTest.h"

void NumberTest::getNumber_When_IndexerIsEmpty() {
    vector<Symbol*> empty = {};
    Indexer<Symbol> indexer = Indexer<Symbol>(empty);
    Number number = Number(indexer);
    number.construct();

    expect("Pointer of integer should be 0", number.getInteger() == 0);
    expect("Pointer of real should be 0", number.getReal() == 0);
    expect("Type number is undefined", number.getType() == NumberType::UNDEFINED);
}

void NumberTest::getNumber_When_CurrentIsNotCatchable() {
    string x = "10x";
    Symbol* id = new Symbol(x, 1, 1);
    vector<Symbol*> empty = {id};
    Indexer<Symbol> indexer = Indexer<Symbol>(empty);
    Number number = Number(indexer);
    number.construct();

    expect("Pointer of integer should be 0", number.getInteger() == 0);
    expect("Pointer of real should be 0", number.getReal() == 0);
    expect("Type number is undefined", number.getType() == NumberType::UNDEFINED);
}

void NumberTest::getNumber_When_CurrentIsDigit() {
    string integer = "1000";
    Symbol* value = new Symbol(integer, 1, 1);
    vector<Symbol*> buf = {value};
    Indexer<Symbol> indexer = Indexer<Symbol>(buf);
    Number number = Number(indexer);
    number.construct();

    expect("The value should be 1000", *number.getInteger() == 1000);
    expect("Pointer of real should be 0", number.getReal() == 0);
    expect("Type number is INTEGER", number.getType() == NumberType::INTEGER);
}

void NumberTest::getNumber_When_CurrentIsReal() {
    string real = "1000.12";
    Symbol* value = new Symbol(real, 1, 1);
    vector<Symbol*> buf = {value};
    Indexer<Symbol> indexer = Indexer<Symbol>(buf);
    Number number = Number(indexer);
    number.construct();

    expect("Pointer of integer should be 0", number.getInteger() == 0);
    expect("The value should be 1000.12", *number.getReal() == 1000.12f);
    expect("Type number is REAL", number.getType() == NumberType::REAL);
}

void NumberTest::getNumber_When_NotConstruct() {
    string value = "152";
    Symbol *any = new Symbol(value, 1, 15);
    vector<Symbol*> symbols = {any};
    Indexer<Symbol> indexer = Indexer<Symbol>(symbols);
    Number number = Number(indexer);

    expect("Pointer of integer should be 0", number.getInteger() == 0);
    expect("Pointer of real should be 0", number.getReal() == 0);
    expect("Type number is undefined", number.getType() == NumberType::UNDEFINED);
}

void NumberTest::getNumber_When_BadReal() {
    string left = ".1256";
    string right = "1256.";
    Symbol* leftSymbol = new Symbol(left, 1, 15);
    Symbol* rightSymbol = new Symbol(right, 1568, 157);
    vector<Symbol*> symbols = {leftSymbol, rightSymbol};
    Indexer<Symbol> indexer = Indexer<Symbol>(symbols);
    Number number = Number(indexer);

    number.construct();
    expect("Pointer of integer should be 0", number.getInteger() == 0);
    expect("Pointer of real should be 0", number.getReal() == 0);
    expect("Type number is undefined", number.getType() == NumberType::UNDEFINED);

    number.construct();
    expect("Pointer of integer should be 0", number.getInteger() == 0);
    expect("Pointer of real should be 0", number.getReal() == 0);
    expect("Type number is undefined", number.getType() == NumberType::UNDEFINED);
}

void NumberTest::positionChanged_WhenConstruct() {
    string value = "\"152\"";
    Symbol *any = new Symbol(value, 1, 15);
    vector<Symbol*> symbols = {any};
    Indexer<Symbol> indexer = Indexer<Symbol>(symbols);
    Number number = Number(indexer);
    unsigned int previous = indexer.position();

    number.construct();

    unsigned int current = indexer.position();

    expect("Current index should be equal the previous added 1", previous == current - 1);
}

void NumberTest::run() {
    getNumber_When_IndexerIsEmpty();
    getNumber_When_CurrentIsNotCatchable();
    getNumber_When_CurrentIsDigit();
    getNumber_When_CurrentIsReal();
    getNumber_When_NotConstruct();
    getNumber_When_BadReal();
    positionChanged_WhenConstruct();
}