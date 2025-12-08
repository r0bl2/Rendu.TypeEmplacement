/*
    PROGRAMME : Gestion des types d'emplacement
    Auteurs   : COMADAN Kokou Ilenin Jacques ; TCHINDOU Essowazou Felicien
    Professeur: Mr AKAKPO

    Objet :
       - Declaration de la structure typeEmplacement
       - Declaration des prototypes des fonctions de gestion :
        ajouter, modifier, supprimer, consulter, lister


 */


#ifndef TYPE_EMPLACEMENT_H
#define TYPE_EMPLACEMENT_H

// Structure representant un type d'emplacement
struct typeEmplacement {
    int idTypeEmplacement;
    float tarifJour;
    char libelle[50];
};

// Variable globale (declaree aussi dans type_emplacement.c)
extern struct typeEmplacement TE;

// Déclaration des fonctions

int verification(int id);
void ajouterTypeEmplacement();
void modifierTypeEmplacement();
void supprimerTypeEmplacement();
void consulterTypeEmplacement();
void listerTypeEmplacement();

#endif
