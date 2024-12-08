#ifndef MISE_A_JOUR_STRATEGIE_H
#define MISE_A_JOUR_STRATEGIE_H

// Déclaration anticipée de la classe Grille.
class Grille;

// Interface pour les stratégies de mise à jour de la grille.
class MiseAJourStrategie {
public:
    virtual ~MiseAJourStrategie() {}
    // Méthode virtuelle pure pour la mise à jour.
    virtual void mettreAJour(Grille& grille) = 0;
};

#endif
