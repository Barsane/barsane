//
// Created by souls on 30/04/2020.
//

#include "../include/ErrorHandler.h"

ErrorHandler::ErrorHandler() {
}

ErrorHandler::~ErrorHandler() {

}

bool ErrorHandler::empty() {
    return false;
}

void ErrorHandler::add(Error *error) {
}

vector<Error *> ErrorHandler::getErrors() {
    Error* error = new Error(UNEXPECTED_ERROR, "Not implement yet", 1, 1);
    vector<Error *> rst = {error};
    return rst;
}
