//
// Created by souls on 29/04/2020.
//

#ifndef BARZANE_SYMBOL_H
#define BARZANE_SYMBOL_H

#include <string>

using namespace std;

enum SymbolType {
    VALUE,
    ID,
    DOUBLE_QUOTATION,
    TYPE,
    COMA,
    COLON,
    SEMI_COLON,
    MINUS,
    LEFT_BRACKET,
    RIGHT_BRACKET,
    TERM_OPERATOR,
    OPERATION_OPERATOR,
    ASSIGNMENT,
    PRINT
};

class Symbol {

    friend ostream& operator<<(ostream& out, const Symbol& symbol);

    public:
        Symbol(string& token, const unsigned int line, const unsigned int colon);
        ~Symbol();

        bool isValue() const;
        bool isId() const;
        bool isDoubleQuotation() const;
        bool isType() const;
        bool isComa() const;
        bool isColon() const;
        bool isSemiColon() const ;
        bool isMinus() const;
        bool isLeftBracket() const ;
        bool isRightBracket() const;
        bool isTermOperator() const;
        bool isOperationOperator() const;
        bool isAssignment() const;
        bool isPrint() const;

        static SymbolType typeOf(const string& token);
        static string stringOf(const SymbolType type);

        string &getToken() const;
        unsigned int getLine() const;
        unsigned int getColon() const;

private:
        string& token;
        unsigned int line;
        unsigned int colon;
};


#endif //BARZANE_SYMBOL_H
