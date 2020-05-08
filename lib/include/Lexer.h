//
// Created by souls on 30/04/2020.
//

#ifndef BARZANE_LEXER_H
#define BARZANE_LEXER_H

#include <ostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Indexer.h"
#include "Symbol.h"
#include "ErrorHandler.h"
#include "str.h"

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

    /**
     * A representative object of Lexer class.
     * @param out: a stream object.
     * @param symbol: A lexer to represent.
     * @return Get the given stream after push the representation string.
     */
    friend ostream& operator<<(ostream& out, const Lexer& lexer);

    typedef Indexer<Indexer<str>> LineIndexer;

    typedef Indexer<str> StrIndexer;

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
        unsigned int length() const;

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
        static LineIndexer indexText(const string& text);
        void tokenize(StrIndexer* strIndexer, unsigned int line);
        void extractSimpleToken(StrIndexer* strIndexer, unsigned int line);
        void extractSpecialToken(StrIndexer* strIndexer, unsigned int line);


        vector<Symbol*> tokens;
        ErrorHandler errorHandler;
};

/**
 * A representative object of Lexer class.
 * @param out: a stream object.
 * @param symbol: A lexer to represent.
 * @return Get the given stream after push the representation string.
 */
ostream& operator<<(ostream& out, const Lexer& lexer);

#endif //BARZANE_LEXER_H
