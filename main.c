/*
   PROGRAMME            : Gestion des type_emplacement
   Auteur               : TCHINDOU Felicien ; COMADAN Kokou Ilénin Jacques
   Objet                : Implémente les fonctions pour ajouter, modifier, supprimer, 
                          consulter et lister les type_emplacement dans un fichier texte.
   Date de création     :  07/12/2025
   Date de modification :  15/12/2025
 */
#include <stdio.h>
#include "type_emplacement.h"

int main() {
    int choix;
    char continuer;
    int programme_termine = 0;
    
    printf("========================================\n");
    printf("   GESTION DES TYPES D'EMPLACEMENT\n");
    printf("========================================\n");
    
    while (!programme_termine) {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Ajouter un type d'emplacement\n");
        printf("2. Modifier un type d'emplacement\n");
        printf("3. Supprimer un type d'emplacement\n");
        printf("4. Consulter un type d'emplacement\n");
        printf("5. Lister tous les types d'emplacement\n");
        printf("6. Quitter\n");
        printf("Votre choix : ");
        
        scanf("%d", &choix);
        viderBuffer();
        
       switch(choix) {
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
            case 6:
                printf("\nAu revoir !\n");
                programme_termine = 1;
                continue; // On utilise continue pour éviter la question "continuer ?"
            default:
                printf("\n ERREUR : Choix invalide ! Veuillez choisir entre 1 et 6.\n");
        }
        
        if (!programme_termine) {
            printf("\nVoulez-vous continuer ? (o/n) : ");
            scanf(" %c", &continuer);
            viderBuffer();
            
            if (continuer == 'n' || continuer == 'N') {
                programme_termine = 1;
                printf("\nAu revoir !\n");
            }
        }
    }
    
    return 0;
}