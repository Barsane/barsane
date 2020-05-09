//
// Created by souls on 30/04/2020.
//

#ifndef BARZANE_ERROR_H
#define BARZANE_ERROR_H

#include <string>

using namespace std;

/**
 * The possible values for a given error.
 */
enum ErrorType {
    UNEXPECTED_TOKEN,
    SYNTAX_ERROR,
    MISSING_TOKEN,

    UNEXPECTED_ERROR
};

/**
 * This data class defines what is an error in Barzane program.
 * It features by:
 *
 *      a type: can be lexical, syntactical, semantical or logical.
 *      a message: To specify exactly the error source.
 *      a line number.
 *      a colon number.
 */
class Error {

    public:
        /**
         * Constructor
         *
         * @param type: The type of error (@see ErrorType)
         * @param msg: The error source
         * @param line: The line number
         * @param colon: The colon number
         */
        Error(ErrorType type, const string msg,
              const unsigned int line, const unsigned int colon)
          : type(type), msg(msg), line(line), colon(colon) {}

        /**
         * Destructor
         */
        ~Error() {};

        /**
         * Get type
         *
         * @return the type of error
         */
        ErrorType getType() const { return type; };

        /**
         * Get message
         *
         * @return the error message.
         */
        const string& getMsg() const { return msg; };

        /**
         * Get line number
         *
         * @return the line number of the error
         */
        unsigned int getLine() const { return line; };

        /**
         * Get the colon number.
         *
         * @return the colon number of the error.
         */
        unsigned int getColon() const { return colon; };

    private:
        ErrorType type;
        string msg;
        unsigned int line;
        unsigned int colon;
};

#endif //BARZANE_ERROR_H
