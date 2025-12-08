/*
   PROGRAMME : Gestion des type_emplacement
   Auteur   : TCHINDOU Felicien ;COMADAN Kokou Ilénin Jacques
   Objet    : Implémente les fonctions pour ajouter, modifier, supprimer,
              consulter et lister les type_emplacement dans un fichier texte.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "type_emplacement.h"

// Variable globale permettant de stocker temporairement
// un type_emplacement pendant la lecture.

struct typeEmplacement TE;


//VERIFICATION ID

int verification(int id) {
    FILE *pf = fopen("type_emplacement.txt", "r");
    if (pf == NULL) {
        return -1; // Fichier encore vide -> aucun ID n'existe
    }

    while (fscanf(pf, "%d %f %49s",
                  &TE.idTypeEmplacement, &TE.tarifJour, TE.libelle) != EOF) {

        if (TE.idTypeEmplacement == id) {
            fclose(pf);
            return 1;
        }
    }

    fclose(pf);
    return -1;
}



//AJOUTER UN TYPE_EMPLACEMENT

void ajouterTypeEmplacement() {
    int idTypeEmplacement, verif;

    printf("\n==================================\n");
    printf("   AJOUT DE TYPE_EMPLACEMENT\n");
    printf("==================================\n");

    do {
        printf("\nEntrer l'id du type_emplacement : ");
        scanf("%d", &idTypeEmplacement);

        verif = verification(idTypeEmplacement);

        if (verif == 1) {
            printf(" Cet id de type_emplacement existe deja. Saisissez un autre.\n");
        }
    } while (verif == 1);

    TE.idTypeEmplacement = idTypeEmplacement;

    printf("Entrer le libelle(caravanne ,tente,camping-car,bungalow) : ");
    scanf("%49s", TE.libelle);

    printf("Entrer le tarif journalier : ");
    scanf("%f", &TE.tarifJour);

    FILE *pf = fopen("type_emplacement.txt", "a");
    if (pf == NULL) {
        printf("Erreur ouverture fichier.\n");
        return;
    }

    fprintf(pf, "%d %.2f %s\n", TE.idTypeEmplacement, TE.tarifJour, TE.libelle);
    fclose(pf);

    printf("\n Type_emplacement ajoute avec succes.\n");
}

//MODIFIER UN TYPE_EMPLACEMENT

modifierTypeEmplacement() {
    int idTypeEmplacement, verif;

    printf("\n=======================================\n");
    printf("  MODIFICATION TYPE_EMPLACEMENT\n");
    printf("=======================================\n");

    do {
        printf("\nEntrer l'id du type_emplacement a modifier : ");
        scanf("%d", &idTypeEmplacement);

        verif = verification(idTypeEmplacement);

        if (verif == -1) {
            printf(" Cet id type_emplacement n'existe pas.\n");
        }

    } while (verif == -1);

    FILE *pf = fopen("type_emplacement.txt", "r");
    FILE *temp = fopen("temporaire.txt", "w");

    while (fscanf(pf, "%d %f %49s",
                  &TE.idTypeEmplacement, &TE.tarifJour, TE.libelle) != EOF) {

        if (TE.idTypeEmplacement == idTypeEmplacement) {
            printf("\nEntrer le nouveau tarif : ");
            scanf("%f", &TE.tarifJour);

            printf("Entrer le nouveau libelle : ");
            scanf("%49s", TE.libelle);
        }

        fprintf(temp, "%d %.2f %s\n",
                TE.idTypeEmplacement, TE.tarifJour, TE.libelle);
    }

    fclose(pf);
    fclose(temp);

    remove("type_emplacement.txt");
    rename("temporaire.txt", "type_emplacement.txt");

    printf("\n Modification effectuee.\n");
}

//SUPPRIMER UN TYPE_EMPLACEMENT

void supprimerTypeEmplacement() {
    int idTypeEmplacement, verif;

    printf("\n======================================\n");
    printf("    SUPPRESSION TYPE_EMPLACEMENT\n");
    printf("======================================\n");

    do {
        printf("\nEntrer l'id du type_emplacement a supprimer : ");
        scanf("%d", &idTypeEmplacement);

        verif = verification(idTypeEmplacement);

        if (verif == -1) {
            printf(" Cet id type_emplacement n'existe pas.\n");
        }

    } while (verif == -1);

    FILE *pf = fopen("type_emplacement.txt", "r");
    FILE *temp = fopen("temporaire.txt", "w");

    while (fscanf(pf, "%d %f %49s",
                  &TE.idTypeEmplacement, &TE.tarifJour, TE.libelle) != EOF) {

        if (TE.idTypeEmplacement != idTypeEmplacement) {
            fprintf(temp, "%d %.2f %s\n",
                    TE.idTypeEmplacement, TE.tarifJour, TE.libelle);
        }
    }

    fclose(pf);
    fclose(temp);

    remove("type_emplacement.txt");
    rename("temporaire.txt", "type_emplacement.txt");

    printf("\n Suppression effectuee.\n");
}


//CONSULTER UN TYPE EMPLACEMENT

void consulterTypeEmplacement() {
    int idTypeEmplacement, verif;

    printf("\n=======================================\n");
    printf("          CONSULTATION TYPE_EMPLACEMENT\n");
    printf("=======================================\n");

    do {
        printf("\nEntrer l'id du type_emplacement : ");
        scanf("%d", &idTypeEmplacement);

        verif = verification(idTypeEmplacement);

        if (verif == -1) {
            printf(" Cet id type_emplacement n'existe pas.\n");
        }

    } while (verif == -1);

    FILE *pf = fopen("type_emplacement.txt", "r");

    while (fscanf(pf, "%d %f %49s",
                  &TE.idTypeEmplacement, &TE.tarifJour, TE.libelle) != EOF) {

        if (TE.idTypeEmplacement == idTypeEmplacement) {
            printf("\n********** INFO TYPE_EMPLACEMENT **********\n");
            printf("ID : %d\n", TE.idTypeEmplacement);
            printf("Tarif : %.2f\n", TE.tarifJour);
            printf("Libelle : %s\n", TE.libelle);
        }
    }

    fclose(pf);
}



//LISTER TOUS LES TYPES

void listerTypeEmplacement() {
    FILE *pf = fopen("type_emplacement.txt", "r");

    printf("\n==================================\n");
    printf("    LISTE DES TYPE_EMPLACEMENT\n");
    printf("==================================\n");

    while (fscanf(pf, "%d %f %49s",
                  &TE.idTypeEmplacement, &TE.tarifJour, TE.libelle) != EOF) {

        printf("\nID : %d | Libelle : %s | Tarif : %.2f",
               TE.idTypeEmplacement, TE.libelle, TE.tarifJour);
    }

    fclose(pf);
}
