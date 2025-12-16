/*
   PROGRAMME            : Gestion des type_emplacement
   Auteur               : TCHINDOU Felicien ; COMADAN Kokou Ilénin Jacques
   Objet                : Implémente les fonctions pour ajouter, modifier, supprimer, 
                          consulter et lister les type_emplacement dans un fichier texte.
   Date de création     :  07/12/2025
   Date de modification :  15/12/2025
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "type_emplacement.h"

// Variable globale temporaire
TypeEmplacement TE;

// ============================================
// FONCTION : viderBuffer
// ============================================
void viderBuffer() 
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// ============================================
// FONCTION : verification
// ============================================
int verification(int numero_type) 
{
    FILE *pf = fopen("type_emplacement.txt", "r");
    int resultat = -1;
    
    if (pf == NULL) {
        return -1; // Fichier encore vide -> aucun numéro n'existe
    }

    while (fscanf(pf, "%d %s %f %f %d %[^\n]",
                  &TE.numero_type, 
                  TE.nom, 
                  &TE.prix_jour_personne, 
                  &TE.surface_moyenne, 
                  &TE.capacite_max_personnes, 
                  TE.description) != EOF) {
        if (TE.numero_type == numero_type) {
            resultat = 1;
        }
    }

    fclose(pf);
    return resultat;
}

// ============================================
// FONCTION : saisirNumeroType
// mode = 0 : pour ajout (le numéro ne doit pas exister)
// mode = 1 : pour modif/supp/consult (le numéro doit exister)
// ============================================
int saisirNumeroType(int mode) 
{
    int numero;
    int verif;
    int numero_valide = 0;
    
    while (!numero_valide) {
        printf("\nEntrer le numero du type d'emplacement : ");
        if (scanf("%d", &numero) != 1) {
            printf(" ERREUR : Saisie invalide. Veuillez entrer un nombre.\n");
            viderBuffer();
            continue;
        }
        viderBuffer();
        
        verif = verification(numero);
        
        if (mode == 0) {
            // Mode ajout : le numéro ne doit pas exister
            if (verif == 1) {
                printf(" ERREUR : Ce numero de type existe deja. Saisissez un autre.\n");
            } else {
                numero_valide = 1;
            }
        } else {
            // Mode modification/suppression/consultation : le numéro doit exister
            if (verif == -1) {
                printf(" ERREUR : Ce numero de type n'existe pas.\n");
                printf("   Voulez-vous :\n");
                printf("   1. Saisir un autre numero\n");
                printf("   2. Voir la liste des numeros existants\n");
                printf("   3. Annuler\n");
                printf("   Votre choix : ");
                
                char choix;
                scanf(" %c", &choix);
                viderBuffer();
                
                if (choix == '2') {
                    FILE *pf = fopen("type_emplacement.txt", "r");
                    if (pf) {
                        printf("\n   LISTE DES NUMEROS EXISTANTS : ");
                        while (fscanf(pf, "%d %s %f %f %d %[^\n]",
                                      &TE.numero_type, TE.nom, 
                                      &TE.prix_jour_personne, &TE.surface_moyenne,
                                      &TE.capacite_max_personnes, TE.description) != EOF) {
                            printf("%d ", TE.numero_type);
                        }
                        printf("\n");
                        fclose(pf);
                    }
                } else if (choix == '3') {
                    return -1; // Annulation
                }
            } else {
                numero_valide = 1;
            }
        }
    }
    return numero;
}


/* FONCTION : saisirCaracteristiques
estModification = 0 : pour ajout (pas d'affichage anciennes valeurs)
estModification = 1 : pour modification (affichage anciennes valeurs)
*/
void saisirCaracteristiques(TypeEmplacement *te, int estModification) 
{
    if (te == NULL) return;
    
    // Saisie du nom
    if (estModification) {
        printf("   Ancien nom: %s\n", te->nom);
    }
    printf("   Entrer le nom du type (ex: Tente, Caravane, Bungalow) : ");
    fgets(te->nom, TAILLE_NOM, stdin);
    te->nom[strcspn(te->nom, "\n")] = '\0';

    // Saisie du prix par jour et par personne
    if (estModification) {
        printf("   Ancien prix: %.2f euros/jour/personne\n", te->prix_jour_personne);
    }
    
    int prix_valide = 0;
    while (!prix_valide) {
        printf("   Entrer le prix par jour et par personne (en euros) : ");
        if (scanf("%f", &te->prix_jour_personne) != 1) {
            printf("     ERREUR : Saisie invalide. Veuillez entrer un nombre.\n");
            viderBuffer();
        } else if (te->prix_jour_personne <= 0) {
            printf("     ERREUR : Le prix doit être positif.\n");
            viderBuffer();
        } else {
            prix_valide = 1;
            viderBuffer();
        }
    }

    // Saisie de la surface moyenne
    if (estModification) {
        printf("   Ancienne surface: %.2f m2\n", te->surface_moyenne);
    }
    
    int surface_valide = 0;
    while (!surface_valide) {
        printf("   Entrer la surface moyenne (en m2) : ");
        if (scanf("%f", &te->surface_moyenne) != 1) {
            printf("     ERREUR : Saisie invalide. Veuillez entrer un nombre.\n");
            viderBuffer();
        } else if (te->surface_moyenne <= 0) {
            printf("     ERREUR : La surface doit être positive.\n");
            viderBuffer();
        } else {
            surface_valide = 1;
            viderBuffer();
        }
    }

    // Saisie de la capacité maximale
    if (estModification) {
        printf("   Ancienne capacite: %d personnes\n", te->capacite_max_personnes);
    }
    
    int capacite_valide = 0;
    while (!capacite_valide) {
        printf("   Entrer la capacite maximale de personnes : ");
        if (scanf("%d", &te->capacite_max_personnes) != 1) {
            printf("     ERREUR : Saisie invalide. Veuillez entrer un nombre entier.\n");
            viderBuffer();
        } else if (te->capacite_max_personnes <= 0) {
            printf("     ERREUR : La capacité doit être positive.\n");
            viderBuffer();
        } else {
            capacite_valide = 1;
            viderBuffer();
        }
    }

    // Saisie de la description
    if (estModification) {
        printf("   Ancienne description: %s\n", te->description);
    }
    printf("   Entrer la description : ");
    fgets(te->description, TAILLE_DESCRIPTION, stdin);
    te->description[strcspn(te->description, "\n")] = '\0';
}


