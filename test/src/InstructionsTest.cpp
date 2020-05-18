//
// Created by souls on 18/05/2020.
//

#include "../include/InstructionsTest.h"

void InstructionsTest::run() {
    getInstructions_When_CurrentIsEmpty();
    getInstructions_When_NotConstruct();
    getInstructions_When_OneInstr();
    getInstructions_When_MultipleInstrs();
    positionChanged_When_Construct();
}

void InstructionsTest::getInstructions_When_CurrentIsEmpty() {
    vector<Symbol*> symbols = {
    };
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Instructions* instructions = new Instructions(indexer);

    instructions->construct();

    expectIf("", instructions->getInstruction() != 0, [&]() {
        expect("", instructions->getInstruction()->getDeclarations() == 0);
        expect("", instructions->getInstruction()->getAffects() == 0);
        expect("", instructions->getInstruction()->getBuiltins() == 0);
    });
    expect("", instructions->getInstructions() == 0);

    delete instructions;
}

void InstructionsTest::getInstructions_When_NotConstruct() {
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
    Instructions* instructions = new Instructions(indexer);

    expect("", instructions->getInstruction() == 0);
    expect("", instructions->getInstructions() == 0);

    delete instructions;
}

void InstructionsTest::getInstructions_When_OneInstr() {
    string ch1 = "x";
    string ch2 = ":";
    string ch3 = "number";
    string ch4 = ";";

    Symbol* symbol1 = new Symbol(ch1, 1, 1);
    Symbol* symbol2 = new Symbol(ch2, 1, 2);
    Symbol* symbol3 = new Symbol(ch3, 1, 3);
    Symbol* symbol4 = new Symbol(ch4, 1, 4);

    vector<Symbol*> symbols = {
            symbol1, symbol2, symbol3,
            symbol4
    };
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Instructions* instructions = new Instructions(indexer);

    instructions->construct();

    expectIf("", instructions->getInstruction() != 0, [&]() {
        expect("", instructions->getInstruction()->getDeclarations() != 0);
    });
    expect("", instructions->getInstructions() == 0);

    delete instructions;
}

void InstructionsTest::getInstructions_When_MultipleInstrs() {
    string ch1 = "x";
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
    Symbol* symbol10 = new Symbol(ch9, 1, 10);
    Symbol* symbol11 = new Symbol(ch9, 1, 11);

    vector<Symbol*> symbols = {
            symbol1, symbol2, symbol3,
            symbol4, symbol5, symbol6,
            symbol7, symbol8, symbol9,
            symbol10, symbol11
    };
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Instructions* instructions = new Instructions(indexer);

    instructions->construct();

    expectIf("", instructions->getInstruction() != 0, [&]() {
        Instruction* instruction = instructions->getInstruction();
        expect("", instruction->getDeclarations() != 0);
        expect("", instruction->getAffects() == 0);
        expect("", instruction->getBuiltins() == 0);
    });
    expectIf("", instructions->getInstructions() != 0, [&]() {
        Instructions* instrs = instructions->getInstructions();
        expectIf("", instrs->getInstruction() != 0, [&]() {
            Instruction* instruction = instrs->getInstruction();
            expect("", instruction->getDeclarations() == 0);
            expect("", instruction->getAffects() != 0);
            expect("", instruction->getBuiltins() == 0);
        });
        expectIf("", instrs->getInstructions() != 0, [&]() {
            Instructions* instructions = instrs->getInstructions();
            expectIf("", instructions->getInstruction() != 0, [&]() {
                Instruction* instruction = instructions->getInstruction();
                expect("", instruction->getDeclarations() == 0);
                expect("", instruction->getAffects() == 0);
                expect("", instruction->getBuiltins() != 0);
            });
            expect("", instructions->getInstructions() == 0);
        });
    });

    delete instructions;
}

void InstructionsTest::positionChanged_When_Construct() {
    string ch1 = "x";
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
    Instructions* instructions = new Instructions(indexer);

    unsigned int previous = indexer->position();
    instructions->construct();
    unsigned int current = indexer->position();

    expect("", current == previous + 11);

    delete instructions;
}
