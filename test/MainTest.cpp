//
// Created by souls on 29/04/2020.
//

#include "expect.h"

int main() {
    expect("Should be OK",  1 == 1);
    expect("Should be OK", "Hello" == "Hello");
    expect("Should be not OK", "!=&" == "x");
    return 0;
}