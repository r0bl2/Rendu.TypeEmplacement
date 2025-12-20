/*
    PROGRAMME : Gestion des types d'emplacement
    FICHIER   : type_emplacement.h
    Auteurs   : COMADAN Kokou Ilenin Jacques ;
                TCHINDOU Essowazou Felicien
    Professeur: Mr AKAKPO

    Objet :
        - Declaration de la structure TypeEmplacement
        - Declaration des constantes globales
        - Declaration des prototypes des fonctions publiques

    Date de création    : 08/12/2025
    Date de modification : 20/12/2025
*/

#ifndef TYPE_EMPLACEMENT_H
#define TYPE_EMPLACEMENT_H

#define LIBELLE_MAX 50  // Taille maximale d'un libellé

/* Structure représentant un type d'emplacement */
typedef struct {
    int idTypeEmplacement;     // Identifiant unique
    float tarifJour;           // Tarif journalier
    char libelle[LIBELLE_MAX]; // Libellé du type
} TypeEmplacement;

/* Fonctions publiques du module */
void chargerTypes(void);           // Charger les données depuis le fichier
void sauvegarderTypes(void);       // Sauvegarder les données dans le fichier

void ajouterTypeEmplacement(void); // Ajouter un type
void modifierTypeEmplacement(void); // Modifier un type
void supprimerTypeEmplacement(void); // Supprimer un type
void consulterTypeEmplacement(void); // Consulter un type
void listerTypeEmplacement(void);    // Lister tous les types

#endif
