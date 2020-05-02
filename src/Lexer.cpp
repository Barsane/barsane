//
// Created by souls on 30/04/2020.
//

#include "../include/Lexer.h"

Lexer::Lexer(const string &text): tokens(0) {
    LineIndexer lineIndexer = indexText(text);
    while (!lineIndexer.end()) {
        tokenize(lineIndexer.current(), lineIndexer.position() + 1);
    }
}

Lexer::~Lexer() {
}

Indexer<Symbol>* Lexer::getTokens() const {
    return nullptr;
}

const unsigned int Lexer::length() const {
    return getTokens()->size();
}

void Lexer::displayErrors() {
    errorHandler.display();
}

bool Lexer::hasErrors() {
    return !errorHandler.empty();
}

Lexer::LineIndexer Lexer::indexText(const string &text) {
    stringstream stream(text);
    string line;
    vector<StrIndexer*> linesBuf;
    while (getline(stream, line)) {
        vector<str*> charVector(line.size());
        transform(line.begin(), line.end(), charVector.begin(),
                [](char s) { return new str(s); });
        StrIndexer* charIndexer = new StrIndexer(charVector);
        linesBuf.push_back(charIndexer);
    }
    LineIndexer indexer = LineIndexer(linesBuf);
    return indexer;
}

void Lexer::tokenize(Lexer::StrIndexer* strIndexer, unsigned int line) {
        while (!strIndexer->end()) {
            str* key = strIndexer->current();
           switch (key->getType()) {
               case SPACE:
                   strIndexer->next();
                   break;
               case ALPHANUMERIC_OR_UNDERSCORE:
                   extractSimpleToken(strIndexer, line);
                   break;
               case SPECIAL:
                   extractSpecialToken(strIndexer, line);
               default:
                   // TODO
                   cout << "Not implemented";
                   break;
           }
        }
}

void Lexer::extractSimpleToken(Lexer::StrIndexer *strIndexer, unsigned int line) {
    string expression = "";
    while (!strIndexer->end()) {
        str* current = strIndexer->current();
        if (!current->isSpecial() && current->isSpace()) {
            expression += current->value();
            strIndexer->next();
        } else {
            break;
        }
    }

    if (expression != "") {
        unsigned int colon = strIndexer->position();
        Symbol* symbol = new Symbol(expression, line, colon);
        tokens.push_back(symbol);
    }
}

void Lexer::extractSpecialToken(Lexer::StrIndexer *strIndexer, unsigned int line) {
    str* current = strIndexer->current();
    string token = current->value();
    unsigned int colon = strIndexer->position() + 1;
    Symbol* symbol = new Symbol(token, line, colon);
    tokens.push_back(symbol);
    strIndexer->next();
}
