#ifndef AFFICHAGE_GRAPHIQUE_H
#define AFFICHAGE_GRAPHIQUE_H

#include "Affichage.h"
#include <SFML/Graphics.hpp>

// Classe pour l'affichage graphique du jeu avec SFML.
class AffichageGraphique : public Affichage {
private:
    const int tailleCellule = 10; // Taille de chaque cellule en pixels.
    sf::RenderWindow fenetre;     // Fenêtre SFML pour l'affichage.
    

public:
    // Constructeur par défaut.
    AffichageGraphique();

    // Affiche la grille dans la fenêtre graphique.
    void afficherGrille(const Grille& grille) override;

    // Démarre le mode graphique.
    void demarrerMode(Grille& grille, const std::string& nomFichierEntree = "") override;
    void ouvrirFenetre(int largeur, int hauteur);
    bool estFenetreOuverte() const;
    void gererEvenements();
    void fermerFenetre();

};

#endif
