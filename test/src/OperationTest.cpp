//
// Created by souls on 13/05/2020.
//

#include "../include/OperationTest.h"

void OperationTest::run() {
    getOperation_When_CurrentIsEmpty();
    getOperation_When_NotConstruct();
    getOperation_When_BadToken();
    positionChanged_WhenConstruct();
    getOperation_When_CurrentIsMinus();
    getOperation_When_CurrentIsLeftBracket();
    getOperation_When_CurrentIsId();
    getOperation_When_CurrentIsNumber();
    getOperation_When_MissingTerm();
    getOperation_When_MissingOperation();
    getOperation_When_MissingOperator();
    getOperation_When_OnlyTerm();
}

void OperationTest::getOperation_When_CurrentIsEmpty() {
    vector<Symbol*> symbols = {};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Operation* operation = new Operation(indexer);

    operation->construct();

    expect("", operation->getTerm() == 0);
    expect("", operation->getOperator() == 0);
    expect("", operation->getOperation() == 0);

    delete operation;
}

void OperationTest::getOperation_When_NotConstruct() {
    string minus = "-";
    string number = "3";
    string plus = "+";
    string id = "x";
    Symbol* symbolMinus = new Symbol(minus, 1, 1);
    Symbol* symbolNum = new Symbol(number, 1, 2);
    Symbol* symbolPlus = new Symbol(plus, 1, 3);
    Symbol* symbolId = new Symbol(id, 1, 4);
    vector<Symbol*> symbols = {symbolMinus, symbolNum, symbolPlus, symbolId};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Operation* operation = new Operation(indexer);

    expect("", operation->getTerm() == 0);
    expect("", operation->getOperator() == 0);
    expect("", operation->getOperation() == 0);

    delete operation;
}

void OperationTest::getOperation_When_BadToken() {
    string minus = "-";
    string number = "3";
    string bad = "hello";
    string id = "x";
    Symbol* symbolMinus = new Symbol(minus, 1, 1);
    Symbol* symbolNum = new Symbol(number, 1, 2);
    Symbol* symbolBad = new Symbol(bad, 1, 3);
    Symbol* symbolId = new Symbol(id, 1, 4);
    vector<Symbol*> symbols = {symbolMinus, symbolNum, symbolBad, symbolId};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Operation* operation = new Operation(indexer);

    operation->construct();

    expect("", operation->getTerm() != 0);
    expect("", operation->getOperator() == 0);
    expect("", operation->getOperation() == 0);

    delete operation;
}

void OperationTest::positionChanged_WhenConstruct() {
    string minus = "-";
    string number = "3";
    string mul = "*";
    string id = "x";
    Symbol* symbolMinus = new Symbol(minus, 1, 1);
    Symbol* symbolNum = new Symbol(number, 1, 2);
    Symbol* symbolMul = new Symbol(mul, 1, 3);
    Symbol* symbolId = new Symbol(id, 1, 4);
    vector<Symbol*> symbols = {symbolMinus, symbolNum, symbolMul, symbolId};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Operation* operation = new Operation(indexer);

    unsigned int previous = indexer->position();
    operation->construct();
    unsigned int current = indexer->position();

    expect("", current == previous + 4);

    delete operation;
}

