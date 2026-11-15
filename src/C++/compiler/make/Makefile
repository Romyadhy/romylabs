CXX = g++
CXXFLAGS = -Wall -Wextra -g -std=c++20
TARGET = app
SRC = main.cpp
all:$(TARGET)
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)
clean:
	rm -f $(TARGET)
.PHONY: all clean
