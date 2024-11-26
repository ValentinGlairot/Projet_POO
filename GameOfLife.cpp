#include "GameOfLife.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <filesystem>

GameOfLife::GameOfLife(const std::string& inputFilePath, int maxIterations)
    : inputFilePath(inputFilePath), maxIterations(maxIterations), grid(0, 0) {}

void GameOfLife::loadInitialState() {
    std::ifstream file(inputFilePath);
    if (!file) {
        std::cerr << "Erreur lors de l'ouverture du fichier : " << inputFilePath << std::endl;
        exit(1);
    }

    int height, width;
    file >> height >> width;
    grid = Grid(width, height);

    std::vector<std::vector<bool>> initialState(height, std::vector<bool>(width, false));
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int state;
            file >> state;
            initialState[y][x] = (state == 1);
        }
    }
    grid.initialize(initialState);
}

void GameOfLife::runConsoleMode() {
    loadInitialState();
    Grid previousGrid = grid;

    for (int iteration = 0; iteration < maxIterations; ++iteration) {
        std::cout << "Itération : " << iteration << std::endl;
        grid.display();
        saveIteration(iteration);

        grid.update();

        if (grid.isStable(previousGrid)) {
            std::cout << "La grille est stable. Fin de la simulation." << std::endl;
            break;
        }

        previousGrid = grid;
    }
}

void GameOfLife::saveIteration(int iteration) const {
    std::filesystem::create_directory(inputFilePath + "_out");
    std::string outputPath = inputFilePath + "_out/iteration_" + std::to_string(iteration) + ".txt";

    std::ofstream outFile(outputPath);
    if (!outFile) {
        std::cerr << "Erreur lors de la création du fichier : " << outputPath << std::endl;
        return;
    }

    const auto& cells = grid.getCells();
    int height = cells.size();
    int width = cells[0].size();

    outFile << height << " " << width << std::endl;
    for (const auto& row : cells) {
        for (const auto& cell : row) {
            outFile << (cell.getState() ? "1 " : "0 ");
        }
        outFile << std::endl;
    }
}
