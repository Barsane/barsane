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
    bool isNext = strcmp(indexer.current(), type);
    expect("The current value should be 'number'",
            isNext == 0);
}

void IndexerTest::getCurrent_WhenBack() {

}

void IndexerTest::getCurrent_WhenReindex() {

}

void IndexerTest::getPosition_WhenNext() {

}

void IndexerTest::getPosition_WhenBack() {

}

void IndexerTest::getPosition_WhenReindex() {

}

void IndexerTest::getSize_When_BufferIs() {

}

void IndexerTest::verifyEnd_When_PositionIsNotLast() {

}

void IndexerTest::verifyEnd_When_PositionIsLast() {

}

void IndexerTest::verifyCurrent_When_Initiate() {

}

void IndexerTest::verifyPosition_When_Initiate() {

}

void IndexerTest::verifyEnd_When_Initiate() {

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

}

void IndexerTest::catchException_When_OutOfRange() {

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