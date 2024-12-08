CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Listez ici tous vos fichiers sources
SRCS = main.cpp \
       Grille.cpp \
       Cellule.cpp \
       JeuDeLaVieStrategie.cpp \
       AffichageConsole.cpp \
       AffichageGraphique.cpp \
       ControllerJeuDeLaVie.cpp

# Génère la liste des objets correspondants
OBJS = $(SRCS:.cpp=.o)

# Nom de l'exécutable final
TARGET = JeuDeLaVie

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ -lsfml-graphics -lsfml-window -lsfml-system

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)
