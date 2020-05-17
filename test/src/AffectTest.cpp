//
// Created by souls on 15/05/2020.
//

#include "../include/AffectTest.h"

void AffectTest::run() {
    getAffect_When_CurrentIsEmpty();
    getAffect_When_NotConstruct();
    positionChanged_When_Construct();
    getAffect_When_MissingId();
    getAffect_When_MissingEqual();
    getAffect_When_MissingExpression();
    getAffect_When_MissingSemicolon();
    getAffect_When_BadId();
    getAffect_When_BadAfterId();
    getAffect_When_BadExpression();
}

void AffectTest::getAffect_When_CurrentIsEmpty() {
    vector<Symbol*> symbols = {};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Affect* affect = new Affect(indexer);

    affect->construct();

    expectIf("", affect->getId() != 0, [&]() {
        expect("", affect->getId()->getName() == 0);
    });
    expect("", affect->getExpression() == 0);

    delete affect;
}

void AffectTest::getAffect_When_NotConstruct() {
    string id = "x";
    string equal = "=";
    string expr = "1";
    string semicolon = ";";
    Symbol* symbolId = new Symbol(id, 1, 1);
    Symbol* symbolEqual = new Symbol(equal, 1, 2);
    Symbol* symbolExpr = new Symbol(expr, 1, 3);
    Symbol* symbolSemicolon = new Symbol(semicolon, 1, 4);
    vector<Symbol*> symbols = {symbolId, symbolEqual, symbolExpr, symbolEqual, symbolSemicolon};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Affect* affect = new Affect(indexer);

    expect("", affect->getId() == 0);
    expect("", affect->getExpression() == 0);

    delete affect;
}

void AffectTest::positionChanged_When_Construct() {
    string id = "x";
    string equal = "=";
    string expr = "1";
    string semicolon = ";";
    Symbol* symbolId = new Symbol(id, 1, 1);
    Symbol* symbolEqual = new Symbol(equal, 1, 2);
    Symbol* symbolExpr = new Symbol(expr, 1, 3);
    Symbol* symbolSemicolon = new Symbol(semicolon, 1, 4);
    vector<Symbol*> symbols = {symbolId, symbolEqual, symbolExpr, symbolSemicolon};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Affect* affect = new Affect(indexer);

    unsigned int previous = indexer->position();
    affect->construct();
    unsigned int current = indexer->position();

    expect("", current == previous + 4);

    delete affect;
}

void AffectTest::getAffect_When_MissingId() {
    string equal = "=";
    string expr = "1";
    string semicolon = ";";
    Symbol* symbolEqual = new Symbol(equal, 1, 2);
    Symbol* symbolExpr = new Symbol(expr, 1, 3);
    Symbol* symbolSemicolon = new Symbol(semicolon, 1, 4);
    vector<Symbol*> symbols = {symbolEqual, symbolExpr, symbolSemicolon};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Affect* affect = new Affect(indexer);

    affect->construct();

    expectIf("", affect->getId() != 0, [&]() {
        expect("", affect->getId()->getName() == 0);
    });
    expect("", affect->getExpression() == 0);

    delete affect;
}

void AffectTest::getAffect_When_MissingEqual() {
    string id = "x";
    string expr = "1";
    string semicolon = ";";
    Symbol* symbolId = new Symbol(id, 1, 2);
    Symbol* symbolExpr = new Symbol(expr, 1, 3);
    Symbol* symbolSemicolon = new Symbol(semicolon, 1, 4);
    vector<Symbol*> symbols = {symbolId, symbolExpr, symbolSemicolon};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Affect* affect = new Affect(indexer);

    affect->construct();

    expectIf("", affect->getId() != 0, [&]() {
        expect("", *affect->getId()->getName() == "x");
    });
    expect("", affect->getExpression() == 0);

    delete affect;
}

