#ifndef AFFICHAGE_GRAPHIQUE_H
#define AFFICHAGE_GRAPHIQUE_H

#include "Affichage.h"
#include <SFML/Graphics.hpp>

// Cette classe gère l'affichage graphique de la grille en utilisant SFML.

class AffichageGraphique : public Affichage {
private:
    const int tailleCellule = 10;
    sf::RenderWindow fenetre;

public:
    AffichageGraphique();

    void afficherGrille(const Grille& grille) override;
    void demarrerMode(Grille& grille, const std::string& nomFichierEntree = "") override;
};

#endif // AFFICHAGE_GRAPHIQUE_H
