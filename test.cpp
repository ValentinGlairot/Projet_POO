#include <iostream>
#include "Grille.h"
#include "JeuDeLaVieStrategie.h"

// Test simple : Initialisation de la grille
void testInitialisationGrille() {
    std::cout << "Test : Initialisation simple de la grille...\n";

    Grille grille(3, 3);
    grille.initialiserDepuisFichier("test_input_simple.txt");

    if (grille.obtenirLargeur() == 3 && grille.obtenirHauteur() == 3) {
        std::cout << "[OK] La taille de la grille est correcte.\n";
    } else {
        std::cout << "[ERREUR] La taille de la grille est incorrecte.\n";
    }

    const auto& cellules = grille.obtenirCellules();
    if (cellules[1][1].obtenirEtat() && !cellules[0][0].obtenirEtat()) {
        std::cout << "[OK] Les états initiaux des cellules sont corrects.\n";
    } else {
        std::cout << "[ERREUR] Les états initiaux des cellules sont incorrects.\n";
    }
}

void testUneIteration() {
    std::cout << "Test : Une itération simple...\n";

    Grille grille(3, 3);
    grille.initialiserDepuisFichier("test_input_simple.txt");

    JeuDeLaVieStrategie strategie;
    grille.definirStrategie(&strategie);

    grille.mettreAJour(); // Applique une itération

    const auto& cellules = grille.obtenirCellules();

    // Toutes les cellules doivent être mortes après une itération
    bool testReussi = true;
    for (int x = 0; x < grille.obtenirLargeur(); ++x) {
        for (int y = 0; y < grille.obtenirHauteur(); ++y) {
            if (cellules[x][y].obtenirEtat()) {
                testReussi = false;
                std::cout << "[ERREUR] La cellule (" << x << ", " << y << ") devrait être morte.\n";
            }
        }
    }

    if (testReussi) {
        std::cout << "[OK] L'évolution après une itération est correcte.\n";
    }
}

int main() {
    testInitialisationGrille();
    testUneIteration();
    return 0;
}
