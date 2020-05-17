//
// Created by souls on 16/05/2020.
//

#include "../include/AffectsTest.h"

void AffectsTest::run() {
    getAffects_When_CurrentIsEmpty();
    getAffects_When_NotConstruct();
    positionChanged_When_Construct();
    getAffects_When_OneAffect();
    getAffects_When_MultipleAffects();
    getAffects_When_BadId();
}

void AffectsTest::getAffects_When_CurrentIsEmpty() {
    vector<Symbol*> symbols = {};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Affects* affects = new Affects(indexer);

    affects->construct();

    expectIf("", affects->getAffect() != 0, [&]() {
        Id* id = affects->getAffect()->getId();
        expectIf("", id != 0, [&]() {
            expect("", id->getName() == 0);
        });
        expect("", affects->getAffect()->getExpression() == 0);
    });
    expect("", affects->getAffects() == 0);

    delete affects;
}

void AffectsTest::getAffects_When_NotConstruct() {
    string id = "x";
    string equal = "=";
    string expr = "25";
    string semicolon = ";";
    Symbol* symbolId = new Symbol(id, 1, 1);
    Symbol* symbolEqual = new Symbol(equal, 1, 3);
    Symbol* symbolExpr = new Symbol(expr, 1, 5);
    Symbol* symbolSemicolon = new Symbol(semicolon, 1, 7);
    vector<Symbol*> symbols = {symbolId, symbolEqual, symbolExpr, symbolSemicolon};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Affects* affects = new Affects(indexer);


    expect("", affects->getAffect() == 0);
    expect("", affects->getAffects() == 0);

    delete affects;
}

void AffectsTest::positionChanged_When_Construct() {
    string id = "x";
    string equal = "=";
    string expr = "25";
    string semicolon = ";";
    Symbol* symbolId = new Symbol(id, 1, 1);
    Symbol* symbolEqual = new Symbol(equal, 1, 3);
    Symbol* symbolExpr = new Symbol(expr, 1, 5);
    Symbol* symbolSemicolon = new Symbol(semicolon, 1, 7);
    vector<Symbol*> symbols = {symbolId, symbolEqual, symbolExpr, symbolSemicolon};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Affects* affects = new Affects(indexer);

    unsigned int previous = indexer->position();
    affects->construct();
    unsigned int current = indexer->position();

    expect("", current == previous + 4);

    delete affects;
}

void AffectsTest::getAffects_When_OneAffect() {
    string id = "x";
    string equal = "=";
    string expr = "25";
    string semicolon = ";";
    Symbol* symbolId = new Symbol(id, 1, 1);
    Symbol* symbolEqual = new Symbol(equal, 1, 3);
    Symbol* symbolExpr = new Symbol(expr, 1, 5);
    Symbol* symbolSemicolon = new Symbol(semicolon, 1, 7);
    vector<Symbol*> symbols = {symbolId, symbolEqual, symbolExpr, symbolSemicolon};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Affects* affects = new Affects(indexer);

    affects->construct();

    expectIf("", affects->getAffect() != 0, [&]() {
        expect("", affects->getAffect()->getId() != 0);
        expect("", affects->getAffect()->getExpression() != 0);
    });
    expect("", affects->getAffects() == 0);

    delete affects;
}

void AffectsTest::getAffects_When_MultipleAffects() {
    string id = "x";
    string equal = "=";
    string expr = "25";
    string semicolon = ";";
    string var = "ok";
    string boolean = "true";
    Symbol* symbolId = new Symbol(id, 1, 1);
    Symbol* symbolEqual = new Symbol(equal, 1, 3);
    Symbol* symbolExpr = new Symbol(expr, 1, 5);
    Symbol* symbolSemicolon = new Symbol(semicolon, 1, 7);
    Symbol* symbolVar = new Symbol(var, 1, 9);
    Symbol* symbolEqual1 = new Symbol(equal, 1, 11);
    Symbol* symbolBoolean = new Symbol(boolean, 1, 13);
    Symbol* symbolSc1 = new Symbol(semicolon, 1, 15);
    vector<Symbol*> symbols = {
        symbolId, symbolEqual, symbolExpr, symbolSemicolon,
        symbolVar, symbolEqual1, symbolBoolean, symbolSc1
    };
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Affects* affects = new Affects(indexer);

    affects->construct();

    expectIf("", affects->getAffect() != 0, [&]() {
        expect("", affects->getAffect()->getId() != 0);
        expect("", affects->getAffect()->getExpression() != 0);
    });
    expectIf("", affects->getAffects() != 0, [&]() {
        Affect* affect = affects->getAffects()->getAffect();
        expect("", *affect->getId()->getName() == "ok");
        expect("", affect->getExpression()->getBoolean() != 0);
        expect("", affect->getExpression()->getString() == 0);
        expect("", affect->getExpression()->getOperation() == 0);
    });

    delete affects;
}

void AffectsTest::getAffects_When_BadId() {
    string id = "123";
    string equal = "=";
    string expr = "25";
    string semicolon = ";";
    Symbol* symbolId = new Symbol(id, 1, 1);
    Symbol* symbolEqual = new Symbol(equal, 1, 3);
    Symbol* symbolExpr = new Symbol(expr, 1, 5);
    Symbol* symbolSemicolon = new Symbol(semicolon, 1, 7);
    vector<Symbol*> symbols = {symbolId, symbolEqual, symbolExpr, symbolSemicolon};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Affects* affects = new Affects(indexer);

    affects->construct();

    expectIf("", affects->getAffect() != 0, [&]() {
        Affect* affect = affects->getAffect();
        expectIf("", affect->getId() != 0, [&]() {
            expect("", affect->getId()->getName() == 0);
            expect("", affect->getExpression() == 0);
        });
    });
    expect("", affects->getAffects() == 0);

    delete affects;
}
