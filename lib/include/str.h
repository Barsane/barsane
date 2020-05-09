//
// Created by souls on 02/05/2020.
//

#ifndef BARZANE_STR_H
#define BARZANE_STR_H

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * The possible values for a given symbol.
 */
enum StrType {
    SPACE,
    ALPHANUMERIC_OR_UNDERSCORE,
    SPECIAL,

    UNDEFINED
};

/**
 * A class utility to allow to make an operation like if a string
 * is a sequence space, alphabetic numeric, special and other more.
 * It also suggests a type (@see StrType) that facilitate multiple cases
 * of an instantiated object.
 */
class str {

    /**
     * Define the different special character accepted by Barzane grammar.
     */
    const vector<char> specials = {
            '+', '-', '*', '/', '<', '>', '=',
            '!', ':', ';', ',', '"', '(', ')',
            '%',
    };

    public:
        /**
         * Constructor
         *
         * @param chr: a pointer character(s) to cast.
         */
        str(char* chr): key(chr) { initType(); };

        /**
         * Constructor
         *
         * @param chr: a constant of pointer character(s) to cast.
         */
        str(const char* chr): key(chr) { initType(); };

        /**
         * Constructor
         *
         * @param chr: a character cast.
         */
        str(char chr): key(1, chr) { initType(); };

        /**
         * Constructor
         *
         * @param chr: a string to cast.
         */
        str(string chr): key(chr) { initType(); };

        /**
         * Destructor
         */
        ~str() {};

        /**
         * Get type
         *
         * @return a type of sequence given to the constructor.
         */
        StrType getType() const;

        /**
         * Get value
         *
         * @return the sequence given to the constructor.
         */
        string value() const;

        /**
         * Check if the value of object json is a space sequence.
         *
         * @return true if the object json is a space sequence
         *         otherwise false.
         */
        bool isSpace() const;

        /**
         * Check if the value of object json is a numeric sequence.
         * Note that the character "." is considered numeric.
         *
         * @return true if the value of object json is a numeric sequence
         *         otherwise false.
         */
        bool isNumeric() const;

        /**
         * Check if the value of object json is an alphabetic and/or
         * underscore sequence.
         *
         * @return true if the value of object json is an alphabetic and/or
         * underscore sequence otherwise false.
         */
        bool isAlphaUnd() const;

        /**
         * Check if the value of object json is an alphanumeric and/or
         * underscore sequence.
         *
         * @return true if the value of object json is an alphanumeric and/or
         * sequence underscore otherwise false.
         */
        bool isAlphaNumUnd() const;

        /**
         * Check if the value of object json is a space sequence.
         *
         * @return true if the value of object json is a space otherwise false.
         */
        bool isSpecial() const;

        /**
         * Check if the value of object json start and end with double quote character.
         *
         * @return true  the value of object json start and end with double character
         * otherwise false.
         */
        bool isExpression() const;

    private:
        string key;
        StrType type_;

        void initType();

};


#include "str.hxx"

#endif //BARZANE_STR_H