void OperationTest::getOperation_When_CurrentIsMinus() {
    string minus = "-";
    string number = "3";
    string plus = "+";
    string id = "x";
    Symbol* symbolMinus = new Symbol(minus, 1, 1);
    Symbol* symbolNum = new Symbol(number, 1, 2);
    Symbol* symbolPlus = new Symbol(plus, 1, 3);
    Symbol* symbolId = new Symbol(id, 1, 4);
    vector<Symbol*> symbols = {symbolMinus, symbolNum, symbolPlus, symbolId};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Operation* operation = new Operation(indexer);

    operation->construct();

    expectIf("", operation->getTerm() != 0, [&]() {
        Term* term = operation->getTerm();
        expectIf("", term->getFactor() != 0, [&]() {
            Factor *factor = term->getFactor();
            expectIf("", factor->getMinus() != 0, [&]() {
                Symbol* minus = factor->getMinus();
                expect("", minus->getToken() == "-");
            });
            expectIf("", factor->getNumber() != 0, [&]() {
                Number* number = factor->getNumber();
                expect("", *number->getInteger() == 3);
            });
            expect("", factor->getId() == 0);
            expect("", factor->getLeftBracket() == 0);
            expect("", factor->getOperation() == 0);
            expect("", factor->getRightBracket() == 0);
        });
        expect("",term->getOperator() == 0);
        expect("", term->getTerm() == 0);
    });
    expectIf("", operation->getOperator() != 0, [&]() {
        Symbol* operator_ = operation->getOperator();
        expect("", operator_->getToken() == "+");
    });
    expectIf("", operation->getOperation() != 0, [&]() {
        Operation* right = operation->getOperation();
        expectIf("", right->getTerm() != 0, [&]() {
            Term *term = right->getTerm();
            expectIf("", term->getFactor() != 0, [&]() {
                Factor *factor = term->getFactor();
                expect("", factor->getMinus() == 0);
                expect("", factor->getNumber() == 0);
                expectIf("", factor->getId() != 0, [&]() {
                    Id *id = factor->getId();
                    expect("", *id->getName() == "x");
                });
                expect("", factor->getLeftBracket() == 0);
                expect("", factor->getOperation() == 0);
                expect("", factor->getRightBracket() == 0);
            });
            expect("", term->getOperator() == 0);
            expect("", term->getTerm() == 0);
        });
        expect("", right->getOperator() == 0);
        expect("", right->getOperation() == 0);
    });

    delete operation;
}

void OperationTest::getOperation_When_CurrentIsLeftBracket() {
    string left = "(";
    string number = "3";
    string plus = "+";
    string id = "x";
    string right = ")";
    Symbol* symbolLeft = new Symbol(left, 1, 1);
    Symbol* symbolNum = new Symbol(number, 1, 2);
    Symbol* symbolPlus = new Symbol(plus, 1, 3);
    Symbol* symbolId = new Symbol(id, 1, 4);
    Symbol* symbolRight = new Symbol(right, 1, 5);
    vector<Symbol*> symbols = {symbolLeft, symbolNum, symbolPlus, symbolId, symbolRight};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Operation* operation = new Operation(indexer);

    operation->construct();

    expectIf("", operation->getTerm() != 0, [&]() {
        Term* term = operation->getTerm();
        expectIf("", term->getFactor() != 0, [&]() {
            Factor *factor = term->getFactor();
            expect("", factor->getMinus() == 0);
            expect("", factor->getNumber() == 0);
            expect("", factor->getId() == 0);
            expectIf("", factor->getLeftBracket() != 0, [&]() {
                Symbol* left = factor->getLeftBracket();
                expect("", left->getToken() == "(");
            });
            expectIf("", factor->getOperation() != 0, [&]() {
                Operation* operation = factor->getOperation();
                expectIf("", operation->getTerm() != 0, [&]() {
                    Term *term = operation->getTerm();
                    expectIf("", term->getFactor() != 0, [&]() {
                        Factor *factor = term->getFactor();
                        expect("", factor->getMinus() == 0);
                        expectIf("", factor->getNumber() != 0, [&]() {
                            Number* number = factor->getNumber();
                            expect("", *number->getInteger() == 3);
                        });
                        expect("", factor->getId() == 0);
                        expect("", factor->getLeftBracket() == 0);
                        expect("", factor->getOperation() == 0);
                        expect("", factor->getRightBracket() == 0);
                    });
                    expect("", term->getOperator() == 0);
                    expect("", term->getTerm() == 0);
                });
                expectIf("", operation->getOperator() != 0, [&]() {
                    Symbol* operator_ = operation->getOperator();
                    expect("", operator_->getToken() == "+");
                });
                expectIf("", operation->getOperation() != 0, [&]() {
                    Operation* right = operation->getOperation();
                    expectIf("", right->getTerm() != 0, [&]() {
                        Term *term = right->getTerm();
                        expectIf("", term->getFactor() != 0, [&]() {
                            Factor *factor = term->getFactor();
                            expect("", factor->getMinus() == 0);
                            expect("", factor->getNumber() == 0);
                            expectIf("", factor->getId() != 0, [&]() {
                                Id *id = factor->getId();
                                expect("", *id->getName() == "x");
                            });
                            expect("", factor->getLeftBracket() == 0);
                            expect("", factor->getOperation() == 0);
                            expect("", factor->getRightBracket() == 0);
                        });
                        expect("", term->getOperator() == 0);
                        expect("", term->getTerm() == 0);
                    });
                    expect("", right->getOperator() == 0);
                    expect("", right->getOperation() == 0);
                });
            });
            expectIf("", factor->getRightBracket() != 0, [&]() {
                Symbol* right = factor->getRightBracket();
                expect("", right->getToken() == ")");
            });
        });
        expect("",term->getOperator() == 0);
        expect("", term->getTerm() == 0);
    });
    expect("", operation->getOperator() == 0);
    expect("", operation->getOperation() == 0);

    delete operation;
}

