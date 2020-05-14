//
// Created by souls on 13/05/2020.
//

#include "../include/TermTest.h"

void TermTest::run() {
    getTerm_When_CurrentIsEmpty();
    getTerm_When_NotConstruct();
    getTerm_When_BadToken();
    positionChanged_WhenConstruct();
    getTerm_When_CurrentIsMinus();
    getTerm_When_CurrentIsLeftBracket();
    getTerm_When_CurrentIsId();
    getTerm_When_CurrentIsNumber();
    getTerm_When_MissingLeftFactor();
    getTerm_When_MissingRightFactor();
    getTerm_When_MissingOperator();
    getTerm_When_OnlyFactor();
    getTerm_When_NestedDeep();
}

void TermTest::getTerm_When_CurrentIsEmpty() {
    vector<Symbol*> symbols = {};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Term* term = new Term(indexer);

    term->construct();

    expect("", term->getFactor() == 0);
    expect("", term->getOperator() == 0);
    expect("", term->getTerm() == 0);

    delete term;
}

void TermTest::getTerm_When_NotConstruct() {
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
    Term* term = new Term(indexer);

    expect("", term->getFactor() == 0);
    expect("", term->getOperator() == 0);
    expect("", term->getTerm() == 0);

    delete term;
}

void TermTest::getTerm_When_BadToken() {
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
    Term* term = new Term(indexer);

    term->construct();

    expect("", term->getFactor() != 0);
    expect("", term->getOperator() == 0);
    expect("", term->getTerm() == 0);

    delete term;
}

void TermTest::positionChanged_WhenConstruct() {
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
    Term* term = new Term(indexer);

    term->construct();

    expect("", term->getFactor() != 0);
    expect("", term->getOperator() != 0);
    expect("", term->getTerm() != 0);

    delete term;
}

void TermTest::getTerm_When_CurrentIsMinus() {
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
    Term* term = new Term(indexer);

    term->construct();

    expectIf("", term->getFactor() != 0, [&]() {
        Factor* factor = term->getFactor();
        expect("", factor->getMinus() != 0);
        expect("", factor->getNumber() != 0);
        expect("", factor->getLeftBracket() == 0);
        expect("", factor->getOperation() == 0);
        expect("", factor->getRightBracket() == 0);
    });
    expectIf("", term->getOperator() != 0, [&]() {
        Symbol* operator_ = term->getOperator();
        expect("", operator_->getToken() == "*");
    });
    expectIf("", term->getTerm() != 0, [&]() {
        Term* right = term->getTerm();
        expectIf("", right->getFactor() !=0, [&]() {
           Factor* factor = right->getFactor();
           expect("", factor->getMinus() == 0);
           expect("", factor->getNumber() == 0);
           expectIf("", factor->getId() != 0, [&]() {
              Id* id = factor->getId();
              expect("", *id->getName() == "x");
           });
           expect("", factor->getRightBracket() == 0);
           expect("", factor->getOperation() == 0);
           expect("", factor->getRightBracket() == 0);
        });
        expect("", right->getOperator() == 0);
        expect("", right->getTerm() == 0);
    });

    delete term;
}

void TermTest::getTerm_When_CurrentIsLeftBracket() {
    string left = "(";
    string number = "3";
    string mul = "*";
    string id = "x";
    string right = ")";
    Symbol* symbolLeft = new Symbol(left, 1, 1);
    Symbol* symbolNum = new Symbol(number, 1, 2);
    Symbol* symbolMul = new Symbol(mul, 1, 3);
    Symbol* symbolId = new Symbol(id, 1, 4);
    Symbol* symbolRight = new Symbol(right, 1, 5);
    vector<Symbol*> symbols = {symbolLeft, symbolNum, symbolMul, symbolId, symbolRight};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Term* term = new Term(indexer);

    term->construct();

    expectIf("", term->getFactor() != 0, [&]() {
        Factor* factor = term->getFactor();
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
               Term* term = operation->getTerm();
               expectIf("", term->getFactor() != 0, [&]() {
                   Factor* factor = term->getFactor();
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
               expectIf("", term->getOperator() != 0, [&]() {
                   Symbol* operator_ = term->getOperator();
                   expect("", operator_->getToken() == "*");
               });
               expectIf("", term->getTerm() != 0, [&]() {
                   Term* right = term->getTerm();
                   expectIf("", right->getFactor(), [&]() {
                       Factor* factor = right->getFactor();
                       expect("", factor->getMinus() == 0);
                       expect("", factor->getNumber() == 0);
                       expectIf("", factor->getId() != 0, [&]() {
                           Id* id = factor->getId();
                           expect("", *id->getName() == "x");
                       });
                   });
                   expect("", right->getOperator() == 0);
                   expect("", right->getTerm() == 0);
               });
           });
        });
        expectIf("", factor->getRightBracket() != 0, [&]() {
            Symbol* right = factor->getRightBracket();
            expect("", right->getToken() == ")");
        });
    });
    expect("", term->getOperator() == 0);
    expect("", term->getTerm() ==0);

    delete term;
}

