#include <iostream>
#include <string>
#include "Grille.h"
#include "Affichage.h"
#include "AffichageConsole.h"
#include "AffichageGraphique.h"
#include "JeuDeLaVieStrategie.h"

int main(int argc, char* argv[]) {
    // Vérifie que le fichier d'entrée est spécifié.
    if (argc < 2) {
        std::cerr << "Usage : " << argv[0] << " <fichier_etat_initial>\n";
        return 1;
    }

    std::string nomFichier = argv[1]; // Récupère le nom du fichier.

    try {
        // Initialise la grille avec le fichier d'entrée.
        Grille grille(0, 0);
        grille.initialiserDepuisFichier(nomFichier);

        // Définit la stratégie du jeu de la vie.
        JeuDeLaVieStrategie strategie;
        grille.definirStrategie(&strategie);

        // Demande à l'utilisateur de choisir le mode d'affichage.
        int choix;
        std::cout << "Choisissez un mode :\n";
        std::cout << "1. Mode Console\n";
        std::cout << "2. Mode Graphique\n";
        std::cout << "Entrez votre choix : ";
        std::cin >> choix;

        Affichage* affichage = nullptr; // Pointeur vers l'affichage.

        if (choix == 1) {
            // Si l'utilisateur choisit le mode console.
            affichage = new AffichageConsole();
            affichage->demarrerMode(grille, nomFichier);
        } else if (choix == 2) {
            // Si l'utilisateur choisit le mode graphique.
            affichage = new AffichageGraphique();
            affichage->demarrerMode(grille);
        } else {
            std::cout << "Choix invalide. Fin du programme.\n";
            return 1;
        }

        delete affichage; // Libère la mémoire allouée.

    } catch (const std::exception& e) {
        // En cas d'erreur lors de l'initialisation ou de l'exécution.
        std::cerr << "Erreur : " << e.what() << "\n";
        return 1;
    }

    return 0; // Fin normale du programme.
}
