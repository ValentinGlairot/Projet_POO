# Nom de l'exécutable
TARGET = game_of_life

# Options du compilateur
CXX = g++
CXXFLAGS = -std=c++17 -Wall -I./

# Dossiers
SRC_DIR = .
BUILD_DIR = build
BIN_DIR = bin

# Fichiers sources et objets
SOURCES = $(SRC_DIR)/main.cpp $(SRC_DIR)/Grid.cpp $(SRC_DIR)/Cell.cpp
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))

# Bibliothèques SFML
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Règles
all: $(BIN_DIR)/$(TARGET)

$(BIN_DIR)/$(TARGET): $(OBJECTS)
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(SFML_LIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

run: all
	$(BIN_DIR)/$(TARGET)
