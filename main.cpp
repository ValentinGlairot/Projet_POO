#include "Game.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <file_path> <iterations>" << std::endl;
        return 1;
    }

    std::string filePath = argv[1];
    int iterations = std::stoi(argv[2]);

    Game game(filePath, iterations);

    char mode;
    std::cout << "Select mode: (c) Console, (g) Graphic: ";
    std::cin >> mode;

    if (mode == 'c') {
        game.runConsoleMode();
    } else if (mode == 'g') {
        game.runGraphicMode();
    } else {
        std::cerr << "Invalid mode selected!" << std::endl;
    }

    return 0;
}
