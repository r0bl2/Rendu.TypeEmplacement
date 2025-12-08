#include <stdio.h>
#include <stdlib.h>
#include "type_emplacement.h"

/*
  Main : menu principal
  Permet d'appeler les operations de gestion de type_emplacement.
  Les fonctions sont definies dans type_emplacement.c.
 */

int main() {
    int choix;

    do {
        printf("\n==================================\n");
        printf("          MENU PRINCIPAL\n");
        printf("==================================\n");
        printf("1 - Ajouter un type_emplacement\n");
        printf("2 - Modifier un type_emplacement\n");
        printf("3 - Supprimer un type_emplacement\n");
        printf("4 - Consulter un type_emplacement\n");
        printf("5 - Lister les type_emplacement crees\n");
        printf("0 - Quitter\n");
        printf("Entrer votre choix : ");
        scanf("%d", &choix);

        switch (choix) {

            case 1:
                ajouterTypeEmplacement();
                break;

            case 2:
                modifierTypeEmplacement();
                break;

            case 3:
                supprimerTypeEmplacement();
                break;

            case 4:
                consulterTypeEmplacement();
                break;

            case 5:
                listerTypeEmplacement();
                break;

            case 0:
                printf("\nFermeture du programme...\n");
                break;

            default:
                printf("\nChoix invalide. Reessayer.\n");
        }

    } while (choix != 0);

    return 0;
}
