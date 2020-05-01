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

void ErrorHandlerTest::run() {
    verifyEmpty_WhenAdd();
    verifyEmpty_When_Initiate();
}