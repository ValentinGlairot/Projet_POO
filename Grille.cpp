#include "Grille.h"
#include "MiseAJourStrategie.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

Grille::Grille(int larg, int haut) : largeur(larg), hauteur(haut), strategie(nullptr) {
    this->cellules = std::vector<std::vector<Cellule>>(this->largeur, std::vector<Cellule>(this->hauteur));
}

void Grille::initialiserAleatoire() {
    std::srand(std::time(nullptr));
    for (int x = 0; x < this->largeur; ++x) {
        for (int y = 0; y < this->hauteur; ++y) {
            this->cellules[x][y].definirEtat(std::rand() % 2);
        }
    }
}

void Grille::initialiserDepuisFichier(const std::string& nomFichier) {
    std::ifstream fichier(nomFichier);
    if (!fichier.is_open()) {
        throw std::runtime_error("Impossible d'ouvrir le fichier : " + nomFichier);
    }

    fichier >> this->largeur >> this->hauteur;
    this->cellules = std::vector<std::vector<Cellule>>(this->largeur, std::vector<Cellule>(this->hauteur));

    for (int y = 0; y < this->hauteur; ++y) {
        for (int x = 0; x < this->largeur; ++x) {
            int etat;
            fichier >> etat;
            this->cellules[x][y].definirEtat(etat == 1);
        }
    }
    fichier.close();
}

void Grille::mettreAJour() {
    if (this->strategie != nullptr) {
        this->strategie->mettreAJour(*this);
    } else {
        std::cerr << "Erreur : Aucune stratégie de mise à jour n'a été définie.\n";
    }
}

bool Grille::estCelluleValide(int x, int y) const {
    return x >= 0 && x < this->largeur && y >= 0 && y < this->hauteur;
}

int Grille::compterVoisinsVivants(int x, int y) const {
    int compte = 0;

    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue; // Ignore la cellule elle-même

            int nx = x + dx;
            int ny = y + dy;

            // Vérifie si la cellule voisine est valide et vivante
            if (this->estCelluleValide(nx, ny) && this->cellules[nx][ny].obtenirEtat()) {
                ++compte;
            }
        }
    }

    return compte;
}

int Grille::obtenirLargeur() const {
    return this->largeur;
}

int Grille::obtenirHauteur() const {
    return this->hauteur;
}

const std::vector<std::vector<Cellule>>& Grille::obtenirCellules() const {
    return this->cellules;
}

void Grille::definirCellules(const std::vector<std::vector<Cellule>>& nouvellesCellules) {
    this->cellules = nouvellesCellules;
}

void Grille::definirStrategie(MiseAJourStrategie* nouvelleStrategie) {
    this->strategie = nouvelleStrategie;
}

bool Grille::operator==(const Grille& autre) const {
    return this->cellules == autre.cellules;
}
