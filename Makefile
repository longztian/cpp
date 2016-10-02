.DEFAULT_GOAL := build
.PHONY: lint

CXX := g++
CXXFLAGS := -std=c++11 -I./include

SRC_CTCL := $(shell find ./CtCI-6th-Edition-cpp -name "*.cpp")
OBJ_CTCL := $(patsubst %.cpp, %.o, $(SRC_CTCL))
EXE_CTCL := $(patsubst %.cpp, %, $(filter %/test.cpp, $(SRC_CTCL)))
#$(info $(EXE_CTCL))

CXX=g++

lint:
	cpplint --quiet --filter=-legal/copyright ${SRC_CTCL} && \
	cppcheck --quiet --enable=warning,style,performance,portability,unusedFunction --std=c++11 .

build: $(OBJ_CTCL)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(EXE_CTCL) $(OBJ_CTCL)

test:
	$(EXE_CTCL)

clean:
	rm -rf $(OBJ_CTCL) $(EXE_CTCL)
