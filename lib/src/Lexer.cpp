//
// Created by souls on 30/04/2020.
//

#include "../include/Lexer.h"

Lexer::Lexer(const string &text) {
    LineIndexer lineIndexer = indexText(text);
    while (!lineIndexer.end()) {
        tokenize(lineIndexer.current(), lineIndexer.position() + 1);
        lineIndexer.next();
    }
    indexer = new Indexer<Symbol>(tokens);
}

Lexer::~Lexer() {
    delete indexer;
}

Indexer<Symbol>* Lexer::getTokens() const {
    return indexer;
}

unsigned int Lexer::length() const {
    return tokens.size();
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
               break;
           default:
               unsigned int colon = strIndexer->position() + 1;
               Error error = Error(UNEXPECTED_TOKEN, "Invalid character", line, colon);
               errorHandler.add(error);
               strIndexer->next();
               break;
       }
    }
}

void Lexer::extractSimpleToken(Lexer::StrIndexer *strIndexer, unsigned int line) {
    string expression = "";
    const unsigned int colon = strIndexer->position() + 1;
    while (!strIndexer->end()) {
        str* current = strIndexer->current();
        if (!current->isSpecial() && !current->isSpace()) {
            expression += current->value();
            strIndexer->next();
        } else {
            break;
        }
    }

    if (expression != "") {
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

ostream& operator<<(ostream& out, const Lexer& lexer) {
   for (auto token : lexer.tokens)
       out << *token;
   return out;
}

