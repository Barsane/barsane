//
// Created by souls on 30/04/2020.
//

#ifndef BARZANE_ERRORHANDLER_H
#define BARZANE_ERRORHANDLER_H

#include <vector>
#include "Error.h"

class ErrorHandler {

    public:
        ErrorHandler();
        ~ErrorHandler();

        bool empty();
        void add(Error* error);
        vector<Error*> getErrors();

    private:
        vector<Error*> errors;

};


#endif //BARZANE_ERRORHANDLER_H
