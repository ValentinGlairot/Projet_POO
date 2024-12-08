#include "Grille.h"
#include "MiseAJourStrategie.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

// Constructeur de la classe Grille.
Grille::Grille(int larg, int haut) : largeur(larg), hauteur(haut), strategie(nullptr) {
    // Initialise la matrice de cellules avec les dimensions données.
    this->cellules = std::vector<std::vector<Cellule>>(this->largeur, std::vector<Cellule>(this->hauteur));
}

// Initialise la grille avec des états aléatoires.
void Grille::initialiserAleatoire() {
    std::srand(std::time(nullptr)); // Graine pour l'aléatoire.
    // Parcourt chaque cellule de la grille.
    for (int x = 0; x < this->largeur; ++x) {
        for (int y = 0; y < this->hauteur; ++y) {
            // Définit un état vivant aléatoire (vivant ou mort).
            this->cellules[x][y].definirEtat(std::rand() % 2);
            // Par défaut, aucune cellule n'est un obstacle dans cette méthode.
            this->cellules[x][y].definirEstObstacle(false);
        }
    }
}

// Initialise la grille à partir d'un fichier.
void Grille::initialiserDepuisFichier(const std::string& nomFichier) {
    std::ifstream fichier(nomFichier);
    if (!fichier.is_open()) {
        throw std::runtime_error("Impossible d'ouvrir le fichier : " + nomFichier);
    }

    // Lit la largeur et la hauteur depuis le fichier.
    fichier >> this->largeur >> this->hauteur;
    // Redimensionne la matrice de cellules.
    this->cellules = std::vector<std::vector<Cellule>>(this->largeur, std::vector<Cellule>(this->hauteur));

    // Parcourt chaque position de la grille.
    for (int y = 0; y < this->hauteur; ++y) {
        for (int x = 0; x < this->largeur; ++x) {
            int etat;
            fichier >> etat; // Lit l'état de la cellule.

            bool vivante = false;  // État vivant par défaut.
            bool obstacle = false; // État obstacle par défaut.

            // Interprète la valeur lue.
            switch (etat) {
                case 0:
                    vivante = false;
                    obstacle = false;
                    break;
                case 1:
                    vivante = true;
                    obstacle = false;
                    break;
                case 2:
                    vivante = false;
                    obstacle = true;
                    break;
                case 3:
                    vivante = true;
                    obstacle = true;
                    break;
                default:
                    throw std::runtime_error("Valeur incorrecte dans le fichier d'entrée : " + std::to_string(etat));
            }

            // Crée la cellule avec les états déterminés.
            this->cellules[x][y] = Cellule(vivante, obstacle);
        }
    }
    fichier.close(); // Ferme le fichier après lecture.
}

// Met à jour la grille en utilisant la stratégie définie.
void Grille::mettreAJour() {
    if (this->strategie != nullptr) {
        this->strategie->mettreAJour(*this); // Applique la stratégie.
    } else {
        std::cerr << "Erreur : Aucune stratégie de mise à jour n'a été définie.\n";
    }
}

// Vérifie si une position est valide dans la grille.
bool Grille::estCelluleValide(int x, int y) const {
    // Vérifie que les coordonnées sont dans les limites.
    return x >= 0 && x < this->largeur && y >= 0 && y < this->hauteur;
}

// Compte les voisins vivants d'une cellule donnée.
int Grille::compterVoisinsVivants(int x, int y) const {
    int compte = 0;

    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue; // Ignore la cellule elle-même

            int nx = x + dx;
            int ny = y + dy;

            if (estCelluleValide(nx, ny)) {
                if (cellules[nx][ny].obtenirEtat()) {
                    ++compte;
                }
            }
        }
    }

    return compte;
}


// Obtient la largeur de la grille.
int Grille::obtenirLargeur() const {
    return this->largeur;
}

// Obtient la hauteur de la grille.
int Grille::obtenirHauteur() const {
    return this->hauteur;
}

// Retourne la matrice de cellules.
const std::vector<std::vector<Cellule>>& Grille::obtenirCellules() const {
    return this->cellules;
}

// Définit une nouvelle matrice de cellules.
void Grille::definirCellules(const std::vector<std::vector<Cellule>>& nouvellesCellules) {
    this->cellules = nouvellesCellules;
}

// Définit la stratégie de mise à jour.
void Grille::definirStrategie(MiseAJourStrategie* nouvelleStrategie) {
    this->strategie = nouvelleStrategie;
}

// Compare deux grilles en comparant leurs cellules.
bool Grille::operator==(const Grille& autre) const {
    return this->cellules == autre.cellules;
}
