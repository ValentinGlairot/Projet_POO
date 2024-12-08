#ifndef CONTROLLER_JEU_DE_LA_VIE_H
#define CONTROLLER_JEU_DE_LA_VIE_H

#include <string>
#include "Grille.h"
#include "MiseAJourStrategie.h"
#include "Affichage.h"

// Contrôleur pour le jeu de la vie, coordonne le modèle (Grille), la stratégie (JeuDeLaVieStrategie) et la vue (Affichage).
class ControllerJeuDeLaVie {
public:
    ControllerJeuDeLaVie(const std::string& nomFichier);
    void run();

private:
    Grille grille;                 // Modèle
    MiseAJourStrategie* strategie; // Stratégie de mise à jour (modèle)
    Affichage* affichage;          // Vue

    void choisirAffichage();
    void modeConsole();
    void modeGraphique();
};

#endif // CONTROLLER_JEU_DE_LA_VIE_H
