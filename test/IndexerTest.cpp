//
// Created by souls on 30/04/2020.
//

#include "IndexerTest.h"

void IndexerTest::getCurrent_WhenNext() {
    // Given
    char id[] = "x"; char type[] = "number"; char sc[] = ";";
    vector<char *> text = {id, type, sc};
    Indexer<char> indexer = Indexer<char>(text);

    // When
    indexer.next();

    // Then
    int isNext = strcmp(indexer.current(), type);
    expect("The current value should be 'number'",
            isNext == 0);
}

void IndexerTest::getCurrent_WhenBack() {
    // Given
    char id[] = "x"; char type[] = "number"; char sc[] = ";";
    vector<char *> text = {id, type, sc};
    Indexer<char> indexer = Indexer<char>(text);

    // When
    indexer.reindex(1);
    indexer.back();

    // Then
    int isBack = strcmp(indexer.current(), id);
    expect("The current value should be 'x'",
           isBack == 0);

}

void IndexerTest::getCurrent_WhenReindex() {
    // Given
    char id[] = "x"; char type[] = "number"; char sc[] = ";";
    vector<char *> text = {id, type, sc};
    Indexer<char> indexer = Indexer<char>(text);

    // When
    indexer.reindex(2);

    // Then
    int isCurrent = strcmp(indexer.current(), sc);
    expect("The current value should be ';'",
           isCurrent == 0);
}

void IndexerTest::getPosition_WhenNext() {
    // Given
    char id[] = "x"; char type[] = "number"; char sc[] = ";";
    vector<char *> text = {id, type, sc};
    Indexer<char> indexer = Indexer<char>(text);

    // When
    indexer.next();

    // Then
    expect("The current position should be 1",
           indexer.position() == 1);
}

void IndexerTest::getPosition_WhenBack() {
    // Given
    char id[] = "x"; char type[] = "number"; char sc[] = ";";
    vector<char *> text = {id, type, sc};
    Indexer<char> indexer = Indexer<char>(text);

    // When
    indexer.reindex(1);
    indexer.back();

    // Then
    expect("The current position should be 0",
           indexer.position() == 0);
}

void IndexerTest::getPosition_WhenReindex() {
    // Given
    char id[] = "x"; char type[] = "number"; char sc[] = ";";
    vector<char *> text = {id, type, sc};
    Indexer<char> indexer = Indexer<char>(text);

    // When
    indexer.reindex(2);

    // Then
    expect("The current position should be 2",
           indexer.position() == 2);
}

void IndexerTest::getSize_When_BufferIs() {
    // Given
    char id[] = "x"; char type[] = "number"; char sc[] = ";";
    vector<char *> text = {id, type, sc};
    Indexer<char> indexer = Indexer<char>(text);

    // Then
    expect("The size index should be 3", indexer.size() == 3);
}

void IndexerTest::verifyEnd_When_PositionIsNotLast() {
    // Given
    char id[] = "x"; char type[] = "number"; char sc[] = ";";
    vector<char *> text = {id, type, sc};
    Indexer<char> indexer = Indexer<char>(text);

    // Then
    expect("It is not end", !indexer.end());
}

void IndexerTest::verifyEnd_When_PositionIsLast() {
    // Given
    char id[] = "x"; char type[] = "number"; char sc[] = ";";
    vector<char *> text = {id, type, sc};
    Indexer<char> indexer = Indexer<char>(text);

    // When
    indexer.reindex(2);

    // Then
    expect("It is end", indexer.end());
}

void IndexerTest::verifyCurrent_When_Initiate() {
    // Given
    char id[] = "x"; char type[] = "number"; char sc[] = ";";
    vector<char *> text = {id, type, sc};
    Indexer<char> indexer = Indexer<char>(text);

    // Then
    expect("The current value should be 'x'",
            strcmp(indexer.current(), id) == 0);
}

void IndexerTest::verifyPosition_When_Initiate() {
    // Given
    char id[] = "x"; char type[] = "number"; char sc[] = ";";
    vector<char *> text = {id, type, sc};
    Indexer<char> indexer = Indexer<char>(text);

    // Then
    expect("The position should be 0",
           indexer.position() == 0);
}

void IndexerTest::verifyEnd_When_Initiate() {
    // Given
    char id[] = "x"; char type[] = "number"; char sc[] = ";";
    vector<char *> text = {id, type, sc};
    Indexer<char> indexer = Indexer<char>(text);

    // Then
    expect("It is not end",!indexer.end());
}



void IndexerTest::catchException_WhenNext_ThenLast() {
    char id[] = "x"; char type[] = "number";
    vector<char *> text = {id, type};
    Indexer<char> indexer = Indexer<char>(text);

    // When
    indexer.next();

    // Then
    bool caught = false;
    try {
        indexer.next();
    } catch (...) {
        caught = true;
    }
    expect("An exception should be throw", caught == true);
}

void IndexerTest::catchException_WhenBack_ThenFirst() {
    char id[] = "x"; char type[] = "number";
    vector<char *> text = {id, type};
    Indexer<char> indexer = Indexer<char>(text);


    // When
    bool caught = false;
    try {
        indexer.back();
    } catch (...) {
        caught = true;
    }

    // Then
    expect("An exception should be throw", caught == true);
}

void IndexerTest::catchException_When_OutOfRange() {

    char id[] = "x"; char type[] = "number";
    vector<char *> text = {id, type};
    Indexer<char> indexer = Indexer<char>(text);

    // Given
    bool caught = false;
    try {
        indexer.reindex(100);
    } catch (...) {
        caught = true;
    }

    // Then
    expect("An exception should be throw", caught == true);
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
    catchException_WhenNext_ThenLast();
    catchException_WhenBack_ThenFirst();
    catchException_When_OutOfRange();
}