# Compiler and flags
CXX = g++
CXXFLAGS = -c -I.\include  # Include the 'include' directory for headers


# External library
EXT_LIB = . -lglfw3 -lopengl32 -lgdi32 

# Source files
SRC = src\main.cpp include\glad.cpp

BUILD_DIR = .\build
# Object files
OBJ = $(BUILD_DIR)\main.o $(BUILD_DIR)\include\glad.o $(BUILD_DIR)\util\util.o

# Output file
OUT = $(BUILD_DIR)\app.exe



# Debug flags
DEBUG_FLAGS = -g  # Only used in debug build


# Targets
all: $(OUT) run

# Debug target (includes the -g flag)
debug: CXXFLAGS += $(DEBUG_FLAGS)
debug: $(OUT)

$(OUT): $(OBJ)
	$(CXX) $(OBJ) -o $(OUT) -L$(EXT_LIB)

# Rule to compile source files into object files
$(BUILD_DIR)\main.o: src\main.cpp
	-mkdir $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c src\main.cpp -o $(BUILD_DIR)\main.o

$(BUILD_DIR)\include\glad.o: include\glad.c
	-mkdir $(BUILD_DIR)\include
	$(CXX) $(CXXFLAGS) -c include\glad.c -o $(BUILD_DIR)\include\glad.o

$(BUILD_DIR)\util\util.o: src\util\util.cpp
	-mkdir $(BUILD_DIR)\util
	$(CXX) $(CXXFLAGS) -c src\util\util.cpp -o $(BUILD_DIR)\util\util.o

run:
	$(OUT)

clean:
	rmdir /s /q .\build
