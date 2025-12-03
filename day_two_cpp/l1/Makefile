# filepath: /home/kmos/coding/AOC2025/day_two_cpp/l1/Makefile
# Makefile for a single-file C++ project (main.cpp)

CXX := g++
CXXFLAGS := -std=c++20 -O2 -Wall -Wextra -Wpedantic -g
LDFLAGS :=

TARGET := main
SRC := main.cpp
OBJ := $(SRC:.cpp=.o)

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJ)
