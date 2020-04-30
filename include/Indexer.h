//
// Created by souls on 30/04/2020.
//


#ifndef BARZANE_INDEXER_H
#define BARZANE_INDEXER_H

#include <vector>
#include <iostream>
#include <ostream>

using namespace std;

template<typename T> class Indexer {

    template<typename U> friend ostream& operator<<(ostream& out, const Indexer<U>& indexer);

public:
    Indexer(vector<T*> buf);
    ~Indexer();

    void next();
    void back();
    void reindex(unsigned int pos);
    const unsigned int size() const;
    T* current();
    unsigned int position();
    bool end();

private:
    vector<T*> buffer;
    unsigned int index;

};

template<typename T> ostream& operator<<(ostream& out, const Indexer<T>& indexer);

#include "Indexer.hxx"

#endif //BARZANE_INDEXER_H
