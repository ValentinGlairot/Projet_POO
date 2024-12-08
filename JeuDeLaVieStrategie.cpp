#include "JeuDeLaVieStrategie.h"

void JeuDeLaVieStrategie::mettreAJour(Grille& grille) {
    // Copie des cellules actuelles pour préparer la mise à jour.
    std::vector<std::vector<Cellule>> nouvellesCellules = grille.obtenirCellules();

    // Parcourt chaque cellule de la grille.
    for (int x = 0; x < grille.obtenirLargeur(); ++x) {
        for (int y = 0; y < grille.obtenirHauteur(); ++y) {
            const Cellule& celluleActuelle = grille.obtenirCellules()[x][y];

            if (celluleActuelle.obtenirEstObstacle()) {
                // Si c'est un obstacle, ne pas le mettre à jour.
                nouvellesCellules[x][y] = celluleActuelle;
                continue; // Passe à la cellule suivante.
            }

            // Compte les voisins vivants de la cellule.
            int voisinsVivants = grille.compterVoisinsVivants(x, y);

            if (celluleActuelle.obtenirEtat()) {
                // Règles pour une cellule vivante.
                nouvellesCellules[x][y].definirEtat(voisinsVivants == 2 || voisinsVivants == 3);
            } else {
                // Règles pour une cellule morte.
                nouvellesCellules[x][y].definirEtat(voisinsVivants == 3);
            }
        }
    }

    // Met à jour la grille avec les nouvelles cellules.
    grille.definirCellules(nouvellesCellules);
}
