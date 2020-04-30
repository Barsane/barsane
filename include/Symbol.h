//
// Created by souls on 29/04/2020.
//

#ifndef BARZANE_SYMBOL_H
#define BARZANE_SYMBOL_H

#include <string>

using namespace std;


/**
 * The possible values for a given symbol.
 */
enum SymbolType {
    VALUE,
    ID,
    DOUBLE_QUOTATION,
    TYPE,
    COMA,
    COLON,
    SEMI_COLON,
    LEFT_BRACKET,
    RIGHT_BRACKET,
    TERM_OPERATOR,
    OPERATION_OPERATOR,
    ASSIGNMENT,
    PRINT,

    UNKNOWN
};

/**
 * Tokenize a string. It is the smallest unit that allow to feature
 * the kind of symbol, the starting indices with these members:
 *
 *      the token given while instantiating a new symbol
 *      the token type @see SymbolType
 *      the line number given while instantiating a new symbol
 *      the colon number given wile instantiating a new symbol.
 *
 * @warning An exception is throw if an instruction tries to create
 *          a object with line less than 1 as same as colon.
 */
class Symbol {

    /**
     * A representative object of Symbol class.
     * @param out: a stream object.
     * @param symbol: A symbol to represent.
     * @return Get the given stream after push the representation string.
     */
    friend ostream& operator<<(ostream& out, const Symbol& symbol);

    public:
        /**
         * Constructor
         *
         * @param token: the string whose should be tokenize.
         * @param line: the line number.
         * @param colon: the colon number.
         */
        Symbol(string& token, const unsigned int line, const unsigned int colon);

        /**
         * Destructor
         */
        ~Symbol();

        /**
         * Check if the object symbol is type of VALUE (@see SymbolType).
         *
         * @return true if the object symbol is type of VALUE
         *         otherwise false.
         */
        bool isValue() const;

        /**
         * Check if the object symbol is type of ID (@see SymbolType).
         *
         * @return true if the object symbol is type of ID
         *         otherwise false.
         */
        bool isId() const;

        /**
         * Check if the object symbol is type of DOUBLE_QUOTATION (@see SymbolType).
         *
         * @return true if the object symbol is type of DOUBLE_QUOTATION
         *         otherwise false.
         */
        bool isDoubleQuotation() const;

        /**
         * Check if the object symbol is type of TYPE (@see SymbolType).
         *
         * @return true if the object symbol is type of TYPE
         *         otherwise false.
         */
        bool isType() const;

        /**
         * Check if the object symbol is type of COMA (@see SymbolType).
         *
         * @return true if the object symbol is type of COMA
         *         otherwise false.
         */
        bool isComa() const;

        /**
         * Check if the object symbol is type of COLON (@see SymbolType).
         *
         * @return true if the object symbol is type of COLON
         *         otherwise false.
         */
        bool isColon() const;

        /**
         * Check if the object symbol is type of SEMI_COLON (@see SymbolType).
         *
         * @return true if the object symbol is type of SEMI_COLON
         *         otherwise false.
         */
        bool isSemiColon() const;

        /**
         * Check if the object symbol is type of MINUS (@see SymbolType).
         *
         * @return true if the object symbol is type of MINUS
         *         otherwise false.
         */
        bool isMinus() const;

        /**
         * Check if the object symbol is type of LEFT_BRACKET (@see SymbolType).
         *
         * @return true if the object symbol is type of LEFT_BRACKET
         *         otherwise false.
         */
        bool isLeftBracket() const;

        /**
         * Check if the object symbol is type of RIGHT_BRACKET (@see SymbolType).
         *
         * @return true if the object symbol is type of RIGHT_BRACKET
         *         otherwise false.
         */
        bool isRightBracket() const;

        /**
         * Check if the object symbol is type of TERM_OPERATOR (@see SymbolType).
         * A term operator symbol is either `*` or `/` token value.
         *
         * @return true if the object symbol is type of TERM_OPERATOR
         *         otherwise false.
         */
        bool isTermOperator() const;

        /**
         * Check if the object symbol is type of OPERATION_OPERATOR (@see SymbolType).
         * A operation operator symbol is either `+` or `-` token value.
         *
         * @return true if the object symbol is type of OPERATION_OPERATOR
         *         otherwise false.
         */
        bool isOperationOperator() const;

        /**
         * Check if the object symbol is type of ASSIGNMENT (@see SymbolType).
         *
         * @return true if the object symbol is type of ASSIGNMENT
         *         otherwise false.
         */
        bool isAssignment() const;

        /**
         * Check if the object symbol is type of PRINT (@see SymbolType).
         *
         * @return true if the object symbol is type of PRINT
         *         otherwise false.
         */
        bool isPrint() const;

        /**
         * Identify token type among @enum SymbolType.
         *
         * @param token: token value.
         * @return the type of the given token value.
         */
        static SymbolType typeOf(const string& token);

        /**
         * Represent a symbol type in order to get pretty print.
         *
         * @param type
         * @return a string of the given type.
         */
        static string stringOf(const SymbolType type);

        /**
         * Get token value.
         *
         * @return the token value that is string.
         */
        string& getToken() const;

        /**
         * Get line number.
         * @return the line number that is an unsigned integer.
         */
        unsigned int getLine() const;

        /**
         * Get colon number.
         * @return the colon number that is an unsigned integer.
         */
        unsigned int getColon() const;

        /**
         * Get the token type.
         * @return the token type that is a @enum SymbolType.
         */
        SymbolType getType() const;

private:
        string& token;
        unsigned int line;
        unsigned int colon;
        SymbolType type;
};


#endif //BARZANE_SYMBOL_H
