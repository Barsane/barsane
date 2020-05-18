//
// Created by souls on 18/05/2020.
//

#include "../include/InstructionTest.h"

void InstructionTest::run() {
    getInstruction_When_CurrentIsEmpty();
    getInstruction_When_NotConstruct();
    positionChanged_When_Construct();
    getInstruction_When_Declaration();
    getInstruction_When_Affect();
    getInstruction_When_Builtin();
    getInstruction_When_BadToken();
}

void InstructionTest::getInstruction_When_CurrentIsEmpty() {
    vector<Symbol*> symbols = {
    };
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Instruction* instruction = new Instruction(indexer);

    instruction->construct();

    expect("", instruction->getDeclarations() == 0);
    expect("", instruction->getAffects() == 0);
    expect("", instruction->getBuiltins() == 0);

    delete instruction;
}

void InstructionTest::getInstruction_When_NotConstruct() {
    string ch1 = "x";
    string ch2 = ":";
    string ch3 = "number;";
    string ch4 = "x";
    string ch5 = "=";
    string ch6 = "1;";
    string ch7 = "print";
    string ch8 = "x";
    string ch9 = ";";

    Symbol* symbol1 = new Symbol(ch1, 1, 1);
    Symbol* symbol2 = new Symbol(ch2, 1, 2);
    Symbol* symbol3 = new Symbol(ch3, 1, 3);
    Symbol* symbol4 = new Symbol(ch4, 1, 4);
    Symbol* symbol5 = new Symbol(ch5, 1, 5);
    Symbol* symbol6 = new Symbol(ch6, 1, 6);
    Symbol* symbol7 = new Symbol(ch7, 1, 7);
    Symbol* symbol8 = new Symbol(ch8, 1, 8);
    Symbol* symbol9 = new Symbol(ch9, 1, 9);

    vector<Symbol*> symbols = {
            symbol1, symbol2, symbol3,
            symbol4, symbol5, symbol6,
            symbol7, symbol8, symbol9
    };
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Instruction* instruction = new Instruction(indexer);

    expect("", instruction->getDeclarations() == 0);
    expect("", instruction->getAffects() == 0);
    expect("", instruction->getBuiltins() == 0);

    delete instruction;
}

void InstructionTest::positionChanged_When_Construct() {
    string ch1 = "x";
    string ch2 = ":";
    string ch3 = "number;";
    string ch4 = "x";
    string ch5 = "=";
    string ch6 = "1;";
    string ch7 = "print";
    string ch8 = "x";
    string ch9 = ";";

    Symbol* symbol1 = new Symbol(ch1, 1, 1);
    Symbol* symbol2 = new Symbol(ch2, 1, 2);
    Symbol* symbol3 = new Symbol(ch3, 1, 3);
    Symbol* symbol4 = new Symbol(ch4, 1, 4);
    Symbol* symbol5 = new Symbol(ch5, 1, 5);
    Symbol* symbol6 = new Symbol(ch6, 1, 6);
    Symbol* symbol7 = new Symbol(ch7, 1, 7);
    Symbol* symbol8 = new Symbol(ch8, 1, 8);
    Symbol* symbol9 = new Symbol(ch9, 1, 9);

    vector<Symbol*> symbols = {
            symbol1, symbol2, symbol3,
            symbol4, symbol5, symbol6,
            symbol7, symbol8, symbol9
    };
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Instruction* instruction = new Instruction(indexer);

    unsigned int previous = indexer->position();
    instruction->construct();
    unsigned int current = indexer->position();

    expect("", current == previous + 9);

    delete instruction;
}

