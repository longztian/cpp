.DEFAULT_GOAL := build
.PHONY: lint

SHELL := /bin/bash

# locate the include folder
INCLUDE := $(shell INC=./include; while [[ ! -d $$INC ]] && [[ $$(realpath $$INC) != "/include" ]]; do INC=../$$INC; done; realpath -e $$INC 2>/dev/null)
ifeq ($(INCLUDE),"")
$(error No include path found!)
endif

CXX := g++
#CXX := clang++
CXXFLAGS := -g -fPIC -std=c++1z -I$(INCLUDE)

SRC := $(shell find . -name "*.cpp")
OBJ := $(patsubst %.cpp, %.o, $(SRC))

DEP := .dep
$(shell mkdir -p $(DEP) >/dev/null)
# pull in dependency info for *existing* .o files
-include $(addprefix $(DEP)/,$(notdir $(SRC:.o=.d)))

# compile and generate dependency info
%.o: %.cpp
	$(CXX) -c  $(CXXFLAGS) -o $*.o $*.cpp
	$(CXX) -MM $(CXXFLAGS) $*.cpp > $(addprefix $(DEP)/,$(notdir $*.d))

lint:
	cpplint --quiet --recursive . && \
	cppcheck --quiet --enable=warning,style,performance,portability,unusedFunction --std=c++11 .

TEST := /tmp/test
$(TEST):
	@echo '#define CATCH_CONFIG_MAIN' > $(TEST).cpp
	@echo '#include "catch.hpp"' >> $(TEST).cpp
	$(CXX) -c $(CXXFLAGS) -o $(TEST).o $(TEST).cpp

build: $(OBJ) $(TEST)
#	$(CXX) -shared $(CXXFLAGS) $(LDFLAGS) -o libTest.so $(OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(TEST) $(OBJ) $(TEST).o

test:
	$(TEST)

clean:
	rm -rf $(TEST) $(OBJ) $(DEP) $(TEST).*
