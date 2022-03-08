BIN_DIR = exe
SRC_DIR = src
LIB_DIR = lib
CXX = g++
CPP_FLAGS = -g -Wall -I$(LIB_DIR) -std=c++11

all: $(BIN_DIR)/.dirstamp $(BIN_DIR)/pokemon

$(BIN_DIR)/pokemon: $(SRC_DIR)/main.cpp $(BIN_DIR)/attackMove.o $(BIN_DIR)/battle.o $(BIN_DIR)/pokemon.o
	$(CXX) $(CPP_FLAGS) $^ -o $@

$(BIN_DIR)/attackMove.o: $(SRC_DIR)/attackMove.cpp 
	$(CXX) $(CPP_FLAGS) -c $^ -o $@

$(BIN_DIR)/battle.o: $(SRC_DIR)/battle.cpp 
	$(CXX) $(CPP_FLAGS) -c $^ -o $@

$(BIN_DIR)/pokemon.o: $(SRC_DIR)/pokemon.cpp 
	$(CXX) $(CPP_FLAGS) -c $^ -o $@

$(BIN_DIR)/.dirstamp:
	mkdir -p $(BIN_DIR)
	touch $(BIN_DIR)/.dirstamp

.PHONY: clean
clean: 
	rm -rf $(BIN_DIR)
