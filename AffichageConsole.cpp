#include "AffichageConsole.h"
#include <iostream>

void AffichageConsole::afficher(const Grille& grille) {
    for (int y = 0; y < grille.obtenirHauteur(); ++y) {
        for (int x = 0; x < grille.obtenirLargeur(); ++x) {
            const auto& cellule = grille.obtenirCellules()[x][y];
            std::cout << (cellule.obtenirEtat() ? "O" : ".") << " ";
        }
        std::cout << std::endl;
    }
}

void AffichageConsole::demarrerMode(Grille& /*grille*/, const std::string& /*nomFichierEntree*/) {
    // Implémentation minimale ou une action spécifique si nécessaire.
    std::cout << "Mode console démarré.\n";
}
