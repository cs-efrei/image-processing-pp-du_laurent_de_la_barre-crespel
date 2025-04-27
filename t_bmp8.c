//
// Created by loic on 27/04/2025.
//

#include "t_bmp8.h"

// fait par: Loic Du Laurent de la barre 27/04
t_bmp8 * bmp8_loadImage(const char * filename) {

    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Erreur : impossible d'ouvrir le fichier %s\n", filename);
        return NULL;
    }

    // on utilise le type unsigned char car: 1 pixel = 1 octet = 1 unsigned char.
    // Lecture du header (54 octets)
    unsigned char header[54];
    if (fread(header, sizeof(unsigned char), 54, fp) != 54) {
        printf("Erreur : lecture du header échouée.\n");
        fclose(fp);
        return NULL;
    }

    // Vérification du format BMP
    if (header[0] != 'B' || header[1] != 'M') {
        printf("Erreur : fichier non BMP valide.\n");
        fclose(fp);
        return NULL;
    }

    // Extraction de quelques infos
    unsigned int dataOffset = *(unsigned int *)&header[10];  // position des données d'image
    unsigned int width = *(unsigned int *)&header[18];
    unsigned int height = *(unsigned int *)&header[22];
    unsigned short bitsPerPixel = *(unsigned short *)&header[28];

    if (bitsPerPixel != 8) {
        printf("Erreur : l'image n'est pas en 8 bits.\n");
        fclose(fp);
        return NULL;
    }

    // Allocation de la structure
    t_bmp8 *bmp = (t_bmp8 *)malloc(sizeof(t_bmp8));
    if (!bmp) {
        printf("Erreur : échec de malloc pour t_bmp8.\n");
        fclose(fp);
        return NULL;
    }

    // Copier le header
    memcpy(bmp->header, header, 54);

    // Lecture de la palette de couleurs
    if (fread(bmp->colorTable, sizeof(unsigned char), 1024, fp) != 1024) {
        printf("Erreur : lecture de la color table échouée.\n");
        free(bmp);
        fclose(fp);
        return NULL;
    }

    // Calcul de la taille des données
    unsigned int dataSize = width * height;

    // Allocation de la mémoire pour les données d'image
    bmp->data = (unsigned char *)malloc(dataSize);
    if (!bmp->data) {
        printf("Erreur : échec de malloc pour les données d'image.\n");
        free(bmp);
        fclose(fp);
        return NULL;
    }

    // Positionner le curseur au début des données (au cas où) puis le déplace à l'endroit où commencent les données d'image
    fseek(fp, dataOffset, SEEK_SET);

    // Lecture des données image
    if (fread(bmp->data, sizeof(unsigned char), dataSize, fp) != dataSize) {
        printf("Erreur : lecture des données image échouée.\n");
        free(bmp->data);
        free(bmp);
        fclose(fp);
        return NULL;
    }

    // Remplir les champs
    bmp->width = width;
    bmp->height = height;
    bmp->colorDepth = bitsPerPixel;
    bmp->dataSize = dataSize;

    fclose(fp);
    return bmp;

}

void bmp8_saveImage(const char * filename, t_bmp8 * img) {

}

// fait par: Loic Du Laurent de la barre 27/04
void bmp8_free(t_bmp8 * img) {

    if (image) { // vérifier que le pointeur n'est pas NULL
        if (image->data) {
            free(image->data); // libère d'abord les données de l'image
        }
        free(image); // ensuite libère la structure elle-même
    }

}

// fait par: Loic Du Laurent de la barre 27/04
void bmp8_printInfo(t_bmp8 * img) {
    printf("Image Info:\n"
           "    Width: %u\n"
           "    Height: %u\n"
           "    Color Depth: %u\\n"
           "    Data Size: %u\\n",
           img -> width, img -> height, img -> colorDepth, img -> dataSize);
}

//////////////////////////////////////////////////////////////////////////////

// 1.2 Lecture et écriture d’une image en niveaux de gris
void bmp8_negative(t_bmp8 * img) {

}

void bmp8_brightness(t_bmp8 * img, int value) {

}

void bmp8_threshold(t_bmp8 * img, int threshold) {

}


// 1.4 Les filtres d’image
void bmp8_applyFilter(t_bmp8 * img, float ** kernel, int kernelSize) {

}
