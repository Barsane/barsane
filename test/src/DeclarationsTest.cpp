//
// Created by souls on 13/05/2020.
//

#include "../include/DeclarationsTest.h"

void DeclarationsTest::run() {
    getDeclarations_When_CurrentIsEmpty();
    getDeclarations_When_NotConstruct();
    positionChanged_WhenConstruct();
    getDeclarations_When_OneDeclaration();
    getDeclarations_When_MultipleDeclaration();
}

void DeclarationsTest::getDeclarations_When_CurrentIsEmpty() {
    vector<Symbol*> empty = {};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(empty);
    Declarations* declarations = new Declarations(indexer);

    declarations->construct();

    expect("", declarations->getDeclaration() != 0);
    expect("", declarations->getDeclarations() == 0);

    delete declarations;
}

void DeclarationsTest::getDeclarations_When_NotConstruct() {
    string x = "x";
    string y = "y";
    string colon = ":";
    string type = "number";
    string semicolon = ";";
    Symbol* symbolId11 = new Symbol(x, 1, 1);
    Symbol* symbolColon12 = new Symbol(colon, 1, 2);
    Symbol* symbolType13 = new Symbol(type, 1, 3);
    Symbol* symbolSemiColon14 = new Symbol(semicolon, 1, 4);
    Symbol* symbolId15 = new Symbol(y, 1, 5);
    Symbol* symbolColon16 = new Symbol(colon, 1, 6);
    Symbol* symbolType17 = new Symbol(type, 1, 7);
    Symbol* symbolSemiColon18 = new Symbol(semicolon, 1, 8);
    vector<Symbol*> symbols = {
            symbolId11, symbolColon12, symbolType13, symbolSemiColon14,
            symbolId15, symbolColon16, symbolType17, symbolSemiColon18,
    };
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Declarations* declarations = new Declarations(indexer);

    expect("", declarations->getDeclaration() == 0);
    expect("", declarations->getDeclarations() == 0);

    delete declarations;
}

void DeclarationsTest::positionChanged_WhenConstruct() {
    string x = "x";
    string y = "y";
    string colon = ":";
    string type = "number";
    string semicolon = ";";
    Symbol* symbolId11 = new Symbol(x, 1, 1);
    Symbol* symbolColon12 = new Symbol(colon, 1, 2);
    Symbol* symbolType13 = new Symbol(type, 1, 3);
    Symbol* symbolSemiColon14 = new Symbol(semicolon, 1, 4);
    Symbol* symbolId15 = new Symbol(y, 1, 5);
    Symbol* symbolColon16 = new Symbol(colon, 1, 6);
    Symbol* symbolType17 = new Symbol(type, 1, 7);
    Symbol* symbolSemiColon18 = new Symbol(semicolon, 1, 8);
    vector<Symbol*> symbols = {
            symbolId11, symbolColon12, symbolType13, symbolSemiColon14,
            symbolId15, symbolColon16, symbolType17, symbolSemiColon18,
    };
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Declarations* declarations = new Declarations(indexer);

    unsigned int previous = indexer->position();
    declarations->construct();
    unsigned int current = indexer->position();

    expect("Current index should be equal 8",
           previous + 8 == current);

    delete declarations;
}

void DeclarationsTest::getDeclarations_When_OneDeclaration() {
    string x = "x";
    string colon = ":";
    string type = "number";
    string semicolon = ";";
    Symbol* symbolId11 = new Symbol(x, 1, 1);
    Symbol* symbolColon12 = new Symbol(colon, 1, 2);
    Symbol* symbolType13 = new Symbol(type, 1, 3);
    Symbol* symbolSemiColon14 = new Symbol(semicolon, 1, 4);
    vector<Symbol*> symbols = {
            symbolId11, symbolColon12, symbolType13, symbolSemiColon14
    };
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Declarations* declarations = new Declarations(indexer);

    declarations->construct();

    expect("", declarations->getDeclaration() != 0);
    expect("", declarations->getDeclaration()->getIds() != 0);
    expect("", declarations->getDeclaration()->getType() != 0);
    expect("", declarations->getDeclarations() == 0);

    delete declarations;
}

void DeclarationsTest::getDeclarations_When_MultipleDeclaration() {
    string x = "x";
    string y = "y";
    string colon = ":";
    string type = "number";
    string semicolon = ";";
    Symbol* symbolId11 = new Symbol(x, 1, 1);
    Symbol* symbolColon12 = new Symbol(colon, 1, 2);
    Symbol* symbolType13 = new Symbol(type, 1, 3);
    Symbol* symbolSemiColon14 = new Symbol(semicolon, 1, 4);
    Symbol* symbolId15 = new Symbol(y, 1, 5);
    Symbol* symbolColon16 = new Symbol(colon, 1, 6);
    Symbol* symbolType17 = new Symbol(type, 1, 7);
    Symbol* symbolSemiColon18 = new Symbol(semicolon, 1, 8);
    vector<Symbol*> symbols = {
            symbolId11, symbolColon12, symbolType13, symbolSemiColon14,
            symbolId15, symbolColon16, symbolType17, symbolSemiColon18,
    };
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Declarations* declarations = new Declarations(indexer);

    declarations->construct();

    expect("", declarations->getDeclaration() != 0);
    expect("", declarations->getDeclaration()->getIds() != 0);
    expect("", declarations->getDeclaration()->getType() != 0);
    expect("", declarations->getDeclarations() != 0);
    expect("", declarations->getDeclarations()->getDeclaration() != 0);

    delete declarations;
}
