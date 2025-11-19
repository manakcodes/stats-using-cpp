
CXX = g++
CXXFLAGS = -std=c++17 -Iinclude -Wall -Wextra -O2


SRC_DIR = .
TEST_DIR = .
INCLUDE_DIR = include
BUILD_DIR = build


MAIN_SRC = $(SRC_DIR)/Main.cpp
TEST_SRC = $(TEST_DIR)/test.cpp
MAIN_BIN = main
TEST_BIN = test


all: $(MAIN_BIN)


$(MAIN_BIN): $(MAIN_SRC) $(INCLUDE_DIR)/*.hpp
	$(CXX) $(CXXFLAGS) $(MAIN_SRC) -o $(MAIN_BIN)


test: $(TEST_BIN)
	./$(TEST_BIN)

$(TEST_BIN): $(TEST_SRC) $(INCLUDE_DIR)/*.hpp
	$(CXX) $(CXXFLAGS) $(TEST_SRC) -o $(TEST_BIN)


clean:
	rm -f $(MAIN_BIN) $(TEST_BIN)
