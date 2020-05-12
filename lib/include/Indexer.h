//
// Created by souls on 30/04/2020.
//


#ifndef BARZANE_INDEXER_H
#define BARZANE_INDEXER_H

#include <vector>
#include <set>
#include <iostream>
#include <ostream>

using namespace std;

/**
 * It provides a way to access the elements of an array
 * sequentially without exposing its underlying representation.
 * It allows from the object to index to:
 *
 *      get the current value or position
 *      point the cursor on the next or the previous element
 *      point the cursor on whatever position
 *      check if the cursor is on the last element
 *
 * @tparam T The buffer typename to index.
 */
template<typename T> class Indexer {

    /**
     * A representative object of Indexer class.
     *
     * @tparam U: typename to index.
     * @param out: a stream object.
     * @param indexer: an indexer to represent
     * @return Get the given stream after push the representation string.
     */
    template<typename U> friend ostream& operator<<(ostream& out, const Indexer<U>& indexer);

    public:
        /**
         * Constructor
         *
         * @param buf: The buffer to index
         */
        Indexer(vector<T*> buf);

        /**
         * Destructor
         */
        ~Indexer();

        /**
         * Point on the next element.
         *
         * Note it raises an exception when the current position
         * is the last.
         */
        void next();

        /**
         * Point on the previous element.
         *
         * Note it raises an exception when the current position
         * is the first.
         */
        void back();

        /**
         * point on whatever element as long as it is not out of range
         * from the buffer. Otherwise, this method raises an exception.
         *
         * @param pos: the position that the index place.
         */
        void reindex(unsigned int pos);

        /**
         * Get the buffer size.
         *
         * @return an unsigned integer represented the size value.
         */
        unsigned int size() const;

        /**
         * Get the current element of the index.
         *
         * @return a pointer of the current element.
         */
        T* current();

        /**
         * Get the cursor position of the index.
         *
         * @return a unsigned integer represented the size value.
         */
        unsigned int position();

        /**
         * Check if the cursor is on the last element.
         *
         * @return true if the cursor is on the last element otherwise false.
         */
        bool end();

    private:
        vector<T*> buffer;
        unsigned int index;

        // INTERNAL USAGE
        inline static set<T*> __documents__;

};


/**
 * A representative object of Indexer class.
 *
 * @tparam U: typename to index.
 * @param out: a stream object.
 * @param indexer: an indexer to represent
 * @return Get the given stream after push the representation string.
 */
template<typename T> ostream& operator<<(ostream& out, const Indexer<T>& indexer);


#include "Indexer.hxx"

#endif //BARZANE_INDEXER_H
