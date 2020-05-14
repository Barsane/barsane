//
// Created by souls on 14/05/2020.
//

#include "../include/ExpressionTest.h"

void ExpressionTest::run() {
    getValue_When_CurrentIsEmpty();
    getValue_When_NotConstruct();
    getValue_When_CurrentIsOperation();
    getValue_When_CurrentIsBoolean();
    getValue_When_CurrentIsString();
    getValue_When_BadToken();
    positionChanged_When_Construct();
}

void ExpressionTest::getValue_When_CurrentIsEmpty() {
    vector<Symbol*> symbols = {};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Expression* expression = new Expression(indexer);

    expression->construct();

    expect("", expression->getOperation() == 0);
    expect("", expression->getStringExpr() == 0);
    expect("", expression->getBoolean() == 0);

    delete expression;
}

void ExpressionTest::getValue_When_NotConstruct() {
    string number = "1";
    Symbol* symbol = new Symbol(number, 1, 1);
    vector<Symbol*> symbols = {symbol};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Expression* expression = new Expression(indexer);

    expect("", expression->getOperation() == 0);
    expect("", expression->getStringExpr() == 0);
    expect("", expression->getBoolean() == 0);

    delete expression;
}

void ExpressionTest::getValue_When_CurrentIsOperation() {
    string number = "1";
    Symbol* symbol = new Symbol(number, 1, 1);
    vector<Symbol*> symbols = {symbol};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Expression* expression = new Expression(indexer);

    expression->construct();

    expect("", expression->getOperation() != 0);
    expect("", expression->getStringExpr() == 0);
    expect("", expression->getBoolean() == 0);

    delete expression;
}

void ExpressionTest::getValue_When_CurrentIsBoolean() {
    string ok = "true";
    Symbol* symbol = new Symbol(ok, 1, 1);
    vector<Symbol*> symbols = {symbol};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Expression* expression = new Expression(indexer);

    expression->construct();

    expect("", expression->getOperation() == 0);
    expect("", expression->getStringExpr() == 0);
    expect("", expression->getBoolean() != 0);

    delete expression;
}

void ExpressionTest::getValue_When_CurrentIsString() {
    string expr = "\"Barzane\"";
    Symbol* symbol = new Symbol(expr, 1, 1);
    vector<Symbol*> symbols = {symbol};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Expression* expression = new Expression(indexer);

    expression->construct();

    expect("", expression->getOperation() == 0);
    expect("", expression->getStringExpr() != 0);
    expect("", expression->getBoolean() == 0);

    delete expression;
}

void ExpressionTest::getValue_When_BadToken() {
    string number = "++";
    Symbol* symbol = new Symbol(number, 1, 1);
    vector<Symbol*> symbols = {symbol};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Expression* expression = new Expression(indexer);

    expression->construct();

    expect("", expression->getOperation() == 0);
    expect("", expression->getStringExpr() == 0);
    expect("", expression->getBoolean() == 0);

    delete expression;
}

void ExpressionTest::positionChanged_When_Construct() {
    string number = "1";
    Symbol* symbol = new Symbol(number, 1, 1);
    vector<Symbol*> symbols = {symbol};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Expression* expression = new Expression(indexer);

    unsigned int previous = indexer->position();
    expression->construct();
    unsigned int current = indexer->position();

    expect("", current = previous + 1);

    delete expression;
}
