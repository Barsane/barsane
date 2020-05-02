//
// Created by souls on 02/05/2020.
//

#ifndef BARZANE_STR_H
#define BARZANE_STR_H

#include <string>
#include <ostream>

using namespace std;

enum StrType {
    SPACE,
    ALPHANUMERIC_OR_UNDERSCORE,
    SPECIAL,

    UNDEFINED
};

class str {

    public:
        str(char* chr): key(chr) {};
        str(const char* chr): key(chr) {};
        str(char chr): key(1, chr) {};
        str(string chr): key(chr) {};
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

        StrType initType() const;

};

#include "str.hxx"

#endif //BARZANE_STR_H
