//
// Created by souls on 30/04/2020.
//

#include "../include/IndexerTest.h"

void IndexerTest::getCurrent_WhenNext() {
    // Given
    str* id = new str("x");
    str* type = new str("number");
    str* sc = new str(";");
    vector<str*> text = {id, type, sc};
    Indexer<str> indexer = Indexer<str>(text);

    // When
    indexer.next();

    // Then
    expect("The current value should be 'number'",
            indexer.current()->value() == type->value());
}

void IndexerTest::getCurrent_WhenBack() {
    // Given
    str* id = new str("x");
    str* type = new str("number");
    str* sc = new str(";");
    vector<str*> text = {id, type, sc};
    Indexer<str> indexer = Indexer<str>(text);

    // When
    indexer.reindex(1);
    indexer.back();

    // Then
    expect("The current value should be 'x'",
           indexer.current()->value() == id->value());
}

void IndexerTest::getCurrent_WhenReindex() {
    // Given
    str* id = new str("x");
    str* type = new str("number");
    str* sc = new str(";");
    vector<str*> text = {id, type, sc};
    Indexer<str> indexer = Indexer<str>(text);

    // When
    indexer.reindex(2);

    // Then
    expect("The current value should be ';'",
           indexer.current()->value() == sc->value());
}

void IndexerTest::getPosition_WhenNext() {
    // Given
    str* id = new str("x");
    str* type = new str("number");
    str* sc = new str(";");
    vector<str*> text = {id, type, sc};
    Indexer<str> indexer = Indexer<str>(text);

    // When
    indexer.next();

    // Then
    expect("The current position should be 1",
           indexer.position() == 1);
}

void IndexerTest::getPosition_WhenBack() {
    // Given
    str* id = new str("x");
    str* type = new str("number");
    str* sc = new str(";");
    vector<str*> text = {id, type, sc};
    Indexer<str> indexer = Indexer<str>(text);

    // When
    indexer.reindex(1);
    indexer.back();

    // Then
    expect("The current position should be 0",
           indexer.position() == 0);
}

void IndexerTest::getPosition_WhenReindex() {
    // Given
    str* id = new str("x");
    str* type = new str("number");
    str* sc = new str(";");
    vector<str*> text = {id, type, sc};
    Indexer<str> indexer = Indexer<str>(text);

    // When
    indexer.reindex(2);

    // Then
    expect("The current position should be 2",
           indexer.position() == 2);
}

void IndexerTest::getSize_When_BufferIs() {
    // Given
    str* id = new str("x");
    str* type = new str("number");
    str* sc = new str(";");
    vector<str*> text = {id, type, sc};
    Indexer<str> indexer = Indexer<str>(text);

    // Then
    expect("The size index should be 3", indexer.size() == 3);
}

void IndexerTest::verifyEnd_When_PositionIsNotLast() {
    // Given
    str* id = new str("x");
    str* type = new str("number");
    str* sc = new str(";");
    vector<str*> text = {id, type, sc};
    Indexer<str> indexer = Indexer<str>(text);

    // Then
    expect("It is not end", !indexer.end());
}

void IndexerTest::verifyEnd_When_PositionIsLast() {
    // Given
    str* id = new str("x");
    str* type = new str("number");
    str* sc = new str(";");
    vector<str*> text = {id, type, sc};
    Indexer<str> indexer = Indexer<str>(text);

    // When
    indexer.reindex(3);

    // Then
    expect("It is end", indexer.end());
}

void IndexerTest::verifyCurrent_When_Initiate() {
    // Given
    str* id = new str("x");
    str* type = new str("number");
    str* sc = new str(";");
    vector<str*> text = {id, type, sc};
    Indexer<str> indexer = Indexer<str>(text);

    // Then
    expect("The current value should be 'x'",
            indexer.current()->value() == id->value());
}

void IndexerTest::verifyPosition_When_Initiate() {
    // Given
    str* id = new str("x");
    str* type = new str("number");
    str* sc = new str(";");
    vector<str*> text = {id, type, sc};
    Indexer<str> indexer = Indexer<str>(text);

    // Then
    expect("The position should be 0",
           indexer.position() == 0);
}

void IndexerTest::verifyEnd_When_Initiate() {
    // Given
    str* id = new str("x");
    str* type = new str("number");
    str* sc = new str(";");
    vector<str*> text = {id, type, sc};
    Indexer<str> indexer = Indexer<str>(text);

    // Then
    expect("It is not end",!indexer.end());
}



void IndexerTest::nullptr_WhenNext_ThenLast() {
    str* id = new str("x");
    str* type = new str("number");
    str* sc = new str(";");
    vector<str*> text = {id, type, sc};
    Indexer<str> indexer = Indexer<str>(text);

    // When
    indexer.next();
    indexer.next();
    indexer.next();

    // Then
    cout << indexer.current() << endl;
    expect("The current pointer should be 0", indexer.current() == 0);
}

void IndexerTest::nullptr_WhenBack_ThenFirst() {
    str* id = new str("x");
    str* type = new str("number");
    str* sc = new str(";");
    vector<str*> text = {id, type, sc};
    Indexer<str> indexer = Indexer<str>(text);


    // When
    indexer.back();

    // Then
    expect("An exception should be throw", indexer.current() == nullptr);
}

void IndexerTest::nullptr_When_OutOfRange() {

    str* id = new str("x");
    str* type = new str("number");
    str* sc = new str(";");
    vector<str*> text = {id, type, sc};
    Indexer<str> indexer = Indexer<str>(text);

    // Given
    indexer.reindex(100);

    // Then
    expect("An exception should be throw", indexer.current() == 0);
}

void IndexerTest::run() {
    getCurrent_WhenNext();
    getCurrent_WhenBack();
    getCurrent_WhenReindex();
    getPosition_WhenNext();
    getPosition_WhenBack();
    getPosition_WhenReindex();
    getSize_When_BufferIs();
    verifyEnd_When_PositionIsNotLast();
    verifyEnd_When_PositionIsLast();
    verifyCurrent_When_Initiate();
    verifyPosition_When_Initiate();
    verifyEnd_When_Initiate();
    nullptr_WhenNext_ThenLast();
    nullptr_WhenBack_ThenFirst();
    nullptr_When_OutOfRange();
}
