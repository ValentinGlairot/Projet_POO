#include "JeuDeLaVieStrategie.h"

void JeuDeLaVieStrategie::mettreAJour(Grille& grille) {
    std::vector<std::vector<Cellule>> nouvellesCellules = grille.obtenirCellules();

    for (int x = 0; x < grille.obtenirLargeur(); ++x) {
        for (int y = 0; y < grille.obtenirHauteur(); ++y) {
            int voisinsVivants = grille.compterVoisinsVivants(x, y);
            if (grille.obtenirCellules()[x][y].obtenirEtat()) {
                nouvellesCellules[x][y].definirEtat(voisinsVivants == 2 || voisinsVivants == 3);
            } else {
                nouvellesCellules[x][y].definirEtat(voisinsVivants == 3);
            }
        }
    }

    grille.definirCellules(nouvellesCellules);
}
