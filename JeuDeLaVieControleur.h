#ifndef JEU_DE_LA_VIE_CONTROLEUR_H
#define JEU_DE_LA_VIE_CONTROLEUR_H

#include "Grille.h"
#include "Affichage.h"

class JeuDeLaVieControleur {
private:
    Grille& grille;
    Affichage& affichage;

public:
    JeuDeLaVieControleur(Grille& grille, Affichage& affichage);
    void executer(int iterations);
};

#endif // JEU_DE_LA_VIE_CONTROLEUR_H
