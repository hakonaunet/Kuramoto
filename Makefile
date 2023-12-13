# Compiler and Flags
CXX = g++
CXXFLAGS = -std=c++20 -Wall -I/usr/include/python3.11 \
           -I/usr/local/include -I./imgui -I./imgui-sfml \
           -Iinclude -I/home/haakolau/.local/lib/python3.11/site-packages/pybind11/include
# Directories
SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include

# Libraries
SFML = -lsfml-graphics -lsfml-window -lsfml-system
OPENGL_LIBS = -lGL
PYTHON_LIB = -L/usr/lib/python3.11/config-3.11-x86_64-linux-gnu -lpython3.11
LIBS = -L/usr/local/lib $(SFML) $(OPENGL_LIBS) $(PYTHON_LIB)

# All cpp and corresponding obj files
IMGUI_SRC = $(wildcard ./imgui/*.cpp) $(wildcard ./imgui-sfml/*.cpp)
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o) $(IMGUI_SRC:%.cpp=%.o)

# Executable Name
EXEC = Kuramoto

# Rules
all: $(OBJ)
	$(CXX) $(OBJ) $(LIBS) -o $(EXEC)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	-rm -f $(OBJ_DIR)/*.o $(EXEC) *.o