//
// Created by cash on 20/03/2025.
//
#include <stdio.h>
#include "functions.h"


FILE *f = fopen("image.bmp", "rb");

unsigned char buffer[54];
fread(buffer, 1, 54, f);
int largeur = *(unsigned int*)(&buffer[18]);