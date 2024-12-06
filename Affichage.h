#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "Grille.h"
#include <string>

// Interface pour les affichages.
class Affichage {
public:
    virtual ~Affichage() {}
    virtual void afficher(const Grille& grille) = 0; // Méthode virtuelle pure.
    virtual void demarrerMode(Grille& grille, const std::string& nomFichierEntree = "") = 0; // Méthode virtuelle pure.
};

#endif // AFFICHAGE_H
