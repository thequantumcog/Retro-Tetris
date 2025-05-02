# Compiler and flags
CC       := g++
CFLAGS   := -Wall

# Strict flags (AddressSanitizer + all warnings)
STRICT_CFLAGS := -Wall -fsanitize=address
LDFLAGS       :=

# Raylib libraries and options
RAYLIB_FLAGS := -lraylib

# Paths and files
SRC_DIR := src
OBJ_DIR := obj
TARGET  := tetris

# Find all .cpp files in the src directory and corresponding .o files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Default rule
all: $(TARGET)

# Strict build: add sanitizer to both compile- and link-flags
strict: CFLAGS   += $(STRICT_CFLAGS)
strict: LDFLAGS  += $(STRICT_CFLAGS)
strict: $(TARGET)

# Link the final binary
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(RAYLIB_FLAGS)

# Compile .cpp files into .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

# Ensure the obj directory exists
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean up compiled files
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all strict clean
