//
// Created by souls on 30/04/2020.
//

#ifndef BARZANE_LEXER_H
#define BARZANE_LEXER_H

#include <ostream>
#include "Indexer.h"
#include "Symbol.h"
#include "ErrorHandler.h"

using namespace std;

/**
 * The lexer converts a sequence of characters for a given input
 * into a indexer of tokens (symbol @see Symbol for meaning). It is
 * defined like the first phase to Barzane compiler.
 *
 * It has like also another goal to recovery the matching errors
 * during the conversion.
 */
class Lexer {

    friend ostream& operator<<(ostream& out, const Lexer& lexer);
    typedef Indexer<Indexer<char>> LineIndexer;
    typedef Indexer<char> CharIndexer;

    public:
        /**
         * Constructor
         *
         * @param text: A sequence of characters to tokenize.
         */
        Lexer(const string& text);

        /**
         * Destructor
         */
        ~Lexer();

        /**
         * Get the indexed tokens.
         *
         * @return a pointer of symbol indexer.
         */
        Indexer<Symbol>* getTokens() const;

        /**
         * Get the total tokens.
         *
         * @return a unsigned integer.
         */
        const unsigned int length() const;

        /**
         * Display a set of errors recovered while converting.
         */
        void displayErrors();

        /**
         * Check if there is at least one error.
         *
         * @return true if there is an error else false.
         */
        bool hasErrors();

    private:
        Indexer<Symbol>* tokens;
        ErrorHandler errorHandler;
};


#endif //BARZANE_LEXER_H
