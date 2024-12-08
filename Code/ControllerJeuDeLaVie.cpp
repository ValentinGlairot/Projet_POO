#include "ControllerJeuDeLaVie.h"
#include "JeuDeLaVieStrategie.h"
#include "AffichageConsole.h"
#include "AffichageGraphique.h"

#include <iostream>
#include <stdexcept>

ControllerJeuDeLaVie::ControllerJeuDeLaVie(const std::string& nomFichier)
    : grille(0, 0), strategie(nullptr), affichage(nullptr)
{
    // Initialise la grille à partir du fichier
    grille.initialiserDepuisFichier(nomFichier);

    // Définit la stratégie du jeu de la vie.
    this->strategie = new JeuDeLaVieStrategie();
    grille.definirStrategie(this->strategie);
}

// Lance le contrôleur
void ControllerJeuDeLaVie::run() {
    try {
        this->choisirAffichage();
    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << "\n";
    }

    // Nettoyage
    if (this->affichage) delete this->affichage;
    if (this->strategie) delete this->strategie;
}

// Permet à l'utilisateur de choisir le mode d'affichage.
void ControllerJeuDeLaVie::choisirAffichage() {
    int choix;
    std::cout << "Choisissez un mode :\n";
    std::cout << "1. Mode Console\n";
    std::cout << "2. Mode Graphique\n";
    std::cout << "Entrez votre choix : ";
    std::cin >> choix;

    if (choix == 1) {
        this->modeConsole();
    } else if (choix == 2) {
        this->modeGraphique();
    } else {
        std::cout << "Choix invalide. Fin du programme.\n";
    }
}

void ControllerJeuDeLaVie::modeConsole() {
    this->affichage = new AffichageConsole();
    // On peut demander à l'utilisateur le nombre d'itérations, etc. directement via la vue console.
    // Le code suivant est déjà géré dans AffichageConsole::demarrerMode()
    this->affichage->demarrerMode(this->grille); 
}

void ControllerJeuDeLaVie::modeGraphique() {
    this->affichage = new AffichageGraphique();
    // De même pour le mode graphique, la logique (délai, boucle d’événement) est déjà dans la vue.
    this->affichage->demarrerMode(this->grille);
}

