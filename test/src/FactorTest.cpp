//
// Created by souls on 13/05/2020.
//

#include "../include/FactorTest.h"

using namespace std;

void FactorTest::run() {
    getFactor_When_CurrentIsEmpty();
    getFactor_When_NotConstruct();
    getFactor_When_BadToken();
    positionChanged_WhenConstruct();
    getFactor_When_CurrentIsMinus();
    getFactor_When_CurrentIsLeftBracket();
    getFactor_When_CurrentIsId();
    getFactor_When_CurrentIsNumber();
    getFactor_When_NestedDeep();
}

void FactorTest::getFactor_When_CurrentIsEmpty() {
    vector<Symbol*> symbols = {};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Factor* factor = new Factor(indexer);

    factor->construct();

    expect("", factor->getMinus() == 0);
    expect("", factor->getId() == 0);
    expect("", factor->getNumber() == 0);
    expect("", factor->getLeftBracket() == 0);
    expect("", factor->getRightBracket() == 0);
    expect("", factor->getOperation() == 0);

    delete factor;
}

void FactorTest::getFactor_When_NotConstruct() {
    string minus = "-";
    string x = "x";
    Symbol* symbolMinus = new Symbol(minus, 1, 1);
    Symbol* symbolId = new Symbol(x, 1, 2);
    vector<Symbol*> symbols = {symbolMinus, symbolId};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Factor* factor = new Factor(indexer);

    expect("", factor->getMinus() == 0);
    expect("", factor->getId() == 0);
    expect("", factor->getNumber() == 0);
    expect("", factor->getLeftBracket() == 0);
    expect("", factor->getRightBracket() == 0);
    expect("", factor->getOperation() == 0);

    delete factor;
}

void FactorTest::getFactor_When_BadToken() {
    string bad = "true";
    string x = "x";
    Symbol* symbolBad = new Symbol(bad, 1, 1);
    Symbol* symbolId = new Symbol(x, 1, 2);
    vector<Symbol*> symbols = {symbolBad, symbolId};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Factor* factor = new Factor(indexer);

    factor->construct();

    expect("", factor->getMinus() == 0);
    expect("", factor->getId() == 0);
    expect("", factor->getNumber() == 0);
    expect("", factor->getLeftBracket() == 0);
    expect("", factor->getRightBracket() == 0);
    expect("", factor->getOperation() == 0);

    delete factor;
}

void FactorTest::positionChanged_WhenConstruct() {
    string minus = "-";
    string x = "x";
    Symbol* symbolMinus = new Symbol(minus, 1, 1);
    Symbol* symbolId = new Symbol(x, 1, 2);
    vector<Symbol*> symbols = {symbolMinus, symbolId};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Factor* factor = new Factor(indexer);

    unsigned int previous = indexer->position();
    factor->construct();
    unsigned int current = indexer->position();

    expect("Current index should be equal the previous because it is the last",
           previous + 2 == current);

    delete factor;
}

void FactorTest::getFactor_When_CurrentIsMinus() {
    string minus = "-";
    string x = "x";
    Symbol* symbolMinus = new Symbol(minus, 1, 1);
    Symbol* symbolId = new Symbol(x, 1, 2);
    vector<Symbol*> symbols = {symbolMinus, symbolId};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Factor* factor = new Factor(indexer);

    factor->construct();

    expect("", factor->getMinus() != 0);
    expect("", factor->getMinus()->getToken() == minus);
    expect("", factor->getId() != 0);
    expect("", factor->getNumber() == 0);
    expect("", factor->getLeftBracket() == 0);
    expect("", factor->getRightBracket() == 0);
    expect("", factor->getOperation() == 0);

    delete factor;
}

void FactorTest::getFactor_When_CurrentIsLeftBracket() {
    // ["-"] {id} | ["-"] {number} | "(" {operation} ")
    string left = "(";
    string x = "x";
    string number = "1";
    string plus = "+";
    string right = ")";
    Symbol* symbolLeft = new Symbol(left, 1, 1);
    Symbol* symbolId = new Symbol(x, 1, 2);
    Symbol* symbolPlus = new Symbol(plus, 1, 3);
    Symbol* symbolNum = new Symbol(number, 1, 4);
    Symbol* symbolRight = new Symbol(right, 1, 5);
    vector<Symbol*> symbols = {symbolLeft, symbolId, symbolPlus, symbolNum, symbolRight};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Factor* factor = new Factor(indexer);

    factor->construct();

    expect("", factor->getLeftBracket() != 0);
    expect("", factor->getLeftBracket()->getToken() == left);
    expect("", factor->getOperation() != 0);
    expect("", factor->getRightBracket() != 0);
    // expect("", factor->getRightBracket()->getToken() == right);
    expect("", factor->getId() == 0);
    expect("", factor->getNumber() == 0);
    expect("", factor->getMinus() == 0);

    delete factor;
}

void FactorTest::getFactor_When_CurrentIsId() {
    string x = "x";
    string any = "any";
    Symbol* symbolId = new Symbol(x, 1, 2);
    Symbol* symbolAny = new Symbol(any, 1, 3);
    vector<Symbol*> symbols = {symbolId, symbolAny};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Factor* factor = new Factor(indexer);

    factor->construct();

    expect("", factor->getMinus() == 0);
    expect("", factor->getId() != 0);
    expect("", *factor->getId()->getName() == x);
    expect("", factor->getNumber() == 0);
    expect("", factor->getLeftBracket() == 0);
    expect("", factor->getRightBracket() == 0);
    expect("", factor->getOperation() == 0);

    delete factor;
}

void FactorTest::getFactor_When_CurrentIsNumber() {
    string number = "1000.53";
    string any = "any";
    Symbol* symbolNum = new Symbol(number, 1, 2);
    Symbol* symbolAny = new Symbol(any, 1, 3);
    vector<Symbol*> symbols = {symbolNum, symbolAny};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Factor* factor = new Factor(indexer);

    factor->construct();

    expect("", factor->getMinus() == 0);
    expect("", factor->getId() == 0);
    expect("", factor->getNumber() != 0);
    expect("", factor->getNumber()->getType() != NumberType::UNDEFINED);
    expect("", factor->getLeftBracket() == 0);
    expect("", factor->getRightBracket() == 0);
    expect("", factor->getOperation() == 0);

    delete factor;
}
