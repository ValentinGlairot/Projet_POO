#ifndef AFFICHAGE_CONSOLE_H
#define AFFICHAGE_CONSOLE_H

#include "Affichage.h"
#include <string>

// Cette classe gère l'affichage en mode console et la sauvegarde des états de la grille dans des fichiers.

class AffichageConsole : public Affichage {
public:
    void afficherGrille(const Grille& grille) override;
    void demarrerMode(Grille& grille, const std::string& nomFichierEntree = "") override;

private:
    void sauvegarderGrilleDansFichier(const Grille& grille, const std::string& repertoire, int iteration);
};

#endif
