#include "AffichageGraphique.h"
#include <iostream>

AffichageGraphique::AffichageGraphique() : fenetre() {}

void AffichageGraphique::afficher(const Grille& grille) {
    this->fenetre.clear(); // Efface le contenu précédent.
    sf::RectangleShape cellule(sf::Vector2f(tailleCellule - 1, tailleCellule - 1));

    for (int x = 0; x < grille.obtenirLargeur(); ++x) {
        for (int y = 0; y < grille.obtenirHauteur(); ++y) {
            const auto& cell = grille.obtenirCellules()[x][y];

            if (cell.obtenirEstObstacle()) {
                cellule.setFillColor(cell.obtenirEtat() ? sf::Color::Red : sf::Color(128, 128, 128));
            } else {
                cellule.setFillColor(cell.obtenirEtat() ? sf::Color::Green : sf::Color::Black);
            }

            cellule.setPosition(x * tailleCellule, y * tailleCellule);
            fenetre.draw(cellule);
        }
    }
    fenetre.display();
}

void AffichageGraphique::demarrerMode(Grille& grille, const std::string& /*nomFichierEntree*/) {
    fenetre.create(sf::VideoMode(grille.obtenirLargeur() * tailleCellule,
                                 grille.obtenirHauteur() * tailleCellule),
                   "Jeu de la Vie");

    while (fenetre.isOpen()) {
        sf::Event event;
        while (fenetre.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                fenetre.close();
        }

        afficher(grille);
        Grille grillePrecedente = grille;
        grille.mettreAJour();

        if (grille == grillePrecedente) {
            std::cout << "L'automate a atteint un état stable. Fin de l'exécution.\n";
            fenetre.close();
        }

        sf::sleep(sf::milliseconds(100));
    }
}