void AffectTest::getAffect_When_MissingExpression() {
    string id = "x";
    string equal = "=";
    string semicolon = ";";
    Symbol* symbolId = new Symbol(id, 1, 2);
    Symbol* symbolEqual = new Symbol(equal, 1, 2);
    Symbol* symbolSemicolon = new Symbol(semicolon, 1, 4);
    vector<Symbol*> symbols = {symbolId, symbolEqual, symbolSemicolon};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Affect* affect = new Affect(indexer);

    affect->construct();

    expectIf("", affect->getId() != 0, [&]() {
        expect("", *affect->getId()->getName() == "x");
    });
    expectIf("", affect->getExpression() != 0, [&]() {
        Expression* expression = affect->getExpression();
        expect("", expression->getString() == 0);
        expect("", expression->getBoolean() == 0);
        expect("", expression->getOperation() == 0);
    });

    delete affect;
}

void AffectTest::getAffect_When_MissingSemicolon() {
    string id = "x";
    string equal = "=";
    string expr = "1";
    Symbol* symbolId = new Symbol(id, 1, 1);
    Symbol* symbolEqual = new Symbol(equal, 1, 2);
    Symbol* symbolExpr = new Symbol(expr, 1, 3);
    vector<Symbol*> symbols = {symbolId, symbolEqual, symbolExpr};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Affect* affect = new Affect(indexer);

    affect->construct();

    expectIf("", affect->getId() != 0, [&]() {
        expect("", *affect->getId()->getName() == "x");
    });
    expectIf("", affect->getExpression() != 0, [&]() {
        Expression* expression = affect->getExpression();
        expect("", expression->getString() == 0);
        expect("", expression->getBoolean() == 0);
        expect("", expression->getOperation() != 0);
    });

    delete affect;
}

void AffectTest::getAffect_When_BadId() {
    string id = "1";
    string equal = "=";
    string expr = "1";
    string semicolon = ";";
    Symbol* symbolId = new Symbol(id, 1, 1);
    Symbol* symbolEqual = new Symbol(equal, 1, 2);
    Symbol* symbolExpr = new Symbol(expr, 1, 3);
    Symbol* symbolSemicolon = new Symbol(semicolon, 1, 4);
    vector<Symbol*> symbols = {symbolId, symbolEqual, symbolExpr, symbolSemicolon};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Affect* affect = new Affect(indexer);

    affect->construct();

    expectIf("", affect->getId() != 0, [&]() {
        expect("", affect->getId()->getName() == 0);
    });
    expect("", affect->getExpression() == 0);

    delete affect;
}

void AffectTest::getAffect_When_BadAfterId() {
    string id = "x";
    string equal = "p";
    string expr = "1";
    string semicolon = ";";
    Symbol* symbolId = new Symbol(id, 1, 1);
    Symbol* symbolEqual = new Symbol(equal, 1, 2);
    Symbol* symbolExpr = new Symbol(expr, 1, 3);
    Symbol* symbolSemicolon = new Symbol(semicolon, 1, 4);
    vector<Symbol*> symbols = {symbolId, symbolEqual, symbolExpr, symbolSemicolon};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Affect* affect = new Affect(indexer);

    affect->construct();

    expectIf("", affect->getId() != 0, [&]() {
        expect("",*affect->getId()->getName() == "x");
    });
    expect("", affect->getExpression() == 0);

    delete affect;
}

void AffectTest::getAffect_When_BadExpression() {
    string id = "x";
    string equal = "=";
    string expr = "print";
    string semicolon = ";";
    Symbol* symbolId = new Symbol(id, 1, 1);
    Symbol* symbolEqual = new Symbol(equal, 1, 2);
    Symbol* symbolExpr = new Symbol(expr, 1, 3);
    Symbol* symbolSemicolon = new Symbol(semicolon, 1, 4);
    vector<Symbol*> symbols = {symbolId, symbolEqual, symbolExpr, symbolSemicolon};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Affect* affect = new Affect(indexer);

    affect->construct();

    expectIf("", affect->getId() != 0, [&]() {
        expect("", *affect->getId()->getName() == "x");
    });
    expectIf("", affect->getExpression() != 0, [&]() {
        Expression* expression = affect->getExpression();
        expect("", expression->getString() == 0);
        expect("", expression->getBoolean() == 0);
        expect("", expression->getOperation() == 0);
    });

    delete affect;
}
