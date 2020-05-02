//
// Created by souls on 02/05/2020.
//

#ifndef BARZANE_STR_H
#define BARZANE_STR_H

#include <string>
#include <iostream>

using namespace std;

enum StrType {
    SPACE,
    ALPHANUMERIC_OR_UNDERSCORE,
    SPECIAL,

    UNDEFINED
};

class str {

    public:
        str(char* chr): key(chr) { initType(); };
        str(const char* chr): key(chr) { initType(); };
        str(char chr): key(1, chr) { initType(); };
        str(string chr): key(chr) { initType(); };
        ~str() {};

        StrType getType() const;
        string value() const;

        bool isSpace() const;
        bool isNumeric() const;
        bool isAlphaUnd() const;
        bool isAlphaNumUnd() const;
        bool isSpecial() const;
        bool isExpression() const;

    private:
        string key;
        StrType type_;

        void initType();

};

#include "str.hxx"

#endif //BARZANE_STR_H
