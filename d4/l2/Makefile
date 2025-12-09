CXX := g++
CXXFLAGS := -std=c++20 -O2 -Wall -Wextra
SRC := main.cpp
BIN := main
OBJ := $(SRC:.cpp=.o)

.PHONY: all run clean

all: $(BIN)

$(BIN): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

run: all
	./$(BIN)

clean:
	rm -f $(BIN) $(OBJ)

