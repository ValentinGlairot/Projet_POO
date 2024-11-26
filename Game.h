#ifndef GAME_H
#define GAME_H

#include "Grid.h"
#include <string>

class Game {
private:
    Grid* grid;
    int maxIterations;
    bool isStable(const Grid& previous, const Grid& current);

public:
    Game(const std::string& filePath, int maxIterations);
    ~Game();
    void runConsoleMode();
    void runGraphicMode();
};

#endif
