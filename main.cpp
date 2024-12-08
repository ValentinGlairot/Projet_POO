#include <iostream>
#include <string>
#include "ControllerJeuDeLaVie.h"

int main(int argc, char* argv[]) {
    // Vérifie que le fichier d'entrée est spécifié.
    if (argc < 2) {
        std::cerr << "Usage : " << argv[0] << " <fichier_etat_initial>\n";
        return 1;
    }

    std::string nomFichier = argv[1]; // Récupère le nom du fichier.

    ControllerJeuDeLaVie controller(nomFichier);
    controller.run();

    return 0; 
}
