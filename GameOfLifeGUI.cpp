#include "GameOfLifeGUI.h"
#include <iostream> // Ajout de l'inclusion

GameOfLifeGUI::GameOfLifeGUI(const std::string& inputFilePath, int maxIterations, int cellSize, float iterationDelay)
    : GameOfLife(inputFilePath, maxIterations), cellSize(cellSize), iterationDelay(iterationDelay) {
    loadInitialState();
    const auto& cells = grid.getCells();
    windowWidth = cells[0].size() * cellSize;
    windowHeight = cells.size() * cellSize;
    window.create(sf::VideoMode(windowWidth, windowHeight), "Jeu de la Vie - Mode Graphique");
}

void GameOfLifeGUI::runGraphicMode() {
    Grid previousGrid = grid;
    sf::Clock clock;
    float timeSinceLastIteration = 0.0f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        timeSinceLastIteration += clock.restart().asSeconds();

        if (timeSinceLastIteration >= iterationDelay) {
            timeSinceLastIteration = 0.0f;

            renderGrid();
            grid.update();

            if (grid.isStable(previousGrid)) {
                std::cout << "La grille est stable. Fin de la simulation." << std::endl;
                window.close();
            }

            previousGrid = grid;
        }
    }
}

void GameOfLifeGUI::renderGrid() {
    window.clear(sf::Color::Black);
    sf::RectangleShape cellShape(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
    cellShape.setFillColor(sf::Color::White);

    const auto& cells = grid.getCells();
    for (size_t y = 0; y < cells.size(); ++y) {
        for (size_t x = 0; x < cells[y].size(); ++x) {
            if (cells[y][x].getState()) {
                cellShape.setPosition(static_cast<float>(x * cellSize), static_cast<float>(y * cellSize));
                window.draw(cellShape);
            }
        }
    }

    window.display();
}
