#ifndef GRILLE_H
#define GRILLE_H

#include <vector>
#include <string>
#include "Cellule.h"

// Déclaration anticipée de la stratégie de mise à jour.
class MiseAJourStrategie;

// Classe représentant la grille du jeu.
class Grille {
private:
    int largeur;   // Largeur de la grille.
    int hauteur;   // Hauteur de la grille.
    std::vector<std::vector<Cellule>> cellules; // Matrice de cellules.
    MiseAJourStrategie* strategie; // Stratégie de mise à jour.

public:
    // Constructeur avec largeur et hauteur.
    Grille(int larg, int haut);

    // Initialise la grille aléatoirement.
    void initialiserAleatoire();

    // Initialise la grille depuis un fichier.
    void initialiserDepuisFichier(const std::string& nomFichier);

    // Met à jour la grille en utilisant la stratégie.
    void mettreAJour();

    // Vérifie si une position est valide dans la grille.
    bool estCelluleValide(int x, int y) const;

    // Compte les voisins vivants d'une cellule.
    int compterVoisinsVivants(int x, int y) const;

    // Accesseurs pour la largeur et la hauteur.
    int obtenirLargeur() const;
    int obtenirHauteur() const;

    // Obtient la matrice de cellules.
    const std::vector<std::vector<Cellule>>& obtenirCellules() const;

    // Définit la matrice de cellules.
    void definirCellules(const std::vector<std::vector<Cellule>>& nouvellesCellules);

    // Définit la stratégie de mise à jour.
    void definirStrategie(MiseAJourStrategie* nouvelleStrategie);

    // Opérateur de comparaison pour les grilles.
    bool operator==(const Grille& autre) const;
};

#endif // GRILLE_H
