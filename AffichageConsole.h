#ifndef AFFICHAGE_CONSOLE_H
#define AFFICHAGE_CONSOLE_H

#include "Affichage.h"

class AffichageConsole : public Affichage {
public:
    void afficher(const Grille& grille) override;
    void demarrerMode(Grille& grille, const std::string& nomFichierEntree = "") override; // Ajoutez cette déclaration.
};

#endif // AFFICHAGE_CONSOLE_H
