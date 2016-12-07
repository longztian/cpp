.DEFAULT_GOAL := app
.PHONY: lint check

SHELL := /bin/bash

# locate the include folder
INCLUDE := $(shell INC=./include; while [[ ! -d $$INC ]] && [[ $$(realpath $$INC) != "/include" ]]; do INC=../$$INC; done; realpath -e $$INC 2>/dev/null)
ifeq ($(INCLUDE),"")
$(error No include path found!)
endif

CXX := g++
#CXX := clang++
CXXFLAGS := -g -fPIC -std=c++1z -I$(INCLUDE)

SRC_LIB := $(shell find . -name "*.cpp" ! -name "main.cpp" ! -name "*.test.cpp")
OBJ_LIB := $(patsubst %.cpp, %.o, $(SRC_LIB))

SRC_TEST := $(shell find . -name "*.test.cpp")
OBJ_TEST := $(patsubst %.cpp, %.o, $(SRC_TEST))

DEP := .dep
$(shell mkdir -p $(DEP) >/dev/null)
# pull in dependency info for *existing* .o files
-include $(addprefix $(DEP)/,$(notdir $(SRC:.o=.d)))

# compile and generate dependency info
%.o: %.cpp
	$(CXX) -c  $(CXXFLAGS) -o $*.o $*.cpp
	$(CXX) -MM $(CXXFLAGS) $*.cpp > $(addprefix $(DEP)/,$(notdir $*.d))

lint:
	cpplint --quiet --recursive .

check:
	cppcheck --quiet --enable=warning,style,performance,portability,unusedFunction --std=c++11 .

TEST := /tmp/test
$(TEST):
	@echo '#define CATCH_CONFIG_MAIN' > $(TEST).cpp
	@echo '#include "catch.hpp"' >> $(TEST).cpp
	$(CXX) -c $(CXXFLAGS) -o $(TEST).o $(TEST).cpp

test: $(OBJ_LIB) $(OBJ_TEST) $(TEST)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(TEST) $(OBJ_LIB) $(OBJ_TEST) $(TEST).o

app: $(OBJ_LIB) main.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJ_LIB) main.o

clean:
	rm -rf $(DEP) $(OBJ_LIB) $(OBJ_TEST) $(TEST) $(TEST).* main.o a.out
