# Compilateur et options
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Liste des fichiers sources principaux
SRCS = main.cpp Grille.cpp Cellule.cpp JeuDeLaVieStrategie.cpp AffichageConsole.cpp AffichageGraphique.cpp ControllerJeuDeLaVie.cpp

# Liste des fichiers sources pour les tests
TEST_SRCS = test.cpp Grille.cpp Cellule.cpp JeuDeLaVieStrategie.cpp

# Objets correspondants
OBJS = $(SRCS:.cpp=.o)
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

# Nom des exécutables
TARGET = JeuDeLaVie
TEST_TARGET = test_executable

# Bibliothèques pour SFML
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

all: $(TARGET) $(TEST_TARGET)

# Compilation du programme principal
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# Compilation des tests unitaires
$(TEST_TARGET): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Règle générique pour compiler les fichiers .cpp en .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage
clean:
	rm -f *.o $(TARGET) $(TEST_TARGET)

# Exécution des tests
run_tests: $(TEST_TARGET)
	./$(TEST_TARGET)

.PHONY: all clean run_tests
