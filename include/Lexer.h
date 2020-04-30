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

class Lexer {

    friend ostream& operator<<(ostream& out, const Lexer& lexer);
    typedef Indexer<Indexer<char>> LineIndexer;
    typedef Indexer<char> CharIndexer;

    public:
        Lexer(const string& text);
        ~Lexer();

        vector<Symbol*> getTokens() const;
        const unsigned int length() const;

    private:
        LineIndexer* stream;
};


#endif //BARZANE_LEXER_H
