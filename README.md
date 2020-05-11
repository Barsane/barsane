# BARZANE

## Running test on Linux

From the root project, run the following commands:

```shell script
$ cd test
$ make
12 token type Should be VALUE
        SymbolTest.cpp:12: void SymbolTest::symbolIsValue_When_TokenIs(): Assertion `symbolTwelve.isValue()` failed 
true token type should be VALUE
        SymbolTest.cpp:19: void SymbolTest::symbolIsValue_When_TokenIs(): Assertion `symbolBoolTrue.isValue()` failed 

Failed: 77      Success: 24

```

## Checking memory state

- Install valgrind with: `sudo apt install valgrind` or `sudo yum install valgrind`
`valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt /bin/testbarzane`

## Extra option for GNU Compiler:

- `-Wall -Werror -Weffc++ -g3 -gdwarf-2 -DDEBUG`
