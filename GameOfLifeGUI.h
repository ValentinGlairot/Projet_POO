#ifndef GAMEOFLIFEGUI_H
#define GAMEOFLIFEGUI_H

#include "GameOfLife.h"
#include <SFML/Graphics.hpp>

class GameOfLifeGUI : public GameOfLife {
private:
    sf::RenderWindow window;
    int cellSize;
    int windowWidth;
    int windowHeight;
    float iterationDelay; // en secondes

public:
    GameOfLifeGUI(const std::string& inputFilePath, int maxIterations = 100, int cellSize = 10, float iterationDelay = 0.1f);
    void runGraphicMode();
    void renderGrid();
};

#endif // GAMEOFLIFEGUI_H
