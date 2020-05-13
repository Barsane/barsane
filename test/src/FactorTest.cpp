//
// Created by souls on 13/05/2020.
//

#include <functional>
#include "../include/FactorTest.h"

using namespace std;

void FactorTest::run() {
    getFactor_When_CurrentIsEmpty();
    getFactor_When_NotConstruct();
    getFactor_When_BadToken();
    positionChanged_WhenConstruct();
    getFactor_When_CurrentIsMinus();
    getFactor_When_CurrentIsLeftBracket();
    getFactor_When_CurrentIsId();
    getFactor_When_CurrentIsNumber();
    getFactor_When_NestedDeep();
}

void FactorTest::getFactor_When_CurrentIsEmpty() {
    vector<Symbol*> symbols = {};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Factor* factor = new Factor(indexer);

    factor->construct();

    expect("", factor->getMinus() == 0);
    expect("", factor->getId() == 0);
    expect("", factor->getNumber() == 0);
    expect("", factor->getLeftBracket() == 0);
    expect("", factor->getRightBracket() == 0);
    expect("", factor->getOperation() == 0);

    delete factor;
}

void FactorTest::getFactor_When_NotConstruct() {
    string minus = "-";
    string x = "x";
    Symbol* symbolMinus = new Symbol(minus, 1, 1);
    Symbol* symbolId = new Symbol(x, 1, 2);
    vector<Symbol*> symbols = {symbolMinus, symbolId};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Factor* factor = new Factor(indexer);

    expect("", factor->getMinus() == 0);
    expect("", factor->getId() == 0);
    expect("", factor->getNumber() == 0);
    expect("", factor->getLeftBracket() == 0);
    expect("", factor->getRightBracket() == 0);
    expect("", factor->getOperation() == 0);

    delete factor;
}

void FactorTest::getFactor_When_BadToken() {
    string bad = "true";
    string x = "x";
    Symbol* symbolBad = new Symbol(bad, 1, 1);
    Symbol* symbolId = new Symbol(x, 1, 2);
    vector<Symbol*> symbols = {symbolBad, symbolId};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Factor* factor = new Factor(indexer);

    factor->construct();

    expect("", factor->getMinus() == 0);
    expect("", factor->getId() == 0);
    expect("", factor->getNumber() == 0);
    expect("", factor->getLeftBracket() == 0);
    expect("", factor->getRightBracket() == 0);
    expect("", factor->getOperation() == 0);

    delete factor;
}

void FactorTest::positionChanged_WhenConstruct() {
    string minus = "-";
    string x = "x";
    Symbol* symbolMinus = new Symbol(minus, 1, 1);
    Symbol* symbolId = new Symbol(x, 1, 2);
    vector<Symbol*> symbols = {symbolMinus, symbolId};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Factor* factor = new Factor(indexer);

    unsigned int previous = indexer->position();
    factor->construct();
    unsigned int current = indexer->position();

    expect("Current index should be equal the previous because it is the last",
           previous + 2 == current);

    delete factor;
}

void FactorTest::getFactor_When_CurrentIsMinus() {
    string minus = "-";
    string x = "x";
    Symbol* symbolMinus = new Symbol(minus, 1, 1);
    Symbol* symbolId = new Symbol(x, 1, 2);
    vector<Symbol*> symbols = {symbolMinus, symbolId};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Factor* factor = new Factor(indexer);

    factor->construct();

    expect("", factor->getMinus() != 0);
    expect("", factor->getMinus()->getToken() == minus);
    expect("", factor->getId() != 0);
    expect("", factor->getNumber() == 0);
    expect("", factor->getLeftBracket() == 0);
    expect("", factor->getRightBracket() == 0);
    expect("", factor->getOperation() == 0);

    delete factor;
}

void FactorTest::getFactor_When_CurrentIsLeftBracket() {
    // ["-"] {id} | ["-"] {number} | "(" {operation} ")
    string left = "(";
    string x = "x";
    string number = "1";
    string plus = "+";
    string right = ")";
    Symbol* symbolLeft = new Symbol(left, 1, 1);
    Symbol* symbolId = new Symbol(x, 1, 2);
    Symbol* symbolPlus = new Symbol(plus, 1, 3);
    Symbol* symbolNum = new Symbol(number, 1, 4);
    Symbol* symbolRight = new Symbol(right, 1, 5);
    vector<Symbol*> symbols = {symbolLeft, symbolId, symbolPlus, symbolNum, symbolRight};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Factor* factor = new Factor(indexer);

    factor->construct();

    expect("", factor->getLeftBracket() != 0);
    expect("", factor->getLeftBracket()->getToken() == left);
    expect("", factor->getOperation() != 0);
    expect("", factor->getRightBracket() != 0);
    expect("", factor->getRightBracket()->getToken() == right);
    expect("", factor->getId() == 0);
    expect("", factor->getNumber() == 0);
    expect("", factor->getMinus() == 0);

    delete factor;
}

