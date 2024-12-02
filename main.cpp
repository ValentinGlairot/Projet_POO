#include <iostream>
#include <string>
#include "Grille.h"
#include "Affichage.h"
#include "AffichageConsole.h"
#include "AffichageGraphique.h"
#include "JeuDeLaVieStrategie.h"

// Programme principal qui initialise la grille et gère le choix du mode (console ou graphique).

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage : " << argv[0] << " <fichier_etat_initial>\n";
        return 1;
    }

    std::string nomFichier = argv[1];

    try {
        // Initialise la grille à partir du fichier
        Grille grille(0, 0);
        grille.initialiserDepuisFichier(nomFichier);

        // Définir la stratégie de mise à jour
        JeuDeLaVieStrategie strategie;
        grille.definirStrategie(&strategie);

        int choix;
        std::cout << "Choisissez un mode :\n";
        std::cout << "1. Mode Console\n";
        std::cout << "2. Mode Graphique\n";
        std::cout << "Entrez votre choix : ";
        std::cin >> choix;

        Affichage* affichage = nullptr;

        if (choix == 1) {
            affichage = new AffichageConsole();
            affichage->demarrerMode(grille, nomFichier);
        } else if (choix == 2) {
            affichage = new AffichageGraphique();
            affichage->demarrerMode(grille);
        } else {
            std::cout << "Choix invalide. Fin du programme.\n";
            return 1;
        }

        delete affichage;

    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << "\n";
        return 1;
    }

    return 0;
}
