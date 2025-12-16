/*
   PROGRAMME            : Gestion des type_emplacement
   Auteur               : TCHINDOU Felicien ; COMADAN Kokou Ilénin Jacques
   Objet                : Implémente les fonctions pour ajouter, modifier, supprimer, 
                          consulter et lister les type_emplacement dans un fichier texte.
   Date de création     :  07/12/2025
   Date de modification :  15/12/2025
 */

#ifndef TYPE_EMPLACEMENT_H
#define TYPE_EMPLACEMENT_H

#include <stdio.h>

// Constantes pour les tailles
#define TAILLE_NOM 50
#define TAILLE_DESCRIPTION 200

// Structure pour représenter un type d'emplacement
typedef struct {
    int numero_type;              // Numéro unique du type
    char nom[TAILLE_NOM];         // Nom du type (ex: "Tente", "Caravane")
    float prix_jour_personne;     // Prix par jour et par personne en euros
    float surface_moyenne;        // Surface moyenne en m²
    int capacite_max_personnes;   // Nombre maximum de personnes
    char description[TAILLE_DESCRIPTION]; // Description de l'emplacement
} TypeEmplacement;

// Prototypes des fonctions
int verification(int numero_type);
int saisirNumeroType(int mode);
void saisirCaracteristiques(TypeEmplacement *te, int estModification);
void afficherTypeEmplacement(const TypeEmplacement *te);
void ajouterTypeEmplacement(void);
void modifierTypeEmplacement(void);
void supprimerTypeEmplacement(void);
void consulterTypeEmplacement(void);
void listerTypeEmplacement(void);
void viderBuffer(void);

#endif