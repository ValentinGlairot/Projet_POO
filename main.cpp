#include "GameOfLife.h"
#include "GameOfLifeGUI.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Utilisation : " << argv[0] << " <fichier_d_entree> <mode>" << std::endl;
        std::cerr << "Modes disponibles : console, graphique" << std::endl;
        return 1;
    }

    std::string inputFilePath = argv[1];
    std::string mode = argv[2];

    if (mode == "console") {
        GameOfLife game(inputFilePath);
        game.runConsoleMode();
    } else if (mode == "graphique") {
        GameOfLifeGUI gameGUI(inputFilePath);
        gameGUI.runGraphicMode();
    } else {
        std::cerr << "Mode inconnu : " << mode << std::endl;
        std::cerr << "Modes disponibles : console, graphique" << std::endl;
        return 1;
    }

    return 0;
}
