#ifndef CELLULE_H
#define CELLULE_H

// Classe représentant une cellule dans la grille.
class Cellule {
private:
    bool estVivante;   // État de la cellule (vivante ou morte).
    bool estObstacle;  // Indique si la cellule est un obstacle.

public:
    // Constructeur avec état vivant et obstacle par défaut.
    Cellule(bool vivante = false, bool obstacle = false);

    // Obtient l'état vivant de la cellule.
    bool obtenirEtat() const;

    // Définit l'état vivant de la cellule.
    void definirEtat(bool etat);

    // Vérifie si la cellule est un obstacle.
    bool obtenirEstObstacle() const;

    // Définit si la cellule est un obstacle.
    void definirEstObstacle(bool obstacle);

    // Opérateur de comparaison pour les cellules.
    bool operator==(const Cellule& autre) const;
};

#endif // CELLULE_H
