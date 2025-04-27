//
// Created by loic on 27/04/2025.
//

#ifndef IMAGE_PROCESSING_GR7_T_BMP8_H
#define IMAGE_PROCESSING_GR7_T_BMP8_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1.1 Le type structuré t_bmp8
typedef struct {
    unsigned char header[54];
    unsigned char colorTable[1024];
    unsigned char * data;

    unsigned int width;
    unsigned int height;
    unsigned int colorDepth;
    unsigned int dataSize;
} t_bmp8;


// 1.2 Lecture et écriture d’une image en niveaux de gris
t_bmp8 * bmp8_loadImage(const char * filename);
void bmp8_saveImage(const char * filename, t_bmp8 * img);
void bmp8_free(t_bmp8 * img);
void bmp8_printInfo(t_bmp8 * img);

void bmp8_negative(t_bmp8 * img);
void bmp8_brightness(t_bmp8 * img, int value);
void bmp8_threshold(t_bmp8 * img, int threshold);

// 1.4 Les filtres d’image
void bmp8_applyFilter(t_bmp8 * img, float ** kernel, int kernelSize);


#endif //IMAGE_PROCESSING_GR7_T_BMP8_H
