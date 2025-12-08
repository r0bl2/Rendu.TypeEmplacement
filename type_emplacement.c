// type_emplacement.c
// Implémentation des fonctions de gestion des types d'emplacements
#include "type_emplacement.h"

// ===== Fonctions utilitaires =====

void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pause_ecran() {
    printf("\nAppuyez sur Entrée pour continuer...");
    getchar();
}

int lire_entier(char *message) {
    int val;
    while (1) {
        printf("%s : ", message);
        if (scanf("%d", &val) != 1 || val <= 0) {
            printf("Erreur : entrez un entier positif.\n");
            while (getchar() != '\n');
        } else {
            getchar();
            return val;
        }
    }
}

float lire_float(char *message) {
    float val;
    while (1) {
        printf("%s : ", message);
        if (scanf("%f", &val) != 1 || val <= 0) {
            printf("Erreur : entrez un nombre positif.\n");
            while (getchar() != '\n');
        } else {
            getchar();
            return val;
        }
    }
}

void lire_chaine(char *message, char *buffer, int taille) {
    printf("%s : ", message);
    fgets(buffer, taille, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
}

// ===== Fonctions de gestion =====

void ajouter_mat_type_emplacement() {
    clear_screen();
    printf("\n==================================\n");
    printf("   AJOUT TYPE D'EMPLACEMENT\n");
    printf("==================================\n");

    MatTypeEmplacement e;
    e.id = lire_entier("Entrez l'ID du type");
    printf("\nExemple : Tente, Caravane, Camping-car, Bungalow\n");
    lire_chaine("Entrez le type", e.type, MAX_TYPE);
    e.nb_places = lire_entier("Nombre maximum de personnes");
    e.surface = lire_float("Surface en m²");
    e.tarif = lire_float("Tarif par jour par personne (euros)");

    FILE *f = fopen(FICHIER_TYPE_EMPLACEMENT, "a");
    if (f) {
        fprintf(f, "%d;%s;%d;%.2f;%.2f\n", e.id, e.type, e.nb_places, e.surface, e.tarif);
        fclose(f);
        printf("\nType d'emplacement ajouté avec succès !\n");
    } else printf("Erreur : impossible d'ouvrir le fichier.\n");

    pause_ecran();
}

void lister_mat_type_emplacements() {
    clear_screen();
    printf("\n==================================\n");
    printf("  LISTE DES TYPES D'EMPLACEMENT\n");
    printf("==================================\n");

    FILE *f = fopen(FICHIER_TYPE_EMPLACEMENT, "r");
    if (!f) {
        printf("Aucun type enregistré.\n");
        pause_ecran();
        return;
    }

    MatTypeEmplacement e;
    printf("ID | Type        | Places | Surface | Tarif\n");
    printf("------------------------------------------------\n");

    while (fscanf(f, "%d;%[^;];%d;%f;%f\n", &e.id, e.type, &e.nb_places, &e.surface, &e.tarif) == 5) {
        printf("%2d | %-10s | %6d | %7.2f | %6.2f\n", e.id, e.type, e.nb_places, e.surface, e.tarif);
    }

    fclose(f);
    pause_ecran();
}

void consulter_mat_type_emplacement() {
    clear_screen();
    printf("\n==================================\n");
    printf("   CONSULTER TYPE D'EMPLACEMENT\n");
    printf("==================================\n");

    int id = lire_entier("Entrez l'ID à consulter");
    FILE *f = fopen(FICHIER_TYPE_EMPLACEMENT, "r");
    if (!f) {
        printf("Aucun type enregistré.\n");
        pause_ecran();
        return;
    }

    MatTypeEmplacement e;
    int trouve = 0;

    while (fscanf(f, "%d;%[^;];%d;%f;%f\n", &e.id, e.type, &e.nb_places, &e.surface, &e.tarif) == 5) {
        if (e.id == id) {
            printf("\nID : %d\nType : %s\nPlaces : %d\nSurface : %.2f m²\nTarif : %.2f euros\n", e.id, e.type, e.nb_places, e.surface, e.tarif);
            trouve = 1;
            break;
        }
    }

    if (!trouve) printf("Type introuvable.\n");

    fclose(f);
    pause_ecran();
}

void supprimer_mat_type_emplacement() {
    clear_screen();
    printf("\n==================================\n");
    printf(" SUPPRESSION TYPE D'EMPLACEMENT\n");
    printf("==================================\n");

    int id = lire_entier("Entrez l'ID à supprimer");
    FILE *f = fopen(FICHIER_TYPE_EMPLACEMENT, "r");
    FILE *temp = fopen("temp.txt", "w");

    if (!f || !temp) {
        printf("Erreur fichier.\n");
        pause_ecran();
        return;
    }

    MatTypeEmplacement e;
    int trouve = 0;

    while (fscanf(f, "%d;%[^;];%d;%f;%f\n", &e.id, e.type, &e.nb_places, &e.surface, &e.tarif) == 5) {
        if (e.id != id)
            fprintf(temp, "%d;%s;%d;%.2f;%.2f\n", e.id, e.type, e.nb_places, e.surface, e.tarif);
        else
            trouve = 1;
    }

    fclose(f);
    fclose(temp);
    remove(FICHIER_TYPE_EMPLACEMENT);
    rename("temp.txt", FICHIER_TYPE_EMPLACEMENT);

    if (trouve) printf("\nType supprimé avec succès !\n");
    else printf("\nType introuvable.\n");

    pause_ecran();
}

void modifier_mat_type_emplacement() {
    clear_screen();
    printf("\n==================================\n");
    printf(" MODIFICATION TYPE D'EMPLACEMENT\n");
    printf("==================================\n");

    int id = lire_entier("Entrez l'ID à modifier");
    FILE *f = fopen(FICHIER_TYPE_EMPLACEMENT, "r");
    FILE *temp = fopen("temp.txt", "w");

    if (!f || !temp) {
        printf("Erreur fichier.\n");
        pause_ecran();
        return;
    }

    MatTypeEmplacement e;
    int trouve = 0;

    while (fscanf(f, "%d;%[^;];%d;%f;%f\n", &e.id, e.type, &e.nb_places, &e.surface, &e.tarif) == 5) {
        if (e.id == id) {
            printf("\nExemple : Tente, Caravane, Camping-car, Bungalow\n");
            lire_chaine("Entrez le nouveau type", e.type, MAX_TYPE);
            e.nb_places = lire_entier("Nombre maximum de personnes");
            e.surface = lire_float("Surface en m²");
            e.tarif = lire_float("Tarif par jour par personne");
            trouve = 1;
        }
        fprintf(temp, "%d;%s;%d;%.2f;%.2f\n", e.id, e.type, e.nb_places, e.surface, e.tarif);
    }

    fclose(f);
    fclose(temp);
    remove(FICHIER_TYPE_EMPLACEMENT);
    rename("temp.txt", FICHIER_TYPE_EMPLACEMENT);

    if (trouve) printf("\nType modifié avec succès !\n");
    else printf("\nType introuvable.\n");

    pause_ecran();
}
