// main.c
// Menu principal pour gérer les types d'emplacements

#include "type_emplacement.h"  // Nouveau fichier d'en-tête
#include <locale.h>
#include <stdio.h>

int main() {
    // Active la locale française pour les accents
    setlocale(LC_ALL, "french");

    int choix;

    do {
        clear_screen();

        printf("\n==============================================\n");
        printf("     GESTION DES TYPES D'EMPLACEMENTS\n");
        printf("==============================================\n");
        printf("1 - Ajouter un type d'emplacement\n");
        printf("2 - Modifier un type d'emplacement\n");
        printf("3 - Supprimer un type d'emplacement\n");
        printf("4 - Consulter un type d'emplacement\n");
        printf("5 - Lister tous les types d'emplacements\n");
        printf("0 - Quitter\n");
        printf("Votre choix : ");

        scanf("%d", &choix);
        getchar(); // Pour consommer le '\n' qui reste

        switch(choix) {
            case 1:
                ajouter_mat_type_emplacement();
                break;

            case 2:
                modifier_mat_type_emplacement();
                break;

            case 3:
                supprimer_mat_type_emplacement();
                break;

            case 4:
                consulter_mat_type_emplacement();
                break;

            case 5:
                lister_mat_type_emplacements();
                break;

            case 0:
                printf("\nMerci d'avoir utilisé le programme !\n");
                break;

            default:
                printf("\nChoix invalide ! Essayez encore.\n");
                pause_ecran();
                break;
        }

    } while (choix != 0);

    return 0;
}
