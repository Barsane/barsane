//
// Created by souls on 30/04/2020.
//

#ifndef BARZANE_INDEXERTEST_H
#define BARZANE_INDEXERTEST_H

#include <cstring>
#include "Test.h"
#include "expect.h"
#include "../include/Indexer.h"

class IndexerTest: public Test {

    public:
        void run();

    private:
        void getCurrent_WhenNext();
        void getCurrent_WhenBack();
        void getCurrent_WhenReindex();
        void getPosition_WhenNext();
        void getPosition_WhenBack();
        void getPosition_WhenReindex();
        void getSize_When_BufferIs();
        void verifyEnd_When_PositionIsNotLast();
        void verifyEnd_When_PositionIsLast();
        void verifyCurrent_When_Initiate();
        void verifyPosition_When_Initiate();
        void verifyEnd_When_Initiate();

        // Rules
        void catchException_WhenNext_ThenLast();
        void catchException_WhenBack_ThenFirst();
        void catchException_When_OutOfRange();
};


#endif //BARZANE_INDEXERTEST_H
