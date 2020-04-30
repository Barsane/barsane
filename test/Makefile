CC=g++
SRC_DIR=../src
BIN_DIR=../bin
TARGET=$(BIN_DIR)/run_test

SOURCE_TEST = SymbolTest.cpp IndexerTest.cpp ErrorHandlerTest.cpp
SOURCE = MainTest.cpp $(SOURCE_TEST) $(SRC_DIR)/Symbol.cpp

## End sources definition
INCLUDE = -I.$(SRC_DIR)/../include .
## end more includes

VPATH=$(SRC_DIR)
OBJ=$(join $(addsuffix $(BIN_DIR)/, $(dir $(SOURCE))), $(notdir $(SOURCE:.cpp=.o)))

## Fix dependency destination to be ../.dep relative to the src dir
DEPENDS=$(join $(addsuffix ../.dep/, $(dir $(SOURCE))), $(notdir $(SOURCE:.cpp=.d)))

## Default rule executed
all: $(TARGET)
	@true

## Clean Rule
clean:
	@-rm -f $(TARGET) $(OBJ) $(DEPENDS)


## Rule for making the actual target
$(TARGET): $(OBJ)
	@echo "============="
	@echo "Linking the target $@"
	@echo "============="
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBS)
	@echo -- Link finished --

## Generic compilation rule
%.o : %.cpp
	@mkdir -p $(dir $@)
	@echo "============="
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@


## Rules for object files from cpp files
## Object file for each file is put in obj directory
## one level up from the actual source directory.
$(BIN_DIR)/%.o : %.cpp
	@mkdir -p $(dir $@)
	@echo "============="
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

# Rule for "other directory"  You will need one per "other" dir
$(SRC_DIR)/$(BIN_DIR)/%.o : %.cpp
	@mkdir -p $(dir $@)
	@echo "============="
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

## Make dependancy rules
../.dep/%.d: %.cpp
	@mkdir -p $(dir $@)
	@echo "============="
	@echo Building dependencies file for $*.o
	@$(SHELL) -ec '$(CC) -M $(CFLAGS) $< | sed "s^$*.o^$(BIN_DIR)/$*.o^" > $@'

## Dependency rule for "other" directory
$(SRC_DIR)/../.dep/%.d: %.cpp
	@mkdir -p $(dir $@)
	@echo "============="
	@echo Building dependencies file for $*.o
	@$(SHELL) -ec '$(CC) -M $(CFLAGS) $< | sed "s^$*.o^$(SRC_DIR)/$(BIN_DIR)/$*.o^" > $@'

## Include the dependency files
-include $(DEPENDS)