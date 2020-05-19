//
// Created by souls on 17/05/2020.
//

#include "../include/ASTTest.h"

void ASTTest::run() {
    getTree_When_CurrentIsEmpty();
    getTree_When_NotConstruct();
    getTree_When_Instructions();
    getTree_When_BadToken();
    positionChanged_When_Construct();
}

void ASTTest::getTree_When_CurrentIsEmpty() {
    vector<Symbol*> symbols = {};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    AST* ast = new AST(indexer);

    ast->construct();

    expect("", ast->getInstructions() == 0);

    delete ast;
}

void ASTTest::getTree_When_NotConstruct() {
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
    AST* ast = new AST(indexer);

    expect("", ast->getInstructions() == 0);

    delete ast;
}

void ASTTest::getTree_When_Instructions() {
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
            symbol4,
            symbol5, symbol6,
            symbol7, symbol8, symbol9,
            symbol10, symbol11
    };
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    AST* ast = new AST(indexer);

    ast->construct();

    expectIf("", ast->getInstructions() != 0, [&]() {
        Instructions* instructions = ast->getInstructions();
        expectIf("", instructions->getInstruction() != 0, [&]() {
            Instruction* instruction = instructions->getInstruction();
            expect("", instruction->getDeclarations() != 0);
            expect("", instruction->getAffects() == 0);
            expect("", instruction->getBuiltins() == 0);
        });
        expectIf("", instructions->getInstructions() != 0, [&]() {
            Instructions* instrs = instructions->getInstructions();
            expectIf("", instrs->getInstruction() != 0, [&]() {
                Instruction* instr = instrs->getInstruction();
                expect("", instr->getDeclarations() == 0);
                expect("", instr->getBuiltins() == 0);
                expect("", instr->getAffects() != 0);
            });
            expectIf("", instrs->getInstructions() != 0, [&]() {
                Instructions* instructions = instrs->getInstructions();
                expectIf("", instructions->getInstruction() != 0, [&]() {
                    Instruction* instruction = instructions->getInstruction();
                    expect("", instruction->getDeclarations() == 0);
                    expect("", instruction->getBuiltins() != 0);
                    expect("", instruction->getAffects() == 0);
                });
                expect("", instructions->getInstructions() == 0);
            });
        });
    });

    delete ast;
}

void ASTTest::getTree_When_BadToken() {
    string ch1 = "x";
    string ch2 = ":";
    string ch3 = "p";
    string ch4 = "m";
    string ch5 = "x";
    string ch6 = "=";
    string ch7 = "!Hello";
    string ch8 = ";";
    string ch9 = "print";
    string ch10 = "!";
    string ch11 = ";";

    Symbol* symbol1 = new Symbol(ch1, 1, 1);
    Symbol* symbol2 = new Symbol(ch2, 1, 2);
    Symbol* symbol3 = new Symbol(ch3, 1, 3);
    Symbol* symbol4 = new Symbol(ch4, 1, 4);
    Symbol* symbol5 = new Symbol(ch5, 1, 5);
    Symbol* symbol6 = new Symbol(ch6, 1, 6);
    Symbol* symbol7 = new Symbol(ch7, 1, 7);
    Symbol* symbol8 = new Symbol(ch8, 1, 8);
    Symbol* symbol9 = new Symbol(ch9, 2, 1);
    Symbol* symbol10 = new Symbol(ch10, 2, 3);
    Symbol* symbol11 = new Symbol(ch11, 2, 6);

    vector<Symbol*> symbols = {
            symbol1,
            symbol2,
            symbol3,
            symbol4,
            symbol5, symbol6,
            symbol7, symbol8,
            symbol9,
            symbol10,
            symbol11
    };
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    AST* ast = new AST(indexer);

    ast->construct();

    expectIf("", ast->getInstructions() != 0, [&]() {
        Instructions* instructions = ast->getInstructions();
        expectIf("", instructions->getInstruction() != 0, [&]() {
            Instruction* instruction = instructions->getInstruction();
            expectIf("", instruction->getDeclarations() != 0, [&]() {
                Declarations* declarations = instruction->getDeclarations();
                expectIf("", declarations->getDeclaration() != 0, [&]() {
                    Declaration* declaration = declarations->getDeclaration();
                    expectIf("", declaration->getIds() != 0, [&]() {
                        Ids* ids = declaration->getIds();
                        expectIf("", ids->getId() != 0, [&]() {
                            expect("", *ids->getId()->getName() == "x");
                        });
                        expect("", ids->getIds() == 0);
                    });
                    expectIf("", declaration->getType() != 0, [&]() {
                        expect("", declaration->getType()->getType() == NodeType::UNDEFINED);
                    });
                });
                expect("", declarations->getDeclarations() == 0);
            });
            expect("", instruction->getAffects() == 0);
            expect("", instruction->getBuiltins() == 0);
        });
        expectIf("", instructions->getInstructions() != 0, [&]() {
            Instructions* instrs = instructions->getInstructions();
            expectIf("", instrs->getInstruction() != 0, [&]() {
                Instruction* instruction = instrs->getInstruction();
                expect("", instruction->getDeclarations() == 0);
                expect("", instruction->getAffects() == 0);
                expectIf("", instruction->getBuiltins() != 0, [&]() {
                   Builtins* builtins = instruction->getBuiltins();
                   expectIf("", builtins->getPrint() != 0, [&]() {
                       // TODO: to fix
                       expect("Expression must not be null", builtins->getPrint()->getExpression() == 0);
                   });
                });
            });
            expect("", instrs->getInstructions() == 0);
        });
    });

    delete ast;
}

void ASTTest::positionChanged_When_Construct() {
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
    Symbol* symbol9 = new Symbol(ch9, 2, 1);
    Symbol* symbol10 = new Symbol(ch10, 2, 3);
    Symbol* symbol11 = new Symbol(ch11, 2, 6);

    vector<Symbol*> symbols = {
            symbol1,
            symbol2,
            symbol3,
            symbol4,
            symbol5, symbol6,
            symbol7, symbol8,
            symbol9,
            symbol10,
            symbol11
    };
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    AST* ast = new AST(indexer);

    unsigned int previous = indexer->position();
    ast->construct();
    unsigned int current = indexer->position();

    expect("", current == previous + 11);

    delete ast;
}
