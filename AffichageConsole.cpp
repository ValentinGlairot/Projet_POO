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

void AffichageConsole::afficherGrille(const Grille& grille) {
    const auto& cellules = grille.obtenirCellules();
    for (int y = 0; y < grille.obtenirHauteur(); ++y) {
        for (int x = 0; x < grille.obtenirLargeur(); ++x) {
            std::cout << (cellules[x][y].obtenirEtat() ? "O" : ".") << " ";
        }
        std::cout << std::endl;
    }
}

void AffichageConsole::sauvegarderGrilleDansFichier(const Grille& grille, const std::string& repertoire, int iteration) {
    std::string nomFichier = repertoire + "/iteration_" + std::to_string(iteration) + ".txt";
    std::ofstream fichier(nomFichier);
    if (!fichier.is_open()) {
        std::cerr << "Erreur lors de l'ouverture du fichier " << nomFichier << " pour l'écriture.\n";
        return;
    }

    fichier << grille.obtenirLargeur() << " " << grille.obtenirHauteur() << "\n";
    const auto& cellules = grille.obtenirCellules();
    for (int y = 0; y < grille.obtenirHauteur(); ++y) {
        for (int x = 0; x < grille.obtenirLargeur(); ++x) {
            fichier << (cellules[x][y].obtenirEtat() ? "1 " : "0 ");
        }
        fichier << "\n";
    }

    fichier.close();
}

void AffichageConsole::demarrerMode(Grille& grille, const std::string& nomFichierEntree) {
    int iterations;
    std::cout << "Entrez le nombre maximum d'itérations : ";
    std::cin >> iterations;

    // Extraire le nom du fichier sans le chemin ni l'extension
    size_t lastSlash = nomFichierEntree.find_last_of("/\\");
    std::string baseFilename = nomFichierEntree.substr(lastSlash + 1);
    size_t lastDot = baseFilename.find_last_of(".");
    if (lastDot != std::string::npos) {
        baseFilename = baseFilename.substr(0, lastDot);
    }

    // Nom du dossier de sortie
    std::string repertoireSortie = baseFilename + "_out";

    // Création du dossier de sortie
    int dirResult = creerRepertoire(repertoireSortie.c_str()
    #ifdef __linux__
        , 0777  // Permissions pour Linux
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

    // Sauvegarder l'état initial
    int iteration = 0;
    this->sauvegarderGrilleDansFichier(grille, repertoireSortie, iteration);

    for (iteration = 1; iteration <= iterations; ++iteration) {
        std::cout << "Itération " << iteration << " :\n";
        this->afficherGrille(grille);

        Grille grillePrecedente = grille; // Sauvegarde de l'état précédent
        grille.mettreAJour();

        // Sauvegarder l'état courant
        this->sauvegarderGrilleDansFichier(grille, repertoireSortie, iteration);

        // Vérifier si l'état a changé
        if (grille == grillePrecedente) {
            std::cout << "L'automate a atteint un état stable. Fin de l'exécution.\n";
            break;
        }

        std::cout << "\n";
    }
}