void OperationTest::getOperation_When_CurrentIsId() {
    string id = "x";
    string minus = "-";
    string number = "3.5";
    Symbol* symbolId = new Symbol(id, 1, 1);
    Symbol* symbolMinus = new Symbol(minus, 1, 3);
    Symbol* symbolNum = new Symbol(number, 1, 6);
    vector<Symbol*> symbols = {symbolId, symbolMinus, symbolNum};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Operation* operation = new Operation(indexer);

    operation->construct();

    expectIf("", operation->getTerm() != 0, [&]() {
        Term* term = operation->getTerm();
        expectIf("", term->getFactor() != 0, [&]() {
            Factor *factor = term->getFactor();
            expect("", factor->getMinus() == 0);
            expect("", factor->getNumber() == 0);
            expectIf("", factor->getId() != 0, [&]() {
                Id* id = factor->getId();
                expect("", *id->getName() == "x");
            });
            expect("", factor->getLeftBracket() == 0);
            expect("", factor->getOperation() == 0);
            expect("", factor->getRightBracket() == 0);
        });
        expect("",term->getOperator() == 0);
        expect("", term->getTerm() == 0);
    });
    expectIf("", operation->getOperator() != 0, [&]() {
        Symbol* operator_ = operation->getOperator();
        expect("", operator_->getToken() == "-");
    });
    expectIf("", operation->getOperation() != 0, [&]() {
        Operation* right = operation->getOperation();
        expectIf("", right->getTerm() != 0, [&]() {
            Term *term = right->getTerm();
            expectIf("", term->getFactor() != 0, [&]() {
                Factor *factor = term->getFactor();
                expect("", factor->getMinus() == 0);
                expectIf("", factor->getNumber() != 0, [&]() {
                    Number* number = factor->getNumber();
                    expect("", *number->getReal() == 3.5);
                });
                expect("", factor->getId() == 0);
                expect("", factor->getLeftBracket() == 0);
                expect("", factor->getOperation() == 0);
                expect("", factor->getRightBracket() == 0);
            });
            expect("", term->getOperator() == 0);
            expect("", term->getTerm() == 0);
        });
        expect("", right->getOperator() == 0);
        expect("", right->getOperation() == 0);
    });

    delete operation;
}

