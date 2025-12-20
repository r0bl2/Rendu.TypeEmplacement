/*
    PROGRAMME : Gestion des types d'emplacement
    FICHIER   : main.c
    Auteurs   : COMADAN Kokou Ilenin Jacques ;
                TCHINDOU Essowazou Felicien
    Professeur: Mr AKAKPO

    Objet :
        - Programme principal
        - Affichage du menu principal
        - Appel des fonctions du module type_emplacement

    Date de création    : 08/12/2025
    Date de modification: 20/12/2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "type_emplacement.h"

int main(void) {

     setlocale(LC_ALL, "French");
    int choix;

    //Création du dossier 'data' si inexistant (Windows)
    system("mkdir data > nul 2>&1");

    // Chargement des données depuis le fichier texte
    chargerTypes();

    do {
        printf("\n===== MENU TYPE EMPLACEMENT =====\n");
        printf("1. Ajouter un type emplacement\n");
        printf("2. Modifier un type emplacement\n");
        printf("3. Supprimer un type emplacement\n");
        printf("4. Consulter un type emplacement\n");
        printf("5. Lister types emplacements enregistrés\n");
        printf("0. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: ajouterTypeEmplacement(); break;
            case 2: modifierTypeEmplacement(); break;
            case 3: supprimerTypeEmplacement(); break;
            case 4: consulterTypeEmplacement(); break;
            case 5: listerTypeEmplacement(); break;
            case 0: printf("Fin du programme.\n"); break;
            default: printf("Choix invalide.\n");
        }
    } while (choix != 0);

    return 0;
}
