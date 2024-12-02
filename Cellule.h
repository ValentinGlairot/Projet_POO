#ifndef CELLULE_H
#define CELLULE_H

// La classe Cellule représente une cellule individuelle dans le jeu de la vie.
// Elle contient l'état de la cellule (vivante ou morte) et des méthodes pour accéder et modifier cet état.

class Cellule {
private:
    bool estVivante;

public:
    Cellule(bool vivante = false);

    // Accesseurs (getters) et mutateurs (setters)
    bool obtenirEtat() const;
    void definirEtat(bool etat);

    // Opérateur d'égalité pour comparer deux cellules
    bool operator==(const Cellule& autre) const;
};

#endif
