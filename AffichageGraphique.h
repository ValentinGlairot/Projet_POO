#ifndef AFFICHAGE_GRAPHIQUE_H
#define AFFICHAGE_GRAPHIQUE_H

#include "Affichage.h"
#include <SFML/Graphics.hpp>

class AffichageGraphique : public Affichage {
private:
    const int tailleCellule = 10;
    sf::RenderWindow fenetre;

public:
    AffichageGraphique(); // Constructeur par défaut.
    void afficher(const Grille& grille) override; // Signature correcte.
    void demarrerMode(Grille& grille, const std::string& nomFichierEntree = "") override; // Signature correcte.
};

#endif // AFFICHAGE_GRAPHIQUE_H
