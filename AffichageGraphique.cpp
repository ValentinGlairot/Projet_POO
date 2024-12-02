#include "AffichageGraphique.h"
#include <iostream>

AffichageGraphique::AffichageGraphique() : fenetre() {
    // Constructeur vide
}

void AffichageGraphique::afficherGrille(const Grille& grille) {
    this->fenetre.clear();
    sf::RectangleShape formeCellule(sf::Vector2f(this->tailleCellule - 1.0f, this->tailleCellule - 1.0f));
    const auto& cellules = grille.obtenirCellules();

    for (int x = 0; x < grille.obtenirLargeur(); ++x) {
        for (int y = 0; y < grille.obtenirHauteur(); ++y) {
            if (cellules[x][y].obtenirEtat()) {
                formeCellule.setPosition(x * this->tailleCellule, y * this->tailleCellule);
                this->fenetre.draw(formeCellule);
            }
        }
    }
    this->fenetre.display();
}

void AffichageGraphique::demarrerMode(Grille& grille, const std::string& /*nomFichierEntree*/) {
    int delai;
    std::cout << "Entrez le délai entre les itérations (en ms) : ";
    std::cin >> delai;

    this->fenetre.create(sf::VideoMode(grille.obtenirLargeur() * this->tailleCellule, grille.obtenirHauteur() * this->tailleCellule), "Jeu de la Vie");

    while (this->fenetre.isOpen()) {
        sf::Event evenement;
        while (this->fenetre.pollEvent(evenement)) {
            if (evenement.type == sf::Event::Closed)
                this->fenetre.close();
        }

        this->afficherGrille(grille);

        Grille grillePrecedente = grille; // Sauvegarde de l'état précédent
        grille.mettreAJour();

        // Vérifier si l'état a changé
        if (grille == grillePrecedente) {
            std::cout << "L'automate a atteint un état stable. Fin de l'exécution.\n";
            this->fenetre.close();
        }

        sf::sleep(sf::milliseconds(delai));
    }
}
