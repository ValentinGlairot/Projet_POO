#ifndef JEU_DE_LA_VIE_STRATEGIE_H
#define JEU_DE_LA_VIE_STRATEGIE_H

#include "MiseAJourStrategie.h"
#include "Grille.h"

// Stratégie pour le jeu de la vie classique.
class JeuDeLaVieStrategie : public MiseAJourStrategie {
public:
    // Méthode pour mettre à jour la grille.
    void mettreAJour(Grille& grille) override;
};

#endif // JEU_DE_LA_VIE_STRATEGIE_H
