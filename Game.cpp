#include "Game.h"
#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>

Game::Game(const std::string& filePath, int maxIterations) : maxIterations(maxIterations) {
    std::ifstream file(filePath);
    int rows, cols;
    file >> rows >> cols;

    std::vector<std::vector<bool>> initialState(rows, std::vector<bool>(cols, false));
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            int state;
            file >> state;
            initialState[r][c] = (state == 1);
        }
    }

    grid = new Grid(rows, cols, initialState);
}

Game::~Game() {
    delete grid;
}

bool Game::isStable(const Grid& previous, const Grid& current) {
    return previous.getCells() == current.getCells();
}

void Game::runConsoleMode() {
    int iteration = 0;

    while (iteration < maxIterations) {
        std::cout << "Iteration " << iteration + 1 << ":\n";

        // Affiche la grille dans la console
        const auto& cells = grid->getCells();
        for (const auto& row : cells) {
            for (bool cell : row) {
                std::cout << (cell ? "1 " : "0 ");
            }
            std::cout << "\n";
        }
        std::cout << "\n";

        // Met à jour la grille
        grid->update();

        iteration++;
    }

    std::cout << "Simulation terminée après " << iteration << " itérations.\n";
}


void Game::runGraphicMode() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Jeu de la Vie");
    window.setFramerateLimit(10);

    int cellSize = 20; // Taille de chaque cellule

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Dessine la grille
        window.clear(sf::Color::Black);
        const auto& cells = grid->getCells();

        for (int r = 0; r < cells.size(); ++r) {
            for (int c = 0; c < cells[r].size(); ++c) {
                sf::RectangleShape cellShape(sf::Vector2f(cellSize, cellSize));
                cellShape.setPosition(c * cellSize, r * cellSize);
                cellShape.setFillColor(cells[r][c] ? sf::Color::Green : sf::Color::White);
                window.draw(cellShape);
            }
        }

        window.display();

        // Met à jour la grille
        grid->update();
    }
}