// FONCTION : afficherTypeEmplacement

void afficherTypeEmplacement(const TypeEmplacement *te) 
{
    if (te == NULL) return;
    
    printf("\n===================================================\n");
    printf("          FICHE TYPE D'EMPLACEMENT\n");
    printf("===================================================\n");
    printf(" Numero              : %d\n", te->numero_type);
    printf(" Nom                 : %s\n", te->nom);
    printf(" Prix/jour/personne  : %.2f euros\n", te->prix_jour_personne);
    printf(" Surface moyenne     : %.2f m2\n", te->surface_moyenne);
    printf(" Capacite max        : %d personnes\n", te->capacite_max_personnes);
    printf(" Description         : %s\n", te->description);
    printf("===================================================\n");
}


// FONCTION : ajouterTypeEmplacement

void ajouterTypeEmplacement() 
{
    printf("\n==================================\n");
    printf("   AJOUT DE TYPE D'EMPLACEMENT\n");
    printf("==================================\n");

    // Saisie et vérification du numéro
    int numero = saisirNumeroType(0);
    if (numero == -1) {
        printf("\n AJOUT ANNULE.\n");
        return;
    }
    
    TE.numero_type = numero;
    
    // Saisie des caractéristiques (mode ajout = 0)
    printf("\n--- Saisie des caracteristiques ---\n");
    saisirCaracteristiques(&TE, 0);

    // Écriture dans le fichier
    FILE *pf = fopen("type_emplacement.txt", "a");
    if (pf == NULL) {
        printf(" ERREUR : Impossible d'ouvrir le fichier.\n");
        return;
    }

    fprintf(pf, "%d %s %.2f %.2f %d %s\n", 
            TE.numero_type, 
            TE.nom, 
            TE.prix_jour_personne, 
            TE.surface_moyenne, 
            TE.capacite_max_personnes, 
            TE.description);
    
    fclose(pf);

    printf("\n SUCCES : Type d'emplacement ajoute avec succes !\n");
    printf(" RESUME :\n");
    afficherTypeEmplacement(&TE);
}


