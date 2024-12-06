#include "JeuDeLaVieControleur.h"

JeuDeLaVieControleur::JeuDeLaVieControleur(Grille& grille, Affichage& affichage)
    : grille(grille), affichage(affichage) {}

void JeuDeLaVieControleur::executer(int iterations) {
    for (int i = 0; i < iterations; ++i) {
        affichage.afficher(grille);
        grille.mettreAJour();
    }
}
