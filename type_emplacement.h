// mat_type_emplacement.h
// Projet : Gestion des types d'emplacements - Camping La Cerisaie
// Auteurs : TCHINDOU Essowazou Félicien, COMADAN Ilénin Jacques
// Professeur : MR AKAKPO

#ifndef MAT_TYPE_EMPLACEMENT_H
#define MAT_TYPE_EMPLACEMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Taille maximale pour le nom du type d'emplacement
#define MAX_TYPE 20

// Nouveau fichier de stockage
#define FICHIER_TYPE_EMPLACEMENT "type_emplacements.txt"

// ===============================
//   STRUCTURE PRINCIPALE
// ===============================

typedef struct {
    int id;                  // Identifiant unique
    char type[MAX_TYPE];     // Exemple : Tente, Caravane, Camping-car, Bungalow
    int nb_places;           // Nombre maximum de personnes
    float surface;           // Surface en m²
    float tarif;             // Tarif par jour et par personne
} MatTypeEmplacement;


// ===============================
//     FONCTIONS UTILITAIRES
// ===============================

void clear_screen();
void pause_ecran();

int lire_entier(char *message);
float lire_float(char *message);
void lire_chaine(char *message, char *buffer, int taille);

// ===============================
//  FONCTIONS DE GESTION (CRUD)
// ===============================

void ajouter_mat_type_emplacement();
void supprimer_mat_type_emplacement();
void modifier_mat_type_emplacement();
void consulter_mat_type_emplacement();
void lister_mat_type_emplacements();

#endif // MAT_TYPE_EMPLACEMENT_H