// FONCTION : modifierTypeEmplacement

void modifierTypeEmplacement() 
{
    printf("\n=======================================\n");
    printf("  MODIFICATION TYPE D'EMPLACEMENT\n");
    printf("=======================================\n");

    // Saisie et vérification du numéro
    int numero_type = saisirNumeroType(1);
    if (numero_type == -1) {
        printf("\n MODIFICATION ANNULEE.\n");
        return;
    }

    FILE *pf = fopen("type_emplacement.txt", "r");
    FILE *temp = fopen("temporaire.txt", "w");

    if (pf == NULL || temp == NULL) {
        printf(" ERREUR : Impossible d'ouvrir les fichiers.\n");
        if (pf) fclose(pf);
        if (temp) fclose(temp);
        return;
    }

    int trouve = 0;
    while (fscanf(pf, "%d %s %f %f %d %[^\n]",
                  &TE.numero_type, 
                  TE.nom, 
                  &TE.prix_jour_personne, 
                  &TE.surface_moyenne, 
                  &TE.capacite_max_personnes, 
                  TE.description) != EOF) {

        if (TE.numero_type == numero_type) {
            trouve = 1;
            printf("\n--- Modification du type numero %d ---\n", numero_type);
            
            // Saisie des nouvelles caractéristiques (mode modification = 1)
            saisirCaracteristiques(&TE, 1);
        }

        fprintf(temp, "%d %s %.2f %.2f %d %s\n", 
                TE.numero_type, 
                TE.nom, 
                TE.prix_jour_personne, 
                TE.surface_moyenne, 
                TE.capacite_max_personnes, 
                TE.description);
    }

    fclose(pf);
    fclose(temp);

    if (!trouve) {
        printf(" ERREUR : Type numero %d non trouve.\n", numero_type);
        remove("temporaire.txt");
        return;
    }

    // Remplacement des fichiers
    remove("type_emplacement.txt");
    rename("temporaire.txt", "type_emplacement.txt");

    printf("\n SUCCES : Modification effectuee avec succes !\n");
}


// FONCTION : supprimerTypeEmplacement

void supprimerTypeEmplacement() 
{
    printf("\n======================================\n");
    printf("    SUPPRESSION TYPE D'EMPLACEMENT\n");
    printf("======================================\n");

    // Saisie et vérification du numéro
    int numero_type = saisirNumeroType(1);
    if (numero_type == -1) {
        printf("\n SUPPRESSION ANNULEE.\n");
        return;
    }

    // Lecture pour afficher ce qu'on va supprimer
    int trouve_lecture = 0;
    FILE *pf_lecture = fopen("type_emplacement.txt", "r");
    if (pf_lecture) {
        while (fscanf(pf_lecture, "%d %s %f %f %d %[^\n]",
                      &TE.numero_type, TE.nom, 
                      &TE.prix_jour_personne, &TE.surface_moyenne,
                      &TE.capacite_max_personnes, TE.description) != EOF) {
            if (TE.numero_type == numero_type) {
                trouve_lecture = 1;
                printf("\n ATTENTION : Vous allez supprimer ce type d'emplacement :\n");
                afficherTypeEmplacement(&TE);
            }
        }
        fclose(pf_lecture);
    }

    // Confirmation
    char confirmation;
    printf("\n ATTENTION : Etes-vous sur de vouloir supprimer le type numero %d ? (o/n) : ", 
           numero_type);
    scanf(" %c", &confirmation);
    viderBuffer();
    
    if (confirmation != 'o' && confirmation != 'O') {
        printf(" SUPPRESSION ANNULEE.\n");
        return;
    }

    FILE *pf = fopen("type_emplacement.txt", "r");
    FILE *temp = fopen("temporaire.txt", "w");

    if (pf == NULL || temp == NULL) {
        printf(" ERREUR : Impossible d'ouvrir les fichiers.\n");
        if (pf) fclose(pf);
        if (temp) fclose(temp);
        return;
    }

    int trouve = 0;
    while (fscanf(pf, "%d %s %f %f %d %[^\n]",
                  &TE.numero_type, 
                  TE.nom, 
                  &TE.prix_jour_personne, 
                  &TE.surface_moyenne, 
                  &TE.capacite_max_personnes, 
                  TE.description) != EOF) {

        if (TE.numero_type != numero_type) {
            fprintf(temp, "%d %s %.2f %.2f %d %s\n", 
                    TE.numero_type, 
                    TE.nom, 
                    TE.prix_jour_personne, 
                    TE.surface_moyenne, 
                    TE.capacite_max_personnes, 
                    TE.description);
        } else {
            trouve = 1;
        }
    }

    fclose(pf);
    fclose(temp);

    if (!trouve) {
        printf(" ERREUR : Type numero %d non trouve dans le fichier.\n", numero_type);
        remove("temporaire.txt");
        return;
    }

    // Remplacement des fichiers
    remove("type_emplacement.txt");
    rename("temporaire.txt", "type_emplacement.txt");

    printf("\n SUCCES : Suppression effectuee pour le numero %d.\n", numero_type);
}


