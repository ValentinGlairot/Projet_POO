#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "Grille.h"
#include <string>

// Classe abstraite pour l'affichage de la grille.
// Elle définit des méthodes virtuelles pour afficher la grille et démarrer le mode d'affichage.

class Affichage {
public:
    virtual ~Affichage() {}

    // Méthode pour afficher la grille
    virtual void afficherGrille(const Grille& grille) = 0;

    // Méthode pour démarrer le mode d'affichage
    virtual void demarrerMode(Grille& grille, const std::string& nomFichierEntree = "") = 0;
};

#endif
