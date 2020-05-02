//
// Created by souls on 02/05/2020.
//


inline StrType str::getType() const {
    return type_;
}

inline string str::value() const {
    return key;
}

inline bool str::isSpace() const {
    string::size_type i = 0;
    while (i < key.length() && isspace(key[i]))
        ++i;
    return key.length() == i;
}

inline bool str::isNumeric() const {
    string::size_type i = 0;
    if (isalpha(key[i]))
        ++i;
    else
        return false;

    while (i < key.length() && isdigit(key[i]))
        ++i;
    return key.length() == i;
}

inline bool str::isAlphaUnd() const {
    string::size_type i = 0;
    while (i < key.length() && (isalpha(key[i]) || key[i] == '_'))
        ++i;
    return key.length() == i;
}

inline bool str::isSpecial() const {
    return !isAlphaNumUnd() && !isSpace();
}

inline bool str::isExpression() const {
    string::size_type start = 0;
    string::size_type end = key.size() - 1;
    if (key[start] == '\"' && key[end] == '\"') {
        return true;
    }

    return false;
}

inline bool str::isAlphaNumUnd() const {
    string::size_type i = 0;
    while (i < key.length() && (isalnum(key[i]) || key[i] == '_'))
        ++i;
    return key.length() == i;
}


inline StrType str::initType() const {
    if (isSpace())          return SPACE;
    if (isAlphaNumUnd())    return ALPHANUMERIC_OR_UNDERSCORE;
    if (isSpecial())        return SPECIAL;

    return UNDEFINED;
}


