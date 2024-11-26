#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include "Grid.h"
#include <string>

class GameOfLife {
protected: // Changement ici
    Grid grid;
    int maxIterations;
    std::string inputFilePath;

public:
    GameOfLife(const std::string& inputFilePath, int maxIterations = 100);
    void runConsoleMode();
    void saveIteration(int iteration) const;
    void loadInitialState();
};

#endif // GAMEOFLIFE_H
