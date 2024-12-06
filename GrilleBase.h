#ifndef GRILLE_BASE_H
#define GRILLE_BASE_H

#include <vector>
#include <string>
#include "Cellule.h"

// Classe de base pour la grille (permet l'héritage).
class GrilleBase {
public:
    virtual ~GrilleBase() {}
    virtual void initialiserDepuisFichier(const std::string& nomFichier) = 0;
    virtual void mettreAJour() = 0;
    virtual const std::vector<std::vector<Cellule>>& obtenirCellules() const = 0;
};

#endif