void TermTest::getTerm_When_CurrentIsId() {
    string id = "x";
    string mul = "/";
    string num = "5";
    Symbol* symbolId = new Symbol(id, 1, 1);
    Symbol* symbolMul = new Symbol(mul, 1, 3);
    Symbol* symbolNum = new Symbol(num, 1, 5);
    vector<Symbol*> symbols = {symbolId, symbolMul, symbolNum};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Term* term = new Term(indexer);

    term->construct();

    expectIf("", term->getFactor() != 0, [&](){
        Factor* factor = term->getFactor();
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
    expectIf("", term->getOperator() != 0, [&](){
        Symbol* operator_ = term->getOperator();
        expect("", operator_->getToken() == "/");
    });
    expectIf("", term->getTerm() != 0, [&]() {
        Term* right = term->getTerm();
        expectIf("", right->getFactor(), [&]() {
            Factor* factor = right->getFactor();
            expect("", factor->getMinus() == 0);
            expectIf("", factor->getNumber() != 0, [&]() {
                Number* number = factor->getNumber();
                expect("", *number->getInteger() == 5);
            });
            expect("", factor->getId() == 0);
            expect("", factor->getLeftBracket() == 0);
            expect("", factor->getOperation() == 0);
            expect("", factor->getRightBracket() == 0);
        });
        expect("", right->getOperator() == 0);
        expect("", right->getTerm() == 0);
    });

    delete term;
}

void TermTest::getTerm_When_CurrentIsNumber() {
    string left = "10";
    string mul = "*";
    string right = "8";
    Symbol* symbolLeft = new Symbol(left, 1, 1);
    Symbol* symbolMul = new Symbol(mul, 1, 3);
    Symbol* symbolRight = new Symbol(right, 1, 5);
    vector<Symbol*> symbols = {symbolLeft, symbolMul, symbolRight};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Term* term = new Term(indexer);

    term->construct();

    expectIf("", term->getFactor() != 0, [&](){
        Factor* factor = term->getFactor();
        expect("", factor->getMinus() == 0);
        expectIf("", factor->getNumber() != 0, [&]() {
            Number* number = factor->getNumber();
            expect("", *number->getInteger() = 10);
        });
        expect("", factor->getId() == 0);
        expect("", factor->getLeftBracket() == 0);
        expect("", factor->getOperation() == 0);
        expect("", factor->getRightBracket() == 0);
    });
    expectIf("", term->getOperator() != 0, [&](){
        Symbol* operator_ = term->getOperator();
        expect("", operator_->getToken() == "*");
    });
    expectIf("", term->getTerm() != 0, [&]() {
        Term* right = term->getTerm();
        expectIf("", right->getFactor(), [&]() {
            Factor* factor = right->getFactor();
            expect("", factor->getMinus() == 0);
            expectIf("", factor->getNumber() != 0, [&]() {
                Number* number = factor->getNumber();
                expect("", *number->getInteger() == 8);
            });
            expect("", factor->getId() == 0);
            expect("", factor->getLeftBracket() == 0);
            expect("", factor->getOperation() == 0);
            expect("", factor->getRightBracket() == 0);
        });
        expect("", right->getOperator() == 0);
        expect("", right->getTerm() == 0);
    });

    delete term;
}

void TermTest::getTerm_When_MissingLeftFactor() {
    string mul = "*";
    string right = "8";
    Symbol* symbolMul = new Symbol(mul, 1, 3);
    Symbol* symbolRight = new Symbol(right, 1, 5);
    vector<Symbol*> symbols = {symbolMul, symbolRight};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Term* term = new Term(indexer);

    term->construct();

    expect("", term->getFactor() == 0);
    expect("", term->getOperator() == 0);
    expect("", term->getTerm() == 0);

    delete term;
}

void TermTest::getTerm_When_MissingRightFactor() {
    string left = "10";
    string mul = "*";
    Symbol* symbolLeft = new Symbol(left, 1, 1);
    Symbol* symbolMul = new Symbol(mul, 1, 3);
    vector<Symbol*> symbols = {symbolLeft, symbolMul};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Term* term = new Term(indexer);

    term->construct();

    expect("", term->getFactor() != 0);
    expect("", term->getOperator() != 0);
    expectIf("", term->getTerm() != 0, [&]() {
        Term* right = term->getTerm();
        expect("", right->getFactor() == 0);
        expect("", right->getOperator() == 0);
        expect("", right->getTerm() == 0);
    });

    delete term;
}

void TermTest::getTerm_When_MissingOperator() {
    string left = "10";
    string right = "8";
    Symbol* symbolLeft = new Symbol(left, 1, 1);
    Symbol* symbolRight = new Symbol(right, 1, 5);
    vector<Symbol*> symbols = {symbolLeft, symbolRight};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Term* term = new Term(indexer);

    term->construct();

    expect("", term->getFactor() != 0);
    expect("", term->getOperator() == 0);
    expect("", term->getTerm() == 0);

    delete term;
}

void TermTest::getTerm_When_OnlyFactor() {
    string left = "10";
    string plus = "+";
    string right = "8";
    Symbol* symbolLeft = new Symbol(left, 1, 1);
    Symbol* symbolPlus = new Symbol(plus, 1, 3);
    Symbol* symbolRight = new Symbol(right, 1, 5);
    vector<Symbol*> symbols = {symbolLeft, symbolPlus, symbolRight};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Term* term = new Term(indexer);

    term->construct();

    expect("", term->getFactor() != 0);
    expect("", term->getOperator() == 0);
    expect("", term->getTerm() == 0);

    delete term;
}

void TermTest::getTerm_When_NestedDeep() {
    string ten = "10";
    string mul = "*";
    string eight = "8";
    string div = "/";
    string four = "4";
    Symbol* symbolTen = new Symbol(ten, 1, 1);
    Symbol* symbolMul = new Symbol(mul, 1, 3);
    Symbol* symbolEight = new Symbol(eight, 1, 5);
    Symbol* symbolDiv = new Symbol(div, 1, 7);
    Symbol* symbolFour = new Symbol(four, 1, 10);
    vector<Symbol*> symbols = {symbolTen, symbolMul, symbolEight, symbolDiv, symbolFour};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Term* term = new Term(indexer);

    term->construct();

    expectIf("", term->getFactor() != 0, [&](){
        Factor* factor = term->getFactor();
        expect("", factor->getMinus() == 0);
        expectIf("", factor->getNumber() != 0, [&]() {
            Number* number = factor->getNumber();
            expect("", *number->getInteger() = 10);
        });
        expect("", factor->getId() == 0);
        expect("", factor->getLeftBracket() == 0);
        expect("", factor->getOperation() == 0);
        expect("", factor->getRightBracket() == 0);
    });
    expectIf("", term->getOperator() != 0, [&](){
        Symbol* operator_ = term->getOperator();
        expect("", operator_->getToken() == "*");
    });
    expectIf("", term->getTerm() != 0, [&]() {
        Term* right = term->getTerm();
        expectIf("", right->getFactor(), [&]() {
            Factor* factor = right->getFactor();
            expect("", factor->getMinus() == 0);
            expectIf("", factor->getNumber() != 0, [&]() {
                Number* number = factor->getNumber();
                expect("", *number->getInteger() == 8);
            });
            expect("", factor->getId() == 0);
            expect("", factor->getLeftBracket() == 0);
            expect("", factor->getOperation() == 0);
            expect("", factor->getRightBracket() == 0);
        });
        expectIf("", right->getOperator() != 0, [&]() {
            Symbol* operator_ = right->getOperator();
            expect("", operator_->getToken() == "/");
        });
        expectIf("", right->getTerm() != 0, [&]() {
            Term* term = right->getTerm();
            expectIf("", term->getFactor() != 0, [&]() {
                Factor* factor = term->getFactor();
                expect("", factor->getMinus() == 0);
                expectIf("", factor->getNumber() != 0, [&]() {
                    Number* number = factor->getNumber();
                    expect("", *number->getInteger() = 4);
                });
                expect("", factor->getId() == 0);
                expect("", factor->getLeftBracket() == 0);
                expect("", factor->getOperation() == 0);
                expect("", factor->getRightBracket() == 0);
            });
            expect("", term->getOperator() == 0);
            expect("", term->getTerm() == 0);
        });
    });

    delete term;
}
