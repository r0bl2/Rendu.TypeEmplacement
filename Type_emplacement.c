/*
    PROGRAMME : Gestion des types d'emplacement
    FICHIER   : type_emplacement.c
    Auteurs   : COMADAN Kokou Ilenin Jacques ;
                TCHINDOU Essowazou Felicien
    Professeur: Mr AKAKPO

    Objet :
        - Implementation des fonctions de gestion des types d'emplacement
        - Gestion du stockage des données en mémoire et dans un fichier texte
        - Encapsulation des données et fonctions internes au module

    Date de création    : 08/12/2025
    Date de modification : 20/12/2025
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "type_emplacement.h"

#define MAX_TYPES 100               // Nombre maximum de types
#define FICHIER "data/type_emplacement.txt" // Fichier de sauvegarde

//Données internes au module (non visibles à l'extérieur)
static TypeEmplacement types[MAX_TYPES];
static int nbTypes = 0;

// FONCTIONS INTERNES


static int chercherIndexParId(int id)
{
    for (int i = 0; i < nbTypes; i++) {
        if (types[i].idTypeEmplacement == id)
            return i;
    }
    return -1; // Retour -1 si non trouvé
}// Recherche d’un type par ID


static int saisirEntier(const char *message)
 {
    int valeur;
    printf("%s", message);
    scanf("%d", &valeur);
    return valeur;
}// Saisie sécurisée d’un entier


static float saisirFloat(const char *message)
{
    float valeur;
    printf("%s", message);
    scanf("%f", &valeur);
    return valeur;
}//Saisie sécurisée d’un float


static void saisirChaine(const char *message, char *chaine)
{
    printf("%s", message);
    scanf(" %[^\n]", chaine); // %[^\n] lit toute la ligne jusqu'au \n
}// Saisie d’une chaîne de caractères (jusqu’au retour à la ligne)


static void afficherType(const TypeEmplacement *te)
{
    printf("ID      : %d\n", te->idTypeEmplacement);
    printf("Libellé : %s\n", te->libelle);
    printf("Tarif   : %.2f Euro \n", te->tarifJour);
}//Affichage d’un type d’emplacement


static void supprimerParDecalage(int index)
 {
    for (int i = index; i < nbTypes - 1; i++) {
        types[i] = types[i + 1]; // Décalage des éléments
    }
    nbTypes--;
}// Décalage lors d’une suppression


static int espaceDisponible(void)
{
    return nbTypes < MAX_TYPES;
}//Vérification espace disponible


// GESTION DU FICHIER TEXTE

void chargerTypes(void)
{
    FILE *f = fopen(FICHIER, "r");
    /*
       fopen en mode "r" : ouvre le fichier en lecture.
       - Si le fichier n’existe pas, fopen retourne NULL.
    */
    if (!f) return; // Si fichier introuvable, on ne fait rien

    nbTypes = 0;

    /* fscanf lit chaque ligne : ID, Tarif, Libellé
       - %d : entier
       - %f : float
       - %[^\n] : chaîne jusqu’à la fin de ligne */
    while (fscanf(f, "%d %f %[^\n]",
                  &types[nbTypes].idTypeEmplacement,
                  &types[nbTypes].tarifJour,
                  types[nbTypes].libelle) == 3) {
        nbTypes++;
    }

    fclose(f); // Fermeture du fichier pour libérer la ressource
}  // Charger les données depuis le fichier texte


void sauvegarderTypes(void)
{
    FILE *f = fopen(FICHIER, "w");
    /*
       fopen en mode "w" : ouvre le fichier en écriture.
       - Crée le fichier s’il n’existe pas.
       - Écrase le contenu s’il existe.
    */
    if (!f) return;

    //fprintf écrit les données dans le fichier
    for (int i = 0; i < nbTypes; i++) {
        fprintf(f, "%d %.2f %s\n",
                types[i].idTypeEmplacement,
                types[i].tarifJour,
                types[i].libelle);
    }

    fclose(f); // Fermeture du fichier
} // Sauvegarder les données dans le fichier texte


//FONCTIONS PUBLIQUES


void ajouterTypeEmplacement(void)
{
    if (!espaceDisponible()) {
        printf("Stock plein.\n");
        return;
    }

    TypeEmplacement te;
    te.idTypeEmplacement = saisirEntier("ID du type-emplacement: ");

    if (chercherIndexParId(te.idTypeEmplacement) != -1) {
        printf("ID déjà existant.\n");
        return;
    }

    saisirChaine("Libellé( Tente,caravane,camping-car,bungalow) : ", te.libelle);
    te.tarifJour = saisirFloat("Tarif/jour : ");

    types[nbTypes++] = te;

    sauvegarderTypes(); // Sauvegarde automatique après ajout
    printf("Ajout réussi.\n");
}// Ajouter un type d’emplacement


void modifierTypeEmplacement(void)
{
    int id = saisirEntier("ID du type-emplacement à modifier : ");
    int index = chercherIndexParId(id);

    if (index == -1) {
        printf("Type introuvable.\n");
        return;
    }

    saisirChaine("Nouveau libellé : ", types[index].libelle);
    types[index].tarifJour = saisirFloat("Nouveau tarif : ");

    sauvegarderTypes(); // Sauvegarde après modification
    printf("Modification réussie.\n");
}//Modifier un type d’emplacement


void supprimerTypeEmplacement(void)
{
    int id = saisirEntier("ID du type-emplacement à supprimer : ");
    int index = chercherIndexParId(id);

    if (index == -1) {
        printf("Type introuvable.\n");
        return;
    }

    supprimerParDecalage(index);

    sauvegarderTypes(); // Sauvegarde après suppression
    printf("Suppression réussie.\n");
}// Supprimer un type d’emplacement


void consulterTypeEmplacement(void)
{
    int id = saisirEntier("ID du type-emplacement à consulter : ");
    int index = chercherIndexParId(id);

    if (index == -1) {
        printf("Type introuvable.\n");
        return;
    }

    afficherType(&types[index]);
}// Consulter un type d’emplacement


void listerTypeEmplacement(void)
{
    if (nbTypes == 0) {
        printf("Aucun type enregistré.\n");
        return;
    }

    for (int i = 0; i < nbTypes; i++) {
        printf("\n--- Type Emplacement enregistré %d ---\n", i + 1);
        afficherType(&types[i]);
    }
}// Lister tous les types d’emplacement
