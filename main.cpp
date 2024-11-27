#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include "Grid.h"

// Ajout des includes pour mkdir
#ifdef _WIN32
    #include <direct.h>
    #define mkdir _mkdir
#else
    #include <sys/stat.h>
    #include <sys/types.h>
#endif

const int cellSize = 10;

void renderGridConsole(const Grid& grid);
void saveGridToFile(const Grid& grid, const std::string& directory, int iteration);
void renderGridGraphics(const Grid& grid, sf::RenderWindow& window);
void consoleMode(Grid& grid, const std::string& inputFilename);
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
            consoleMode(grid, filename);
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

void saveGridToFile(const Grid& grid, const std::string& directory, int iteration) {
    std::string filename = directory + "/iteration_" + std::to_string(iteration) + ".txt";
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Erreur lors de l'ouverture du fichier " << filename << " pour l'écriture.\n";
        return;
    }

    file << grid.getWidth() << " " << grid.getHeight() << "\n";
    const auto& cells = grid.getCells();
    for (int y = 0; y < grid.getHeight(); ++y) {
        for (int x = 0; x < grid.getWidth(); ++x) {
            file << (cells[x][y].getState() ? "1 " : "0 ");
        }
        file << "\n";
    }

    file.close();
}

void consoleMode(Grid& grid, const std::string& inputFilename) {
    int iterations;
    std::cout << "Entrez le nombre maximum d'itérations : ";
    std::cin >> iterations;

    // Extraire le nom du fichier sans le chemin ni l'extension
    size_t lastSlash = inputFilename.find_last_of("/\\");
    std::string baseFilename = inputFilename.substr(lastSlash + 1);
    size_t lastDot = baseFilename.find_last_of(".");
    if (lastDot != std::string::npos) {
        baseFilename = baseFilename.substr(0, lastDot);
    }

    // Nom du dossier de sortie
    std::string outputDir = baseFilename + "_out";

    // Création du dossier de sortie
    int dirResult = mkdir(outputDir.c_str()
#ifdef __linux__
    , 0777  // Permissions pour Linux
#endif
    );

    if (dirResult == 0) {
        std::cout << "Création du dossier de sortie : " << outputDir << "\n";
    } else if (errno == EEXIST) {
        std::cout << "Le dossier de sortie existe déjà : " << outputDir << "\n";
    } else {
        std::cerr << "Erreur : Impossible de créer le dossier de sortie " << outputDir << "\n";
        return;
    }

    // Sauvegarder l'état initial
    int iteration = 0;
    saveGridToFile(grid, outputDir, iteration);

    for (iteration = 1; iteration <= iterations; ++iteration) {
        std::cout << "Itération " << iteration << " :\n";
        renderGridConsole(grid);

        Grid previousGrid = grid; // Sauvegarde de l'état précédent
        grid.update();

        // Sauvegarder l'état courant
        saveGridToFile(grid, outputDir, iteration);

        // Vérifier si l'état a changé
        if (grid == previousGrid) {
            std::cout << "L'automate a atteint un état stable. Fin de l'exécution.\n";
            break;
        }

        std::cout << "\n";
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

void graphicsMode(Grid& grid) {
    int delay;
    std::cout << "Entrez le délai entre les itérations (en ms) : ";
    std::cin >> delay;

    sf::RenderWindow window(sf::VideoMode(grid.getCells().size() * cellSize, grid.getCells()[0].size() * cellSize), "Jeu de la Vie");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        renderGridGraphics(grid, window);

        Grid previousGrid = grid; // Sauvegarde de l'état précédent
        grid.update();

        // Vérifier si l'état a changé
        if (grid == previousGrid) {
            std::cout << "L'automate a atteint un état stable. Fin de l'exécution.\n";
            window.close();
        }

        sf::sleep(sf::milliseconds(delay));
    }
}
