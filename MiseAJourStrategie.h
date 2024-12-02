#ifndef MISE_A_JOUR_STRATEGIE_H
#define MISE_A_JOUR_STRATEGIE_H

// Déclaration anticipée de la classe Grille
class Grille;

// Interface pour la stratégie de mise à jour de la grille
// Permet de définir différentes règles pour l'évolution de la grille
class MiseAJourStrategie {
public:
    virtual ~MiseAJourStrategie() {}
    virtual void mettreAJour(Grille& grille) = 0;
};

#endif
