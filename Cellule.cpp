#include "Cellule.h"

// Constructeur de la classe Cellule.
Cellule::Cellule(bool vivante, bool obstacle) {
    this->estVivante = vivante;   // Initialise l'état vivant.
    this->estObstacle = obstacle; // Initialise l'état obstacle.
}

// Retourne si la cellule est vivante.
bool Cellule::obtenirEtat() const {
    return this->estVivante;
}

// Définit si la cellule est vivante.
void Cellule::definirEtat(bool etat) {
    this->estVivante = etat;
}

// Retourne si la cellule est un obstacle.
bool Cellule::obtenirEstObstacle() const {
    return this->estObstacle;
}

// Définit si la cellule est un obstacle.
void Cellule::definirEstObstacle(bool obstacle) {
    this->estObstacle = obstacle;
}

// Compare deux cellules (état vivant et obstacle).
bool Cellule::operator==(const Cellule& autre) const {
    return this->estVivante == autre.estVivante && this->estObstacle == autre.estObstacle;
}
