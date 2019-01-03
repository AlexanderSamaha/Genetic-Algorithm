#include "a4.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX max_color + 1

PIXEL *generate_random_image(int width, int height, int max_color) {
  PIXEL *pixels = malloc(sizeof(PIXEL) * width * height);
  PIXEL *p = pixels;
  int i;

  // initializing each pixel with random RGB values
  for (i = 0; i < height * width; i++) {
    pixels[i].r = (unsigned char)(rand() % (MAX));
    pixels[i].g = (unsigned char)(rand() % (MAX));
    pixels[i].b = (unsigned char)(rand() % (MAX));
  }
  return p;
}

Individual *generate_population(int population_size, int width, int height,
                                int max_color) {

  Individual *population = malloc(sizeof(Individual) * population_size);
  int i;
  // generating images for each individual in p
  for (i = 0; i < population_size; i++) {
    PPM_IMAGE *image = malloc(sizeof(PPM_IMAGE));
    image->data = generate_random_image(width, height, max_color);
    image->width = width;
    image->height = height;
    image->max_color = max_color;
    population[i].image = *image;
  }
  
  return population;
}
