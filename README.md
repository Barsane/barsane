# BARZANE

## Running test on Linux

From the root project, run the following commands:

```shell script
$ cd test
$ make
$ ../bin/run_test
12 token type Should be VALUE
        SymbolTest.cpp:12: void SymbolTest::symbolIsValue_When_TokenIs(): Assertion `symbolTwelve.isValue()` failed 
true token type should be VALUE
        SymbolTest.cpp:19: void SymbolTest::symbolIsValue_When_TokenIs(): Assertion `symbolBoolTrue.isValue()` failed 

Failed: 77      Success: 24

```
