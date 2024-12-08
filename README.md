# Documentation pour l'Utilisateur Final


## Introduction

Le Jeu de la Vie est une simulation interactive basée sur les règles de John Conway. Grâce à une interface console ou graphique, les utilisateurs peuvent observer l'évolution d'une grille contenant des cellules classiques et des obstacles.

## Prérequis


Un système d'exploitation compatible :
  - Windows, Linux, ou macOS.

SFML pour l'affichage graphique :

  - Linux : sudo apt-get install libsfml-dev
  - macOS : brew install sfml
  - Windows : Télécharger SFML depuis le site officiel.

## Installation

Cloner le dépôt GitHub :
  - git clone [https://github.com/ValentinGlairot/Projet_POO.git](https://github.com/ValentinGlairot/Projet_POO/tree/CODE_FINAL)

Accéder au répertoire du projet :
  - cd Projet_POO

Compiler avec le Makefile :
  - make

    
## Utilisation

Exécuter le programme avec un fichier de configuration :

  - ./jeu_de_la_vie <chemin_vers_fichier>

Exemple :

  - ./jeu_de_la_vie assets/examples/grille.txt


Choisir le mode d'affichage :

  - 1 pour le mode console.
  - 2 pour le mode graphique.

## Format des fichiers de configuration

Un fichier de grille doit respecter cette structure :

  - Première ligne : dimensions de la grille (largeur et hauteur).
  - Lignes suivantes : états des cellules (0, 1, 2, ou 3).

Exemple :

5 5   <br>
0 1 0 2 3 <br>
1 0 1 0 0 <br>
0 1 0 1 0 <br>
2 0 0 1 3 <br>
3 0 1 0 2 <br>


## Modes d'affichage

  - Mode Console
    - Cellules vivantes : O
    - Cellules mortes : .
    - Obstacles vivants : X
    - Obstacles morts : #
    
  - Mode Graphique
    - Cellules vivantes : blanc
    - Cellules mortes : noir
    - Obstacles vivants : rouge
    - Obstacles morts : gris

# Documentation Technicien 
    
Architecture du Code

Structure du Projet

Projet_POO/

├── src/
│   ├── main.cpp                 # Point d'entrée <br>
│   ├── Cellule.cpp              # Implémentation de la classe Cellule <br>
│   ├── Grille.cpp               # Gestion des cellules et règles du jeu <br>
│   ├── JeuDeLaVieStrategie.cpp  # Stratégie de mise à jour des cellules <br>
│   ├── AffichageConsole.cpp     # Affichage terminal <br>
│   ├── AffichageGraphique.cpp   # Affichage SFML <br>
│   └── Utils.cpp                # Fonctions utilitaires (facultatif) <br>
├── include/ <br>
│   ├── Cellule.h                # Définition de la classe Cellule <br>
│   ├── Grille.h                 # Définition de la classe Grille <br>
│   ├── JeuDeLaVieStrategie.h    # Interface pour les stratégies <br>
│   ├── AffichageConsole.h       # Interface pour l'affichage console <br>
│   ├── AffichageGraphique.h     # Interface pour l'affichage graphique <br>
│   └── Utils.h                  # Déclarations des fonctions utilitaires <br>
├── assets/ <br>
│   └── examples/                # Exemples de fichiers de configuration <br>
├── Makefile                     # Automatisation de la compilation <br>
└── README.md                    # Documentation utilisateur <br>


## Principales Classes

### 1. Cellule
  - Rôle : Représente une cellule individuelle.

Attributs :
  - etat : État de la cellule (0, 1, 2, 3).
  - estObstacle : Booléen indiquant si la cellule est un obstacle.

Méthodes principales :
  - void changerEtat(int nouvelEtat) : Modifie l'état si la cellule n'est pas un obstacle.
  - bool estVivante() : Vérifie si la cellule est vivante.
  - bool estMorte() : Vérifie si la cellule est morte.

### 3. Grille

Rôle : Gère l'ensemble des cellules et applique les règles du jeu.

Attributs :
  - std::vector<std::vector<Cellule>> cellules : Grille bidimensionnelle.
  - int largeur, hauteur : Dimensions de la grille.

Méthodes principales :
  - void chargerDepuisFichier(const std::string& fichier) :
  - Charge une grille depuis un fichier d'entrée.
  - void mettreAJour(JeuDeLaVieStrategie& strategie) :
  - Applique les règles à chaque cellule.
  - void afficher() :
  - Affiche la grille actuelle (console).

### 4. JeuDeLaVieStrategie

Rôle : Implémente les règles du Jeu de la Vie.

Méthodes :
  - int calculerNouvelEtat(const Cellule& cellule, const Grille& grille) :
  - Retourne le nouvel état d'une cellule en fonction des voisins.

### 5. Affichages (AffichageConsole et AffichageGraphique)

Rôle : Fournit les modes d'affichage.

Attributs :
  - Console : Simple affichage textuel.
  - Graphique : Utilisation de la bibliothèque SFML pour l'interface utilisateur.

Méthodes principales :
  - void afficher(const Grille& grille) :
  - Rend visuellement la grille dans le mode respectif.
  - Principes de Conception

### 1. Programmation Orientée Objet (OOP)
  - Encapsulation : Les classes Cellule et Grille cachent leurs détails d'implémentation.
  - Responsabilité unique : Chaque classe a une fonction bien définie :
  - Cellule : Gère l'état individuel.
  - Grille : Applique les règles sur l'ensemble des cellules.
  - Affichages : Responsable uniquement de la représentation.

### 2. Modularité
  - Les composants (affichage, logique des règles, gestion de grille) sont indépendants.
  - Facilite la maintenance et l'ajout de nouvelles fonctionnalités.

## 3. Extensibilité

Ajout de nouvelles règles :
  - Implémenter une nouvelle classe héritant de JeuDeLaVieStrategie.
Nouveaux modes d'affichage :
  - Ajouter une classe implémentant une interface similaire à AffichageConsole ou AffichageGraphique.

## Exécution Technique

Compilation

Le projet utilise un Makefile. Les options peuvent être ajustées pour inclure des dépendances ou des flags supplémentaires.


Compilation :
- make

Exécution avec fichier d'entrée :
- ./jeu_de_la_vie assets/examples/grille.txt

Étapes de Mise à Jour

### 1. Mise à Jour Partielle de la Grille

  - Actuellement, la grille entière est recalculée à chaque itération. Une optimisation pourrait inclure :
  - Un suivi des cellules modifiées pour limiter le recalcul.
  - Utilisation d'une structure de données plus performante (e.g., std::unordered_set pour gérer les cellules actives).

### 2. Ajout de Nouvelles Règles

Créer une nouvelle stratégie héritant de JeuDeLaVieStrategie :

class NouvelleRegleStrategie : public JeuDeLaVieStrategie {
public:
    int calculerNouvelEtat(const Cellule& cellule, const Grille& grille) override {
        // Implémentez ici vos nouvelles règles.
    }
};


### 3. Support d’autres Formats de Fichiers

Ajouter un module pour lire des formats comme JSON ou CSV.*

Dépannage et Debugging

## Mauvais affichage graphique :

  - Vérifiez la configuration de SFML, en particulier les chemins vers les bibliothèques et les dépendances dynamiques.
  - Améliorations Techniques Futures

## Interface :
  -  Ajouter un menu interactif pour configurer la simulation.
    
## Persistance :
  -  Permettre l'export des itérations en fichier (CSV, JSON).