void FactorTest::getFactor_When_CurrentIsId() {
    string x = "x";
    string any = "any";
    Symbol* symbolId = new Symbol(x, 1, 2);
    Symbol* symbolAny = new Symbol(any, 1, 3);
    vector<Symbol*> symbols = {symbolId, symbolAny};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Factor* factor = new Factor(indexer);

    factor->construct();

    expect("", factor->getMinus() == 0);
    expect("", factor->getId() != 0);
    expect("", *factor->getId()->getName() == x);
    expect("", factor->getNumber() == 0);
    expect("", factor->getLeftBracket() == 0);
    expect("", factor->getRightBracket() == 0);
    expect("", factor->getOperation() == 0);

    delete factor;
}

void FactorTest::getFactor_When_CurrentIsNumber() {
    string number = "1000.53";
    string any = "any";
    Symbol* symbolNum = new Symbol(number, 1, 2);
    Symbol* symbolAny = new Symbol(any, 1, 3);
    vector<Symbol*> symbols = {symbolNum, symbolAny};
    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Factor* factor = new Factor(indexer);

    factor->construct();

    expect("", factor->getMinus() == 0);
    expect("", factor->getId() == 0);
    expect("", factor->getNumber() != 0);
    expect("", factor->getNumber()->getType() != NumberType::UNDEFINED);
    expect("", factor->getLeftBracket() == 0);
    expect("", factor->getRightBracket() == 0);
    expect("", factor->getOperation() == 0);

    delete factor;
}

