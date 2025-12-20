# Rendu.TypeEmplacement
gestion des types emplacements
## Auteurs
- COMADAN Kokou Ilenin Jacques
- TCHINDOU Essowazou Felicien

## Professeur
- Mr AKAKPO

## Description
Ce projet en langage C permet de gérer différents types d'emplacement (ex : Tente, Chambre, etc.).  
Il propose un menu permettant de :

- Ajouter un type d'emplacement
- Modifier un type existant
- Supprimer un type
- Consulter un type précis
- Lister tous les types

Les données sont sauvegardées dans un fichier texte (`data/type_emplacement.txt`) pour persistance.

## Structure du projet

gestion-types-emplacement/
├── data/                      # Contient les fichiers texte des types d'emplacement
│   └── type_emplacement.txt   # Fichier généré contenant les types (initialement vide)
├── main.c                     # Programme principal, menu et appels des fonctions
├── type_emplacement.h         # Header avec la structure et les prototypes des fonctions
├── type_emplacement.c         # Implémentation des fonctions du module
├── .gitignore                 # Fichiers et dossiers à ignorer (bin/, debug/, data/, *.o, *.exe)
├── README.md                  # Ce fichier, avec description et instructions
└── Makefile (optionnel)       # Pour compiler facilement le projet avec make
