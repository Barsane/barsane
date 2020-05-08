include Makefile.settings

CC = g++ -std=c++1z
LDFLAGS = -shared -fPIC
BIN_DIR = bin
DEP_DIR = .dep
PROJECT_NAME = barzane
VERSION = 0.1

ROOT_DIR = .
LIB_DIR = lib
TEST_DIR = test

## Define target
ROOT_TARGET = $(BIN_DIR)/$(PROJECT_NAME)
LIB_TARGET = $(BIN_DIR)/lib$(PROJECT_NAME).so
LIB_INC = $(BIN_DIR)/$(PROJECT_NAME)/include
TEST_TARGET = $(BIN_DIR)/test$(PROJECT_NAME)

## Define Source
ROOT_SRC = $(ROOT_DIR)/barzane.cpp
LIB_SRC = $(shell find $(LIB_DIR)/src -name "*.cpp")
TEST_SRC = $(shell find $(TEST_DIR)/src -name "*.cpp")

## Define obj
ROOT_OBJ=$(BIN_DIR)/barzane.o
LIB_OBJ=$(LIB_SRC:$(LIB_DIR)/src/%cpp=$(BIN_DIR)/$(LIB_DIR)/%o)
TEST_OBJ=$(TEST_SRC:$(TEST_DIR)/src/%cpp=$(BIN_DIR)/$(TEST_DIR)/%o)

## Define dep
LIB_DEP=$(LIB_SRC:$(LIB_DIR)/src/%cpp=$(DEP_DIR)/$(LIB_DIR)/%d)
TEST_DEP=$(TEST_SRC:$(TEST_DIR)/src/%cpp=$(DEP_DIR)/$(TEST_DIR)/%d)

## Lib option
LIBFLAGS = -l$(PROJECT_NAME) -L$(BIN_DIR) -Wl,-rpath,$(BIN_DIR)

all: clean build run-test run

## Target library Rule
$(LIB_TARGET): $(LIB_OBJ)
	@echo "Linking the target $@ ..."
	@$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
	@echo -- Link finished --

## Compilation library Rule
$(BIN_DIR)/$(LIB_DIR)/%.o : $(LIB_DIR)/src/%.cpp
	@mkdir -p $(dir $@)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@

## Dependency library Rule
$(DEP_DIR)/$(LIB_DIR)/%.d : $(LIB_DIR)/src/%.cpp
	@mkdir -p $(dir $@)
	@echo "Building dependencies file for $*.o"
	@$(SHELL) -ec '$(CC) -M $(CFLAGS) $< | sed "s^$*.o^$(BIN_DIR)/$*.o^" > $@'

## Target test Rule
$(TEST_TARGET): $(TEST_OBJ)
	@echo "Linking the target $@ ..."
	@$(CC) $(CFLAGS) -I$(LIB_DIR)/include -o $@ $^ $(LIBFLAGS)
	@echo -- Link finished --

## Compilation test Rule
$(BIN_DIR)/$(TEST_DIR)/%.o : $(TEST_DIR)/src/%.cpp
	@mkdir -p $(dir $@)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -I$(LIB_DIR)/include -c $< -o $@

## Dependency test Rule
$(DEP_DIR)/$(TEST_DIR)/%.d : $(TEST_DIR)/src/%.cpp
	@mkdir -p $(dir $@)
	@echo "Building dependencies file for $*.o"
	@$(SHELL) -ec '$(CC) -M $(CFLAGS) -I$(LIB_DIR)/include -L$(LIB_TARGET) $< | sed "s^$*.o^$(BIN_DIR)/$*.o^" > $@'

## Target main rule
$(ROOT_TARGET): $(ROOT_OBJ)
	@echo "Linking the target $@ ..."
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFLAGS)
	@echo -- Link finished --


## Compilation main rule
$(ROOT_OBJ) : $(ROOT_SRC)
	@mkdir -p $(dir $@)
	@echo "Compiling $<"
	@echo $(CC) $(CFLAGS) -I$(LIB_DIR)/include -c $< -o $@
	@$(CC) $(CFLAGS) -I$(LIB_DIR)/include -c $< -o $@

build: build-lib build-test build-main

build%lib:
	${INFO} "Building library dependencies ..."
	@$(MAKE) $(LIB_DEP)
	${INFO} "Build compelte"
	${INFO} "Building library ..."
	@$(MAKE) $(LIB_TARGET)
	${INFO} "Build complete"

build%test:
	${INFO} "Building test dependencies ..."
	@$(MAKE) $(TEST_DEP)
	${INFO} "Build complete"
	${INFO} "Building test ..."
	@$(MAKE) $(TEST_TARGET)
	${INFO} "Build complete"

build%main:
	${INFO} "Building main ..."
	@$(MAKE) $(ROOT_TARGET)
	${INFO} "Build complete"

clean: clean-lib clean-test clean-main

clean%lib:
	@-rm -f $(LIB_TARGET) $(LIB_OBJ) $(LIB_DEP)

clean%test:
	@-rm -f $(TEST_TARGET) $(TEST_OBJ) $(TEST_DEP)

clean%main:
	@-rm -f $(ROOT_TARGET) $(ROOT_OBJ)


run:
	$(ROOT_TARGET)

run-test:
	$(TEST_TARGET)

test: run-test

#.SILENT:

.PHONY: clean build run-test run

## IMPORTANT - ensures arguments are not interpreted as make targets
%:
	@:
