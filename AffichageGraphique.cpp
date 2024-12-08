#include "AffichageGraphique.h"
#include <iostream>

// Constructeur de la classe AffichageGraphique.
AffichageGraphique::AffichageGraphique() : fenetre() {
    // Constructeur vide car l'initialisation se fait dans demarrerMode().
}

// Affiche la grille dans la fenêtre graphique.
void AffichageGraphique::afficherGrille(const Grille& grille) {
    this->fenetre.clear(); // Efface le contenu précédent de la fenêtre.

    // Crée une forme pour représenter les cellules.
    sf::RectangleShape formeCellule(sf::Vector2f(this->tailleCellule - 1.0f, this->tailleCellule - 1.0f));
    const auto& cellules = grille.obtenirCellules();

    // Parcourt chaque cellule de la grille.
    for (int x = 0; x < grille.obtenirLargeur(); ++x) {
        for (int y = 0; y < grille.obtenirHauteur(); ++y) {
            const Cellule& cell = cellules[x][y];

            if (cell.obtenirEstObstacle()) {
                if (cell.obtenirEtat()) {
                    formeCellule.setFillColor(sf::Color::Red); // Obstacle vivant en rouge.
                } else {
                    formeCellule.setFillColor(sf::Color(128, 128, 128)); // Obstacle mort en gris.
                }
            } else {
                if (cell.obtenirEtat()) {
                    formeCellule.setFillColor(sf::Color::Green); // Cellule vivante en vert.
                } else {
                    formeCellule.setFillColor(sf::Color::Black); // Cellule morte en noir.
                }
            }

            // Positionne la cellule dans la fenêtre.
            formeCellule.setPosition(x * this->tailleCellule, y * this->tailleCellule);
            this->fenetre.draw(formeCellule); // Dessine la cellule.
        }
    }

    this->fenetre.display(); // Affiche le contenu dessiné.
}

// Démarre le mode graphique pour l'exécution du jeu.
void AffichageGraphique::demarrerMode(Grille& grille, const std::string& /*nomFichierEntree*/) {
    int delai;
    std::cout << "Entrez le délai entre les itérations (en ms) : ";
    std::cin >> delai; // Lit le délai entre les itérations.

    // Crée la fenêtre graphique avec les dimensions adaptées.
    this->fenetre.create(sf::VideoMode(grille.obtenirLargeur() * this->tailleCellule,
                                       grille.obtenirHauteur() * this->tailleCellule),
                         "Jeu de la Vie");

    // Boucle principale d'affichage.
    while (this->fenetre.isOpen()) {
        sf::Event evenement;
        while (this->fenetre.pollEvent(evenement)) {
            if (evenement.type == sf::Event::Closed)
                this->fenetre.close(); // Ferme la fenêtre si l'utilisateur le demande.
        }

        this->afficherGrille(grille); // Affiche la grille actuelle.

        Grille grillePrecedente = grille; // Sauvegarde l'état précédent.
        grille.mettreAJour(); // Met à jour la grille.

        // Vérifie si la grille est stable (ne change plus).
        if (grille == grillePrecedente) {
            std::cout << "L'automate a atteint un état stable. Fin de l'exécution.\n";
            this->fenetre.close(); // Ferme la fenêtre.
        }

        sf::sleep(sf::milliseconds(delai)); // Attend le délai spécifié avant la prochaine itération.
    }
}
