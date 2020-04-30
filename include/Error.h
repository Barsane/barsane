//
// Created by souls on 30/04/2020.
//

#ifndef BARZANE_ERROR_H
#define BARZANE_ERROR_H

#include <string>

using namespace std;

enum ErrorType {
    UNEXPECTED_TOKEN,

    UNKNOWN
};

class Error {

    public:
        Error(ErrorType type, const string msg,
              const unsigned int line, const unsigned int colon)
          : type(type), msg(msg), line(line), colon(colon) {}
        ~Error() {};

        ErrorType getType() const { return type; };
        const string &getMsg() const { return msg; };
        unsigned int getLine() const { return line; };
        unsigned int getColon() const { return colon; };

    private:
        ErrorType type;
        string msg;
        unsigned int line;
        unsigned int colon;
};

#endif //BARZANE_ERROR_H
