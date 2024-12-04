#include "AffichageConsole.h"
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#ifdef _WIN32
    #include <direct.h>
    #define creerRepertoire _mkdir
#else
    #define creerRepertoire mkdir
#endif

// Affiche la grille dans la console.
void AffichageConsole::afficherGrille(const Grille& grille) {
    const auto& cellules = grille.obtenirCellules();

    // Parcourt chaque ligne de la grille.
    for (int y = 0; y < grille.obtenirHauteur(); ++y) {
        // Parcourt chaque colonne de la grille.
        for (int x = 0; x < grille.obtenirLargeur(); ++x) {
            const Cellule& cell = cellules[x][y];
            if (cell.obtenirEstObstacle()) {
                // Affiche "X" si obstacle vivant, "#" si obstacle mort.
                std::cout << (cell.obtenirEtat() ? "X" : "#") << " ";
            } else {
                // Affiche "O" si vivante, "." si morte.
                std::cout << (cell.obtenirEtat() ? "O" : ".") << " ";
            }
        }
        std::cout << std::endl; // Nouvelle ligne après chaque ligne.
    }
}

// Sauvegarde la grille dans un fichier texte.
void AffichageConsole::sauvegarderGrilleDansFichier(const Grille& grille, const std::string& repertoire, int iteration) {
    // Crée le nom du fichier avec l'itération.
    std::string nomFichier = repertoire + "/iteration_" + std::to_string(iteration) + ".txt";
    std::ofstream fichier(nomFichier);
    if (!fichier.is_open()) {
        std::cerr << "Erreur lors de l'ouverture du fichier " << nomFichier << " pour l'écriture.\n";
        return;
    }

    // Écrit les dimensions de la grille.
    fichier << grille.obtenirLargeur() << " " << grille.obtenirHauteur() << "\n";
    const auto& cellules = grille.obtenirCellules();

    // Parcourt chaque cellule pour écrire son état.
    for (int y = 0; y < grille.obtenirHauteur(); ++y) {
        for (int x = 0; x < grille.obtenirLargeur(); ++x) {
            const Cellule& cell = cellules[x][y];
            int etat = 0;
            if (cell.obtenirEstObstacle()) {
                etat = cell.obtenirEtat() ? 3 : 2; // 3 pour obstacle vivant, 2 pour obstacle mort.
            } else {
                etat = cell.obtenirEtat() ? 1 : 0; // 1 pour vivant, 0 pour mort.
            }
            fichier << etat << " "; // Écrit l'état dans le fichier.
        }
        fichier << "\n"; // Nouvelle ligne après chaque ligne.
    }

    fichier.close(); // Ferme le fichier après écriture.
}

// Démarre le mode console pour l'exécution du jeu.
void AffichageConsole::demarrerMode(Grille& grille, const std::string& nomFichierEntree) {
    int iterations;
    std::cout << "Entrez le nombre maximum d'itérations : ";
    std::cin >> iterations; // Lit le nombre d'itérations.

    // Extrait le nom de base du fichier d'entrée.
    size_t lastSlash = nomFichierEntree.find_last_of("/\\");
    std::string baseFilename = nomFichierEntree.substr(lastSlash + 1);
    size_t lastDot = baseFilename.find_last_of(".");
    if (lastDot != std::string::npos) {
        baseFilename = baseFilename.substr(0, lastDot);
    }

    // Définit le répertoire de sortie pour les fichiers.
    std::string repertoireSortie = baseFilename + "_out";

    // Crée le répertoire de sortie.
    int dirResult = creerRepertoire(repertoireSortie.c_str()
    #ifdef __linux__
        , 0777  // Permissions pour Linux.
    #endif
    );

    if (dirResult == 0) {
        std::cout << "Création du dossier de sortie : " << repertoireSortie << "\n";
    } else if (errno == EEXIST) {
        std::cout << "Le dossier de sortie existe déjà : " << repertoireSortie << "\n";
    } else {
        std::cerr << "Erreur : Impossible de créer le dossier de sortie " << repertoireSortie << "\n";
        return;
    }

    // Sauvegarde l'état initial de la grille.
    int iteration = 0;
    this->sauvegarderGrilleDansFichier(grille, repertoireSortie, iteration);

    // Boucle pour chaque itération demandée.
    for (iteration = 1; iteration <= iterations; ++iteration) {
        std::cout << "Itération " << iteration << " :\n";
        this->afficherGrille(grille); // Affiche la grille actuelle.

        Grille grillePrecedente = grille; // Sauvegarde l'état précédent.
        grille.mettreAJour(); // Met à jour la grille.

        // Sauvegarde l'état actuel de la grille.
        this->sauvegarderGrilleDansFichier(grille, repertoireSortie, iteration);

        // Vérifie si la grille est stable (ne change plus).
        if (grille == grillePrecedente) {
            std::cout << "L'automate a atteint un état stable. Fin de l'exécution.\n";
            break; // Sort de la boucle si stable.
        }

        std::cout << "\n"; // Ligne vide pour espacer les itérations.
    }
}
