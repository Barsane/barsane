//
// Created by souls on 12/05/2020.
//

#include "../include/DeclarationTest.h"

void DeclarationTest::run() {
    getDeclaration_When_CurrentIsEmpty();
    getDeclaration_When_NotConstruct();
    getDeclaration_When_MissingColon();
    getDeclaration_When_MissingSemiColon();
    getDeclaration_When_MissingType();
    getDeclaration_When_BadId();
    positionChanged_WhenConstruct();
    getDeclaration_When_OneId();
    getDeclaration_When_MultipleId();
}

void DeclarationTest::getDeclaration_When_CurrentIsEmpty() {
    vector<Symbol*> empty = {};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(empty);
    Declaration* declaration = new Declaration(indexer);

    declaration->construct();

    expect("Pointer of declaration ids should be 0", declaration->getIds() != 0);
    expect("Id of pointer of declaration id", declaration->getIds()->getId() == 0);
    expect("Ids of pointer of declaration id", declaration->getIds()->getIds() == 0);
    expect("Pointer of declaration type", declaration->getType() == 0);

    delete declaration;
}

void DeclarationTest::getDeclaration_When_NotConstruct() {
    string x = "x";
    string colon = ":";
    string type = "number";
    string semicolon = ";";
    Symbol* symbolId = new Symbol(x, 1, 1);
    Symbol* symbolColon = new Symbol(colon, 1, 2);
    Symbol* symbolType = new Symbol(type, 1, 3);
    Symbol* symbolSemiColon = new Symbol(semicolon, 1, 4);
    vector<Symbol*> symbols = {symbolId, symbolColon, symbolType, symbolSemiColon};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Declaration* declaration = new Declaration(indexer);

    expect("Pointer of declaration ids should be 0", declaration->getIds() == 0);
    expect("Pointer of declaration type", declaration->getType() == 0);

    delete declaration;
}

void DeclarationTest::getDeclaration_When_MissingColon() {
    string x = "x";
    string type = "number";
    string semicolon = ";";
    Symbol* symbolId = new Symbol(x, 1, 1);
    Symbol* symbolType = new Symbol(type, 1, 3);
    Symbol* symbolSemiColon = new Symbol(semicolon, 1, 4);
    vector<Symbol*> symbols = {symbolId, symbolType, symbolSemiColon};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Declaration* declaration = new Declaration(indexer);

    declaration->construct();

    expect("Pointer of declaration ids should not be 0", declaration->getIds() != 0);
    expect("Pointer of declaration type should be 0", declaration->getType() == 0);

    delete declaration;
}

void DeclarationTest::getDeclaration_When_MissingSemiColon() {
    string x = "x";
    string colon = ":";
    string type = "number";
    Symbol* symbolId = new Symbol(x, 1, 1);
    Symbol* symbolColon = new Symbol(colon, 1, 2);
    Symbol* symbolType = new Symbol(type, 1, 3);
    vector<Symbol*> symbols = {symbolId, symbolColon, symbolType};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Declaration* declaration = new Declaration(indexer);

    declaration->construct();

    expect("", declaration->getIds() != 0);
    expect("", declaration->getType() != 0);

    delete declaration;
}

void DeclarationTest::getDeclaration_When_MissingType() {
    string x = "x";
    string colon = ":";
    string semicolon = ";";
    Symbol* symbolId = new Symbol(x, 1, 1);
    Symbol* symbolColon = new Symbol(colon, 1, 2);
    Symbol* symbolSemiColon = new Symbol(semicolon, 1, 4);
    vector<Symbol*> symbols = {symbolId, symbolColon, symbolSemiColon};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Declaration* declaration = new Declaration(indexer);

    declaration->construct();

    expect("", declaration->getIds() != 0);
    expect("", declaration->getType() != 0);
    expect("", declaration->getType()->getType() == NodeType::UNDEFINED);

    delete declaration;
}

void DeclarationTest::getDeclaration_When_BadId() {
    string x = "1x";
    string colon = ":";
    string type = "number";
    string semicolon = ";";
    Symbol* badId = new Symbol(x, 1, 1);
    Symbol* symbolColon = new Symbol(colon, 1, 2);
    Symbol* symbolType = new Symbol(type, 1, 3);
    Symbol* symbolSemiColon = new Symbol(semicolon, 1, 4);
    vector<Symbol*> symbols = {badId, symbolColon, symbolType, symbolSemiColon};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Declaration* declaration = new Declaration(indexer);

    declaration->construct();

    expect("", declaration->getIds() != 0);
    expect("", declaration->getIds()->getId() == 0);
    expect("", declaration->getType() != 0);
    expect("", declaration->getType()->getType() != NodeType::UNDEFINED);

    delete declaration;
}

void DeclarationTest::positionChanged_WhenConstruct() {
    string x = "x";
    string colon = ":";
    string type = "number";
    string semicolon = ";";
    Symbol* id = new Symbol(x, 1, 1);
    Symbol* symbolColon = new Symbol(colon, 1, 2);
    Symbol* symbolType = new Symbol(type, 1, 3);
    Symbol* symbolSemiColon = new Symbol(semicolon, 1, 4);
    vector<Symbol*> symbols = {id, symbolColon, symbolType, symbolSemiColon};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Declaration* declaration = new Declaration(indexer);
    unsigned int previous = indexer->position();

    declaration->construct();
    unsigned int current = indexer->position();

    expect("Current index should be equal 4",
           previous + 4 == current);

    delete declaration;
}

void DeclarationTest::getDeclaration_When_OneId() {
    string x = "x";
    string colon = ":";
    string type = "number";
    string semicolon = ";";
    Symbol* id = new Symbol(x, 1, 1);
    Symbol* symbolColon = new Symbol(colon, 1, 2);
    Symbol* symbolType = new Symbol(type, 1, 3);
    Symbol* symbolSemiColon = new Symbol(semicolon, 1, 4);
    vector<Symbol*> symbols = {id, symbolColon, symbolType, symbolSemiColon};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Declaration* declaration = new Declaration(indexer);

    declaration->construct();

    expect("", declaration->getIds() != 0);
    expect("", declaration->getType() != 0);

    delete declaration;
}

void DeclarationTest::getDeclaration_When_MultipleId() {
    string x = "x";
    string coma = ",";
    string y = "y";
    string colon = ":";
    string type = "number";
    string semicolon = ";";
    Symbol* symbolX = new Symbol(x, 1, 1);
    Symbol* symbolComa = new Symbol(coma, 1, 2);
    Symbol* symbolY = new Symbol(y, 1, 3);
    Symbol* symbolColon = new Symbol(colon, 1, 4);
    Symbol* symbolType = new Symbol(type, 1, 5);
    Symbol* symbolSemiColon = new Symbol(semicolon, 1, 6);
    vector<Symbol*> symbols = {
            symbolX, symbolComa, symbolY,
            symbolColon, symbolType, symbolSemiColon
    };
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Declaration* declaration = new Declaration(indexer);

    declaration->construct();

    expect("", declaration->getIds() != 0);
    expect("", declaration->getType() != 0);

    delete declaration;
}
