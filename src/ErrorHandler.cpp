//
// Created by souls on 30/04/2020.
//

#include "../include/ErrorHandler.h"

ErrorHandler::ErrorHandler() {
}

ErrorHandler::~ErrorHandler() {
    for (auto error : errors)
        delete error;
}

bool ErrorHandler::empty() {
    return errors.empty();
}

void ErrorHandler::add(Error *error) {
    errors.push_back(error);
}

void ErrorHandler::display() {
    for (auto error : errors) {
        cerr << "At " << error->getLine() << ":" << error->getColon()
             << " " << error->getMsg() << endl;
    }
}
