#ifndef GRILLE_H
#define GRILLE_H

#include <vector>
#include <string>
#include "Cellule.h"

// Déclaration anticipée de la classe MiseAJourStrategie
class MiseAJourStrategie;

// La classe Grille représente la grille du jeu de la vie.
// Elle contient une matrice de cellules et utilise une stratégie pour la mise à jour.
class Grille {
private:
    int largeur;
    int hauteur;
    std::vector<std::vector<Cellule>> cellules;
    MiseAJourStrategie* strategie;

public:
    Grille(int larg, int haut);

    // Méthodes d'initialisation
    void initialiserAleatoire();
    void initialiserDepuisFichier(const std::string& nomFichier);

    // Méthode pour mettre à jour la grille selon la stratégie
    void mettreAJour();

    // Méthodes utilitaires
    bool estCelluleValide(int x, int y) const;
    int compterVoisinsVivants(int x, int y) const;

    // Accesseurs (getters)
    int obtenirLargeur() const;
    int obtenirHauteur() const;
    const std::vector<std::vector<Cellule>>& obtenirCellules() const;

    // Mutateurs (setters)
    void definirCellules(const std::vector<std::vector<Cellule>>& nouvellesCellules);
    void definirStrategie(MiseAJourStrategie* nouvelleStrategie);

    // Opérateur d'égalité pour comparer deux grilles
    bool operator==(const Grille& autre) const;
};

#endif
