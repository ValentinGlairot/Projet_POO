#include <iostream>
#include "Grille.h"
#include "AffichageConsole.h"
#include "JeuDeLaVieStrategie.h"
#include "JeuDeLaVieControleur.h"

int main() {
    // Initialisation de la grille.
    Grille grille(10, 10);
    grille.initialiserAleatoire();

    // Définition de la stratégie.
    JeuDeLaVieStrategie strategie;
    grille.definirStrategie(&strategie);

    // Création de la vue et du contrôleur.
    AffichageConsole affichageConsole;
    JeuDeLaVieControleur controleur(grille, affichageConsole);

    // Lancement du jeu.
    int iterations = 10; // Exemple d'itérations.
    controleur.executer(iterations);

    return 0;
}
