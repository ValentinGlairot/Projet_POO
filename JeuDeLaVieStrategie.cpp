#include "JeuDeLaVieStrategie.h"

void JeuDeLaVieStrategie::mettreAJour(Grille& grille) {
    std::vector<std::vector<Cellule>> nouvellesCellules = grille.obtenirCellules();

    for (int x = 0; x < grille.obtenirLargeur(); ++x) {
        for (int y = 0; y < grille.obtenirHauteur(); ++y) {
            const Cellule& celluleActuelle = grille.obtenirCellules()[x][y];

            // Compter les voisins vivants
            int voisinsVivants = grille.compterVoisinsVivants(x, y);

            // Mise à jour selon les règles
            if (celluleActuelle.obtenirEtat()) {
                nouvellesCellules[x][y].definirEtat(voisinsVivants == 2 || voisinsVivants == 3);
            } else {
                nouvellesCellules[x][y].definirEtat(voisinsVivants == 3);
            }
        }
    }

    // Mettre à jour la grille avec les nouvelles cellules
    grille.definirCellules(nouvellesCellules);
}

