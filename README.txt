Jeu de la Vie - Simulation avec Obstacles

------------------------------------------------


Description

------------------------------------------------


Ce projet implémente une version enrichie du célèbre Jeu de la Vie de John Conway, avec des fonctionnalités supplémentaires :
- Simulation des cellules classiques (vivantes ou mortes) suivant les règles traditionnelles.
- Ajout de cellules obstacles qui peuvent être vivantes ou mortes, mais dont l'état est immuable.


Deux modes d'affichage :
- Console : Représentation textuelle de la grille.
- Graphique : Visualisation interactive via SFML.


Ce projet a été conçu dans un cadre académique et suit les standards de programmation pour garantir une lisibilité et une modularité optimales.

------------------------------------------------------------------------------------------------------------------------------------------------------- 


Fonctionnalités principales


Simulation du Jeu de la Vie :
- Chaque cellule classique suit les règles suivantes :
- Une cellule vivante avec 2 ou 3 voisins vivants reste vivante.
- Une cellule morte avec exactement 3 voisins vivants devient vivante.
     - Sinon, la cellule devient ou reste morte.

Les cellules obstacles ne changent jamais d'état.

Affichage en console :
- Les cellules classiques sont représentées par O (vivantes) ou . (mortes).
- Les obstacles sont représentés par X (vivants) ou # (morts).


Affichage graphique :
- Basé sur la bibliothèque SFML.
- Les cellules vivantes apparaissent en blanc, les mortes en noir, et les obstacles en rouge ou gris.


--------------------------------------------------------------------------------------------------------------------------------------


Structure du projet : 


├── src/
│   ├── main.cpp                 # Point d'entrée du programme
│   ├── Cellule.cpp              # Implémentation de la classe Cellule
│   ├── Grille.cpp               # Gestion de la grille et des règles du jeu
│   ├── JeuDeLaVieStrategie.cpp  # Stratégie de mise à jour des cellules
│   ├── AffichageConsole.cpp     # Affichage textuel dans le terminal
│   ├── AffichageGraphique.cpp   # Affichage graphique avec SFML
│   └── ...
├── include/
│   ├── Cellule.h                # Définition de la classe Cellule
│   ├── Grille.h                 # Définition de la classe Grille
│   ├── JeuDeLaVieStrategie.h    # Interface pour la stratégie de mise à jour
│   ├── AffichageConsole.h       # Interface pour l'affichage console
│   ├── AffichageGraphique.h     # Interface pour l'affichage graphique
│   └── ...
├── assets/
│   └── examples/                # Exemples de fichiers de configuration de grille
├── README.md                    # Documentation du projet
└── Makefile                     # Automatisation de la compilation


-----------------------------------------------------------------------------------------------------------------


Configuration des cellules et obstacles


Format du fichier d'entrée


Chaque fichier d'entrée doit suivre ce format :

- La première ligne spécifie la largeur et la hauteur de la grille.
- Les lignes suivantes représentent l'état de chaque cellule :
    - 0 : Cellule morte.
    - 1 : Cellule vivante.
    - 2 : Cellule obstacle morte.
    - 3 : Cellule obstacle vivante.


Exemple de fichier d'entrée (grille.txt) :



5 5
0 1 0 2 3
1 0 1 0 0
0 1 0 1 0
2 0 0 1 3
3 0 1 0 2


----------------------------------------------------------------------------------------------------------


Instructions pour exécuter le programme


Prérequis


Compilateur C++ (supportant C++11 ou supérieur)


SFML (pour le mode graphique) :
- Sur Linux : sudo apt-get install libsfml-dev
- Sur macOS : brew install sfml
- Sur Windows : Téléchargez et configurez la bibliothèque depuis SFML.


Compilation
- Utilisez le Makefile fourni pour compiler le projet :

make
- Cela génère un exécutable nommé jeu_de_la_vie.

Exécution
- ./jeu_de_la_vie <fichier_d_entree>

--------------------------------------------------------------------------------------------------------


Exemple avec le fichier grille.txt :

- ./jeu_de_la_vie assets/examples/grille.txt


Le programme vous demandera de choisir le mode d'affichage :

- 1 : Mode Console (affichage textuel dans le terminal).
- 2 : Mode Graphique (affichage interactif via SFML).


Exemple d'utilisation

Mode Console

Sortie typique dans le terminal :

Itération 1 :
. O . # X
O . O . .
. O . O .
# . . O X
X . O . #

Itération 2 :
. . O # X
. O . O .
O . O . .
# . . O X
X . O . #

--------------------------------------------------------------------------------------------------------------

Mode Graphique

- Les cellules mortes apparaissent en noir.
- Les cellules vivantes apparaissent en blanc.
- Les obstacles apparaissent en rouge (vivants) ou gris (morts).



---------------------------------------------------------------------------------------------------------------


Tests

Scénarios testés

- Petite grille sans obstacles (vérification des règles classiques).
- Grille avec obstacles immuables (obstacles bloquant la propagation).
- Grilles aléatoires (génération aléatoire de cellules et obstacles).


# Exemple
- generer_grille("grille_aleatoire.txt", 10, 10)

-------------------------------------------------------------------------------------------------------------


Organisation du code


Points clés


Modularité :
- Séparation des responsabilités (grille, cellules, affichage, logique).

Extensibilité :
- Ajout facile de nouvelles règles ou modes d'affichage.

Compatibilité multiplateforme :
- Gestion des répertoires adaptée à Windows et Linux/macOS.

Structure OOP (Programmation Orientée Objet)

- Classe Cellule : Représente l'état d'une cellule.
- Classe Grille : Gère les cellules et applique les règles.
- Classe AffichageConsole : Affiche la grille dans le terminal.
- Classe AffichageGraphique : Affiche la grille via SFML.

----------------------------------------------------------------------------------------------------------

Améliorations possibles

Interface utilisateur :
- Ajouter un menu pour charger ou configurer des grilles directement.
     - Options avancées :
            - Paramètres pour définir dynamiquement les règles du jeu.

Optimisation :
- Réduction de la complexité lors des mises à jour (par ex., mises à jour partielles).
