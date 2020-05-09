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
    if (isdigit(key[i]) && isdigit(key[key.length() - 1]))
        ++i;
    else
        return false;

    while (i < key.length() && (isdigit(key[i]) || key[i] == '.'))
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
    string::size_type i = 0;
    while (i < key.length()) {
        vector<char>::const_iterator it = find(specials.begin(), specials.end(), key[i]);
        if (it == specials.end()) {
            return false;
        }
        ++i;
    }
    return key.length() == i;
}

inline bool str::isExpression() const {
    string::size_type start = 0;
    string::size_type end = key.size() - 1;
    return key[start] == '\"' && key[end] == '\"';
}

inline bool str::isAlphaNumUnd() const {
    string::size_type i = 0;
    while (i < key.length() && (isalnum(key[i]) || key[i] == '_'))
        ++i;
    return key.length() == i;
}


inline void str::initType() {
    if      (isSpace())          type_ = SPACE;
    else if (isAlphaNumUnd())    type_ = ALPHANUMERIC_OR_UNDERSCORE;
    else if (isSpecial())        type_ = SPECIAL;
    else                         type_ = UNDEFINED;
}


