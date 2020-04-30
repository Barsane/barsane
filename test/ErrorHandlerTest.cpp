//
// Created by souls on 30/04/2020.
//

#include "ErrorHandlerTest.h"

void ErrorHandlerTest::verifyEmpty_WhenAdd() {
    // Given
    ErrorHandler errorHandler = ErrorHandler();

    // When
    Error* error = new Error(UNEXPECTED_TOKEN, "Unexpected token", 1, 1);
    errorHandler.add(error);

    // Then
    expect("Error handler should not be empty", !errorHandler.empty());
}

void ErrorHandlerTest::verifyEmpty_When_Initiate() {
    // Given
    ErrorHandler errorHandler = ErrorHandler();

    // Then
    expect("Error handler should be empty", errorHandler.empty());
}

void ErrorHandlerTest::getErrors_When_Empty() {
    // Given
    ErrorHandler errorHandler = ErrorHandler();

    // Then
    expect("Error handler should be empty", errorHandler.getErrors().empty());
}

void ErrorHandlerTest::getErrors_WhenAdd() {
    // Given
    ErrorHandler errorHandler = ErrorHandler();

    // When
    Error* error = new Error(UNEXPECTED_TOKEN, "Unexpected token", 1, 1);
    errorHandler.add(error);

    // Then
    Error* found = errorHandler.getErrors().at(0);
    expect("Error handler should not be empty", !errorHandler.getErrors().empty());
    expect("Error handler have an UNEXPECTED_TOKEN error", found->getType() == UNEXPECTED_TOKEN);
}

void ErrorHandlerTest::run() {
    verifyEmpty_WhenAdd();
    verifyEmpty_When_Initiate();
    getErrors_When_Empty();
    getErrors_WhenAdd();
}