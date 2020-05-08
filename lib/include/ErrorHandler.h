//
// Created by souls on 30/04/2020.
//

#ifndef BARZANE_ERRORHANDLER_H
#define BARZANE_ERRORHANDLER_H

#include <vector>
#include <iostream>
#include "Error.h"

using namespace std;

/**
 *
 * This class only handles compile time errors that prevents
 * the Barzane program from successfully compiling.
 * In other words, it offers to the different bricks of the compiler
 * to reporting an error by adding it, to checking if it has an error
 * and displaying the errors set eventually.
 *
 * @see Error.h to get more information how an error is defined.
 */
class ErrorHandler {

    public:
        /**
         * Constructor
         */
        ErrorHandler();

        /**
         * Destructor
         */
        ~ErrorHandler();

        /**
         * Verify if error handler has at least an error.
         *
         * @return true if there is no error otherwise false.
         */
        bool empty();

        /**
         * Add a new error to the Error Handler.
         *
         * @param error: An error of Error type
         */
        void add(Error* error);

        /**
         * Display a set of errors stored. Note nothing is displayed
         * if there is no error.
         */
        void display();

    private:
        vector<Error*> errors;

};


#endif //BARZANE_ERRORHANDLER_H