void OperationTest::getOperation_When_CurrentIsNumber() {
    string number = "3.5";
    string minus = "-";
    string id = "x";
    Symbol* symbolNum = new Symbol(number, 1, 1);
    Symbol* symbolMinus = new Symbol(minus, 1, 3);
    Symbol* symbolId = new Symbol(id, 1, 6);
    vector<Symbol*> symbols = {symbolNum, symbolMinus, symbolId};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Operation* operation = new Operation(indexer);

    operation->construct();

    expectIf("", operation->getTerm() != 0, [&]() {
        Term* term = operation->getTerm();
        expectIf("", term->getFactor() != 0, [&]() {
            Factor *factor = term->getFactor();
            expect("", factor->getMinus() == 0);
            expectIf("", factor->getNumber() != 0, [&]() {
                Number* number = factor->getNumber();
                expect("", *number->getReal() == 3.5);
            });
            expect("", factor->getId() == 0);
            expect("", factor->getLeftBracket() == 0);
            expect("", factor->getOperation() == 0);
            expect("", factor->getRightBracket() == 0);
        });
        expect("",term->getOperator() == 0);
        expect("", term->getTerm() == 0);
    });
    expectIf("", operation->getOperator() != 0, [&]() {
        Symbol* operator_ = operation->getOperator();
        expect("", operator_->getToken() == "-");
    });
    expectIf("", operation->getOperation() != 0, [&]() {
        Operation* right = operation->getOperation();
        expectIf("", right->getTerm() != 0, [&]() {
            Term *term = right->getTerm();
            expectIf("", term->getFactor() != 0, [&]() {
                Factor *factor = term->getFactor();
                expect("", factor->getMinus() == 0);
                expect("", factor->getNumber() == 0);
                expectIf("", factor->getId() != 0, [&]() {
                    Id* id = factor->getId();
                    expect("", *id->getName() == "x");
                });
                expect("", factor->getLeftBracket() == 0);
                expect("", factor->getOperation() == 0);
                expect("", factor->getRightBracket() == 0);
            });
            expect("", term->getOperator() == 0);
            expect("", term->getTerm() == 0);
        });
        expect("", right->getOperator() == 0);
        expect("", right->getOperation() == 0);
    });

    delete operation;
}

void OperationTest::getOperation_When_MissingTerm() {
    string minus = "-";
    string id = "x";
    Symbol* symbolMinus = new Symbol(minus, 1, 3);
    Symbol* symbolId = new Symbol(id, 1, 6);
    vector<Symbol*> symbols = {symbolMinus, symbolId};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Operation* operation = new Operation(indexer);

    operation->construct();

    expectIf("", operation->getTerm() != 0, [&]() {
        Term* term = operation->getTerm();
        expectIf("", term->getFactor() != 0, [&]() {
            Factor* factor = term->getFactor();
            expectIf("", factor->getMinus() != 0, [&]() {
                Symbol* minus = factor->getMinus();
                expect("", minus->getToken() == "-");
            });
            expectIf("", factor->getId() != 0, [&]() {
                Id* id = factor->getId();
                expect("", *id->getName() == "x");
            });
            expect("", factor->getNumber() == 0);
            expect("", factor->getLeftBracket() == 0);
            expect("", factor->getOperation() == 0);
            expect("", factor->getRightBracket() == 0);
        });
        expect("", term->getOperator() == 0);
        expect("", term->getTerm() == 0);
    });
    expect("", operation->getOperator() == 0);
    expect("", operation->getOperation() == 0);

    delete operation;
}

void OperationTest::getOperation_When_MissingOperation() {
    string number = "3.5";
    string minus = "-";
    Symbol* symbolNum = new Symbol(number, 1, 1);
    Symbol* symbolMinus = new Symbol(minus, 1, 3);
    vector<Symbol*> symbols = {symbolNum, symbolMinus};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Operation* operation = new Operation(indexer);

    operation->construct();

    expect("", operation->getTerm() != 0);
    expect("", operation->getOperator() != 0);
    expect("", operation->getOperation() == 0);

    delete operation;
}

void OperationTest::getOperation_When_MissingOperator() {
    string number = "3.5";
    string id = "x";
    Symbol* symbolNum = new Symbol(number, 1, 1);
    Symbol* symbolId = new Symbol(id, 1, 6);
    vector<Symbol*> symbols = {symbolNum, symbolId};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Operation* operation = new Operation(indexer);

    operation->construct();

    expect("", operation->getTerm() != 0);
    expect("", operation->getOperator() == 0);
    expect("", operation->getOperation() == 0);

    delete operation;
}

void OperationTest::getOperation_When_OnlyTerm() {
    string number = "3.5";
    Symbol* symbolNum = new Symbol(number, 1, 1);
    vector<Symbol*> symbols = {symbolNum};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Operation* operation = new Operation(indexer);

    operation->construct();

    expect("", operation->getTerm() != 0);
    expect("", operation->getOperator() == 0);
    expect("", operation->getOperation() == 0);

    delete operation;
}

