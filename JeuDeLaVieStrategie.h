#ifndef JEU_DE_LA_VIE_STRATEGIE_H
#define JEU_DE_LA_VIE_STRATEGIE_H

#include "MiseAJourStrategie.h"
#include "Grille.h"

// Implémentation de la stratégie standard du Jeu de la Vie
// Applique les règles classiques du jeu pour mettre à jour la grille
class JeuDeLaVieStrategie : public MiseAJourStrategie {
public:
    void mettreAJour(Grille& grille) override;
};

#endif
