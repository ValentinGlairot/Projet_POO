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
  - git clone https://github.com/ValentinGlairot/Projet_POO.git

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

5 5   \n
0 1 0 2 3 \n
1 0 1 0 0 \n
0 1 0 1 0 \n
2 0 0 1 3 \n
3 0 1 0 2 \n


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
   
    
# Documentation pour le Technicien


## Introduction

Ce projet est conçu en C++ avec une architecture modulaire et extensible, compatible avec la programmation orientée objet (OOP).

## Architecture

Répertoire du projet :

├── src/
│   ├── main.cpp                 # Entrée principale du programme \n
│   ├── Cellule.cpp              # Gestion des cellules \n
│   ├── Grille.cpp               # Manipulation et mise à jour de la grille \n
│   ├── JeuDeLaVieStrategie.cpp  # Implémentation des règles du jeu \n
│   ├── AffichageConsole.cpp     # Affichage terminal \n
│   ├── AffichageGraphique.cpp   # Affichage via SFML \n
├── include/ \n
│   ├── *.h                      # Interfaces et définitions des classes \n
├── assets/ \n
│   └── examples/                # Exemples de grilles \n
├── README.md                    # Documentation \n
└── Makefile                     # Automatisation de compilation \n


## Technologies

Langage : C++ (norme C++11 ou plus récente).

Bibliothèques :

  - Standard : <vector>, <iostream>, etc.
  - Graphique : SFML (Simple and Fast Multimedia Library).

## Compilation
  - Vérifiez que le compilateur prend en charge C++11 :
  - g++ --version

Compilez le projet avec le Makefile :
  - make

Exécutable généré : jeu_de_la_vie.

## Points Clés Techniques

Modularité

  - Classe Cellule : Définit les états et transitions d'une cellule.
  - Classe Grille : Centralise la logique de mise à jour selon les règles.

Affichage :
  - AffichageConsole pour l'interface textuelle.
  - AffichageGraphique pour l'interface SFML.

## Extensibilité

Stratégie de jeu :
  - Le fichier JeuDeLaVieStrategie.cpp peut être étendu pour intégrer de nouvelles règles.

Affichage :
  - Ajoutez de nouveaux modes (exemple : affichage web).

## Tests

Scénarios :
  - Grilles avec et sans obstacles.
  - Grilles aléatoires.
  - Automatisation : Créez des scripts pour valider les règles sur plusieurs itérations.

## Améliorations Futures

Optimisation :
  - Utiliser des structures de données plus efficaces pour la grille (e.g., sparse matrix).

Interface :
  -  Ajouter un menu interactif pour configurer la simulation.
Persistance :
  -  Permettre l'export des itérations en fichier (CSV, JSON).