void InstructionTest::getInstruction_When_Declaration() {
    string ch1 = "x";
    string ch2 = ":";
    string ch3 = "number;";
    string ch4 = "x";
    string ch5 = "=";
    string ch6 = "1;";
    string ch7 = "print";
    string ch8 = "x";
    string ch9 = ";";

    Symbol* symbol1 = new Symbol(ch1, 1, 1);
    Symbol* symbol2 = new Symbol(ch2, 1, 2);
    Symbol* symbol3 = new Symbol(ch3, 1, 3);
    Symbol* symbol4 = new Symbol(ch4, 1, 4);
    Symbol* symbol5 = new Symbol(ch5, 1, 5);
    Symbol* symbol6 = new Symbol(ch6, 1, 6);
    Symbol* symbol7 = new Symbol(ch7, 1, 7);
    Symbol* symbol8 = new Symbol(ch8, 1, 8);
    Symbol* symbol9 = new Symbol(ch9, 1, 9);

    vector<Symbol*> symbols = {
            symbol1, symbol2, symbol3,
            symbol4, symbol5, symbol6,
            symbol7, symbol8, symbol9
    };
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Instruction* instruction = new Instruction(indexer);

    instruction->construct();

    expect("", instruction->getDeclarations() != 0);
    expect("", instruction->getBuiltins() == 0);
    expect("", instruction->getAffects() == 0);

    delete instruction;
}

void InstructionTest::getInstruction_When_Affect() {
    string ch4 = "x";
    string ch5 = "=";
    string ch6 = "1";
    string ch7 = ";";
    string ch8 = "print";
    string ch9 = "x";
    string ch10 = ";";

    Symbol* symbol4 = new Symbol(ch4, 1, 4);
    Symbol* symbol5 = new Symbol(ch5, 1, 5);
    Symbol* symbol6 = new Symbol(ch6, 1, 6);
    Symbol* symbol7 = new Symbol(ch7, 1, 7);
    Symbol* symbol8 = new Symbol(ch8, 1, 8);
    Symbol* symbol9 = new Symbol(ch9, 1, 9);
    Symbol* symbol10 = new Symbol(ch10, 1, 10);

    vector<Symbol*> symbols = {
            symbol4, symbol5, symbol6,
            symbol7, symbol8, symbol9, symbol10
    };
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Instruction* instruction = new Instruction(indexer);

    instruction->construct();

    expect("", instruction->getDeclarations() == 0);
    expect("", instruction->getBuiltins() == 0);
    expect("", instruction->getAffects() != 0);

    delete instruction;
}

void InstructionTest::getInstruction_When_Builtin() {
    string ch8 = "print";
    string ch9 = "x";
    string ch10 = ";";

    Symbol* symbol8 = new Symbol(ch8, 1, 8);
    Symbol* symbol9 = new Symbol(ch9, 1, 9);
    Symbol* symbol10 = new Symbol(ch10, 1, 10);

    vector<Symbol*> symbols = {
        symbol8, symbol9, symbol10
    };
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Instruction* instruction = new Instruction(indexer);

    instruction->construct();

    expect("", instruction->getDeclarations() == 0);
    expect("", instruction->getBuiltins() != 0);
    expect("", instruction->getAffects() == 0);

    delete instruction;
}

void InstructionTest::getInstruction_When_BadToken() {
    string ch1 = "1";
    string ch2 = ":";
    string ch3 = "number";
    string ch4 = ";";
    string ch5 = "x";
    string ch6 = "=";
    string ch7 = "1";
    string ch8 = ";";
    string ch9 = "print";
    string ch10 = "x";
    string ch11 = ";";

    Symbol* symbol1 = new Symbol(ch1, 1, 1);
    Symbol* symbol2 = new Symbol(ch2, 1, 2);
    Symbol* symbol3 = new Symbol(ch3, 1, 3);
    Symbol* symbol4 = new Symbol(ch4, 1, 4);
    Symbol* symbol5 = new Symbol(ch5, 1, 5);
    Symbol* symbol6 = new Symbol(ch6, 1, 6);
    Symbol* symbol7 = new Symbol(ch7, 1, 7);
    Symbol* symbol8 = new Symbol(ch8, 1, 8);
    Symbol* symbol9 = new Symbol(ch9, 1, 9);
    Symbol* symbol10 = new Symbol(ch10, 1, 10);
    Symbol* symbol11 = new Symbol(ch11, 1, 11);



    vector<Symbol*> symbols = {
            symbol1, symbol2, symbol3,
            symbol4, symbol5, symbol6,
            symbol7, symbol8, symbol9,
            symbol10, symbol11
    };
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Instruction* instruction = new Instruction(indexer);

    instruction->construct();

    expect("", instruction->getDeclarations() == 0);
    expect("", instruction->getBuiltins() == 0);
    expect("", instruction->getAffects() == 0);

    delete instruction;
}
