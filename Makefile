CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRCS = main.cpp GameOfLife.cpp Grid.cpp Cell.cpp GameOfLifeGUI.cpp
OBJS = $(SRCS:.cpp=.o)

all: GameOfLife

GameOfLife: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f GameOfLife $(OBJS)
