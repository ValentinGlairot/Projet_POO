stateDiagram-v2
    [*] --> Initialisation
    Initialisation: Charger l'état initial depuis un fichier
    Initialisation --> ChargerGrille
    ChargerGrille: Générer la grille et les cellules
    ChargerGrille --> ChoixMode
    ChoixMode: Choisir entre mode console et mode graphique

    ChoixMode --> ModeConsole : "Mode console"
    ChoixMode --> ModeGraphique : "Mode graphique"

    ModeConsole --> IterationConsole
    IterationConsole: Calculer les nouvelles cellules selon les règles
    IterationConsole --> SauvegardeEtat
    SauvegardeEtat: Sauvegarder l'état de la grille dans un fichier
    SauvegardeEtat --> ConditionFin : Vérifier les conditions de fin
    ConditionFin --> IterationConsole : "L'automate évolue encore"
    ConditionFin --> [*] : "Fin de l'exécution"

    ModeGraphique --> AfficherGrille
    AfficherGrille: Afficher la grille dans la fenêtre graphique
    AfficherGrille --> IterationGraphique
    IterationGraphique: Calculer les nouvelles cellules selon les règles
    IterationGraphique --> MiseAJourAffichage
    MiseAJourAffichage: Mettre à jour l'affichage des cellules
    MiseAJourAffichage --> ConditionFinGraphique : Vérifier les conditions de fin
    ConditionFinGraphique --> IterationGraphique : "L'automate évolue encore"
    ConditionFinGraphique --> [*] : "Fin de l'exécution"
