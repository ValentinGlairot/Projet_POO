#include "Cellule.h"

Cellule::Cellule(bool vivante) {
    this->estVivante = vivante;
}

bool Cellule::obtenirEtat() const {
    return this->estVivante;
}

void Cellule::definirEtat(bool etat) {
    this->estVivante = etat;
}

bool Cellule::operator==(const Cellule& autre) const {
    return this->estVivante == autre.estVivante;
}
