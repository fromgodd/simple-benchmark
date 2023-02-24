CXX = clang++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic

SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = cpu_benchmark

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) $(EXEC)
