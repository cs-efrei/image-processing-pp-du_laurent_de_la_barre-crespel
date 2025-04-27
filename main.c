//
// Created by malo on 20/03/2025.
//

#include "functions.c"
#include "t_bmp8.h"
#include "t_bmp24.h"

// fait par: Loic Du Laurent de la barre 27/04
int main() {
    // Charger l'image
    t_bmp8 * img = bmp8_loadImage("mon_image.bmp");

    if (img == NULL) {
        printf("Erreur lors du chargement de l'image.\n");
        return 1; // quitter avec erreur
    }

    //On libère la mémoire
    bmp8_free(img);

    return 0; // tout s'est bien passé
}