#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "Grille.h"
#include <string>

// Classe abstraite pour l'affichage de la grille.
class Affichage {
public:
    virtual ~Affichage() {}

    // Méthode virtuelle pure pour afficher la grille.
    virtual void afficherGrille(const Grille& grille) = 0;

    // Méthode virtuelle pure pour démarrer le mode d'affichage.
    virtual void demarrerMode(Grille& grille, const std::string& nomFichierEntree = "") = 0;
};

#endif
