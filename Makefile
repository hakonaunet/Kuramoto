# Compiler and Flags
CXX = g++
CXXFLAGS = -std=c++20 -Wall

# Directories
SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = lib
INCLUDE_DIR = include

# Libraries
SFML = -lsfml-graphics -lsfml-window -lsfml-system
LIBS = $(SFML)

# All cpp and corresponding obj files
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Executable Name
EXEC = Kuramoto

# Rules
all: $(OBJ)
	$(CXX) $^ $(LIBS) -o $(EXEC)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm $(OBJ_DIR)/*.o $(EXEC)