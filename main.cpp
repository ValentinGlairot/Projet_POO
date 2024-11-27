#include <SFML/Graphics.hpp>
#include <iostream>
#include "Grid.h"

const int cellSize = 10;

void renderGridConsole(const Grid& grid);
void renderGridGraphics(const Grid& grid, sf::RenderWindow& window);
void consoleMode(Grid& grid);
void graphicsMode(Grid& grid);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage : " << argv[0] << " <fichier_etat_initial>\n";
        return 1;
    }

    std::string filename = argv[1];

    try {
        // Initialise la grille à partir du fichier
        Grid grid(0, 0);
        grid.initializeFromFile(filename);

        int choice;
        std::cout << "Choisissez un mode :\n";
        std::cout << "1. Mode Console\n";
        std::cout << "2. Mode Graphique\n";
        std::cout << "Entrez votre choix : ";
        std::cin >> choice;

        if (choice == 1) {
            consoleMode(grid);
        } else if (choice == 2) {
            graphicsMode(grid);
        } else {
            std::cout << "Choix invalide. Fin du programme.\n";
        }
    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << "\n";
        return 1;
    }

    return 0;
}

void renderGridConsole(const Grid& grid) {
    const auto& cells = grid.getCells();
    for (size_t y = 0; y < cells[0].size(); ++y) {
        for (size_t x = 0; x < cells.size(); ++x) {
            std::cout << (cells[x][y].getState() ? "O" : ".") << " ";
        }
        std::cout << std::endl;
    }
}

void renderGridGraphics(const Grid& grid, sf::RenderWindow& window) {
    window.clear();
    sf::RectangleShape cellShape(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
    const auto& cells = grid.getCells();

    for (size_t x = 0; x < cells.size(); ++x) {
        for (size_t y = 0; y < cells[0].size(); ++y) {
            if (cells[x][y].getState()) {
                cellShape.setPosition(x * cellSize, y * cellSize);
                window.draw(cellShape);
            }
        }
    }
    window.display();
}

void consoleMode(Grid& grid) {
    int iterations;
    std::cout << "Entrez le nombre d'itérations : ";
    std::cin >> iterations;

    for (int i = 0; i < iterations; ++i) {
        std::cout << "Iteration " << i + 1 << " :\n";
        renderGridConsole(grid);
        grid.update();
        std::cout << "\n";
    }
}

void graphicsMode(Grid& grid) {
    sf::RenderWindow window(sf::VideoMode(grid.getCells().size() * cellSize, grid.getCells()[0].size() * cellSize), "Game of Life");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        renderGridGraphics(grid, window);
        grid.update();

        sf::sleep(sf::milliseconds(50)); // Pause de 50ms pour accélérer les itérations
    }
}