// FONCTION : consulterTypeEmplacement

void consulterTypeEmplacement() 
{
    printf("\n=======================================\n");
    printf("          CONSULTATION TYPE D'EMPLACEMENT\n");
    printf("=======================================\n");

    // Saisie et vérification du numéro
    int numero_type = saisirNumeroType(1);
    if (numero_type == -1) {
        printf("\n CONSULTATION ANNULEE.\n");
        return;
    }

    FILE *pf = fopen("type_emplacement.txt", "r");
    if (pf == NULL) {
        printf(" ERREUR : Aucun type d'emplacement enregistre.\n");
        return;
    }

    int trouve = 0;
    while (fscanf(pf, "%d %s %f %f %d %[^\n]",
                  &TE.numero_type, 
                  TE.nom, 
                  &TE.prix_jour_personne, 
                  &TE.surface_moyenne, 
                  &TE.capacite_max_personnes, 
                  TE.description) != EOF) {

        if (TE.numero_type == numero_type) {
            afficherTypeEmplacement(&TE);
            trouve = 1;
        }
    }

    fclose(pf);

    if (!trouve) {
        printf(" ERREUR : Type d'emplacement non trouve.\n");
    }
}


// FONCTION : listerTypeEmplacement

void listerTypeEmplacement() 
{
    FILE *pf = fopen("type_emplacement.txt", "r");

    printf("\n==================================\n");
    printf("    LISTE DES TYPES D'EMPLACEMENT\n");
    printf("==================================\n");

    if (pf == NULL) {
        printf(" AUCUN : Aucun type d'emplacement enregistre.\n");
        return;
    }

    int compte = 0;
    // En-tête simplifié sans description pour l'affichage tabulaire
    printf("\n+-----+--------------------+-------------+---------+------+\n");
    printf("| N°  | Nom                | Prix/pers   | Surface | Cap. |\n");
    printf("+-----+--------------------+-------------+---------+------+\n");
    
    while (fscanf(pf, "%d %s %f %f %d %[^\n]",
                  &TE.numero_type, 
                  TE.nom, 
                  &TE.prix_jour_personne, 
                  &TE.surface_moyenne, 
                  &TE.capacite_max_personnes, 
                  TE.description) != EOF) {
        
        printf("| %-3d | %-18s | %9.2f € | %6.1f | %-4d |\n",
               TE.numero_type, 
               TE.nom, 
               TE.prix_jour_personne, 
               TE.surface_moyenne, 
               TE.capacite_max_personnes);
        compte++;
    }
    
    printf("+-----+--------------------+-------------+---------+------+\n");
    fclose(pf);
    
    if (compte == 0) {
        printf(" AUCUN : Aucun enregistrement trouve.\n");
    } else {
        printf("\n TOTAL : %d type(s) d'emplacement\n", compte);
        printf("\n NOTE : Pour voir les descriptions completes, utilisez la fonction 'Consulter'\n");
    }
}