void FactorTest::getFactor_When_NestedDeep() {
    // (-3 * ( 6 / 3 + 1 * (2 + 7) / 3)) + x * ( x + 5)
    string char0 = "(";
    string minus = "-";
    string char1 = "3";
    string char2 = "*";
    string char3 = "(";
    string char4 = "6";
    string char5 = "/";
    string char6 = "3";
    string char7 = "+";
    string char8 = "1";
    string char9 = "*";
    string char10 = "(";
    string char11 = "2";
    string char12 = "+";
    string char13 = "7";
    string char14 = ")";
    string char15 = "/";
    string char16 = "3";
    string char17 = ")";
    string char18 = ")";
    string char19 = "+";
    string char20 = "x";
    string char21 = "*";
    string char22 = "(";
    string char23 = "x";
    string char24 = "+";
    string char25 = "5";
    string char26 = ")";
    Symbol* symbol0 = new Symbol(char0, 1, 1);
    Symbol* symbolMinus = new Symbol(minus, 1, 1);
    Symbol* symbol1 = new Symbol(char1, 1, 1);
    Symbol* symbol2 = new Symbol(char2, 1, 2);
    Symbol* symbol3 = new Symbol(char3, 1, 3);
    Symbol* symbol4 = new Symbol(char4, 1, 4);
    Symbol* symbol5 = new Symbol(char5, 1, 5);
    Symbol* symbol6 = new Symbol(char6, 1, 6);
    Symbol* symbol7 = new Symbol(char7, 1, 7);
    Symbol* symbol8 = new Symbol(char8, 1, 8);
    Symbol* symbol9 = new Symbol(char9, 1, 9);
    Symbol* symbol10 = new Symbol(char10, 1, 10);
    Symbol* symbol11 = new Symbol(char11, 1, 11);
    Symbol* symbol12 = new Symbol(char12, 1, 12);
    Symbol* symbol13 = new Symbol(char13, 1, 13);
    Symbol* symbol14 = new Symbol(char14, 1, 14);
    Symbol* symbol15 = new Symbol(char15, 1, 15);
    Symbol* symbol16 = new Symbol(char16, 1, 16);
    Symbol* symbol17 = new Symbol(char17, 1, 17);
    Symbol* symbol18 = new Symbol(char18, 1, 18);
    Symbol* symbol19 = new Symbol(char19, 1, 19);
    Symbol* symbol20 = new Symbol(char20, 1, 20);
    Symbol* symbol21 = new Symbol(char21, 1, 21);
    Symbol* symbol22 = new Symbol(char22, 1, 22);
    Symbol* symbol23 = new Symbol(char23, 1, 23);
    Symbol* symbol24 = new Symbol(char24, 1, 24);
    Symbol* symbol25 = new Symbol(char25, 1, 25);
    Symbol* symbol26 = new Symbol(char26, 1, 26);

    vector<Symbol*> symbols = {
            symbol0,
            symbolMinus,
            symbol1,
            symbol2,
            symbol3,
            symbol4,
            symbol5,
            symbol6,
            symbol7,
            symbol8,
            symbol9,
            symbol10,
            symbol11,
            symbol12,
            symbol13,
            symbol14,
            symbol15,
            symbol16,
            symbol17,
            symbol18,
            symbol19,
            symbol20,
            symbol21,
            symbol22,
            symbol23,
            symbol24,
            symbol25,
            symbol26
    };

    Indexer<Symbol>* indexer = new Indexer<Symbol>(symbols);
    Factor* factor = new Factor(indexer);

    factor->construct();

    // (-3 * ( 6 / 3 + 1 * (2 + 7) / 3)) + x * ( x + 5)
    expect("", factor->getMinus() == 0);
    expect("", factor->getId() == 0);
    expect("", factor->getNumber() == 0);
    expectIf("", factor->getLeftBracket() != 0, [&]() {
       Symbol* left = factor->getLeftBracket();
       expect("", left->getToken() == "(");
    });
    expectIf("", factor->getOperation() != 0, [&]() {
      Operation* operation = factor->getOperation();
      expectIf("", operation->getTerm() != 0, [&]() {
        Term *term = operation->getTerm();
        expectIf("", term->getFactor() != 0, [&]() {
          Factor* factor = term->getFactor();
          expectIf("", factor->getMinus() != 0, [&]() {
            Symbol* minus = factor->getMinus();
            expect("", minus->getToken() == "-");
          });
          expect("", factor->getId() == 0);
          expectIf("", factor->getNumber() != 0, [&]() {
            Number* number = factor->getNumber();
            expect("", *number->getInteger() == 3);
          });
          expect("", factor->getLeftBracket() == 0);
          expect("", factor->getRightBracket() == 0);
          expect("", factor->getOperation() == 0);
        });
        expectIf("", term->getOperator() != 0, [&]() {
          Symbol* operator_ = term->getOperator();
          expect("", operator_->getToken() == "*");
        });
        expectIf("", term->getTerm(), [&]() {
          Term* right = term->getTerm();
          expectIf("", right->getFactor() != 0, [&]() {
            Factor* factor = right->getFactor();
            expect("", factor->getMinus() == 0);
            expect("", factor->getId() == 0);
            expect("", factor->getNumber() == 0);
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
                    expect("", factor->getId() == 0);
                    expectIf("", factor->getNumber() != 0,[&]() {
                        Number* number = factor->getNumber();
                        expect("", *number->getInteger() == 6);
                    });
                    expect("", factor->getLeftBracket() == 0);
                    expect("", factor->getOperation() == 0);
                    expect("", factor->getRightBracket() == 0);
                });
                expectIf("", term->getOperator() != 0, [&]() {
                    Symbol* operator_ = term->getOperator();
                    expect("", operator_->getToken() == "/");
                });
                expectIf("", term->getTerm() != 0, [&]() {
                  Term* right = term->getTerm();
                  expectIf("", right->getFactor() != 0, [&]() {});
                  expect("", right->getOperator() == 0);
                  expectIf("", right->getFactor() != 0, [&]() {
                    Factor* factor = right->getFactor();
                    expect("", factor->getMinus() == 0);
                    expect("", factor->getId() == 0);
                    expectIf("", factor->getNumber() != 0, [&]() {
                      Number* number = factor->getNumber();
                      expect("", *number->getInteger() == 3);
                    });
                    expect("", factor->getLeftBracket() == 0);
                    expect("", factor->getOperation() == 0);
                    expect("", factor->getRightBracket() == 0);
                  });
                });
              });
              expectIf("", operation->getOperator() != 0, [&] () {
                Symbol* operator_ = operation->getOperator();
                expect("", operator_->getToken() == "+");
              });
              expectIf("", operation->getOperation() != 0, [&]() {
                Operation* right = operation->getOperation();
                expectIf("", right->getTerm() != 0, [&]() {
                  term = right->getTerm();
                  expectIf("", term->getFactor() != 0, [&]() {
                    Factor* factor = term->getFactor();
                    expect("", factor->getMinus() == 0);
                    expect("", factor->getId() == 0);
                    expectIf("", factor->getNumber() != 0, [&]() {
                      Number* number = factor->getNumber();
                      expect("", *number->getInteger() == 1);
                    });
                    expect("", factor->getLeftBracket() == 0);
                    expect("", factor->getOperation() == 0);
                    expect("", factor->getRightBracket() == 0);
                  });
                });
                expect("", right->getOperator() == 0);
                expect("", right->getOperation() == 0);
              });
            });
            expectIf("", factor->getRightBracket() != 0, [&]() {
              Symbol* left = factor->getRightBracket();
              expect("", left->getToken() == ")");
            });
          });
          expect("", right->getOperator() == 0);
          expect("", right->getTerm() == 0);
        });
      });
      expect("", operation->getOperator() == 0);
      expect("", operation->getOperation() == 0);
    });
    expectIf("", factor->getRightBracket() != 0, [&]() {
        Symbol* right = factor->getRightBracket();
        expect("", right->getToken() == ")");
    });

    delete factor;
}