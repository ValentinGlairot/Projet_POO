#ifndef AFFICHAGE_CONSOLE_H
#define AFFICHAGE_CONSOLE_H

#include "Affichage.h"
#include <string>

// Classe pour l'affichage en console du jeu.
class AffichageConsole : public Affichage {
public:
    // Affiche la grille dans la console.
    void afficherGrille(const Grille& grille) override;

    // Démarre le mode console.
    void demarrerMode(Grille& grille, const std::string& nomFichierEntree = "") override;

private:
    // Sauvegarde la grille dans un fichier texte.
    void sauvegarderGrilleDansFichier(const Grille& grille, const std::string& repertoire, int iteration);
};

#endif // AFFICHAGE_CONSOLE_H
