#include "image_viewer.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int parse_ppm_header(FILE *fp, int *width, int *height, int *maxval)
{
  char magic[3];
  int c;

  if (!fp || !width || !height || !maxval)
    return -1;

  /* Read magic number */
  if (fscanf(fp, "%2s", magic) != 1)
    return -1;

  if (strcmp(magic, "P6") != 0)
    return -1;

  /* Read width, height, maxval while skipping comments */
  for (int i = 0; i < 3;)
  {
    c = fgetc(fp);

    if (c == '#')
    {
      /* Skip comment line */
      while ((c = fgetc(fp)) != '\n' && c != EOF)
        ;
      continue;
    }

    if (isspace(c))
      continue;

    ungetc(c, fp);

    if (i == 0 && fscanf(fp, "%d", width) == 1)
      i++;
    else if (i == 1 && fscanf(fp, "%d", height) == 1)
      i++;
    else if (i == 2 && fscanf(fp, "%d", maxval) == 1)
      i++;
    else
      return -1;
  }

  /* Consume single whitespace before binary pixel data */
  fgetc(fp);

  return 0;
}

/**
 * Core logic of image viewer.
 */
void image_viewer(FILE *fp, int *height, int *width, int *maxval)
{
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
  {
    printf("SDL_Init Error: %s\n", SDL_GetError());
    return;
  }

  SDL_Window *pwin = SDL_CreateWindow(
      "imgview",
      SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
      *height,
      *width,
      SDL_WINDOW_SHOWN);

  if (!pwin)
  {
    printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
    SDL_Quit();
    return;
  }

  SDL_Surface *psurface = SDL_GetWindowSurface(pwin);
  if (!psurface)
  {
    printf("SDL_GetWindowSurface Error: %s\n", SDL_GetError());
    SDL_DestroyWindow(pwin);
    SDL_Quit();
    return;
  }

  SDL_Rect pixel = {0, 0, 1, 1};

  for (int y = 0; y < *height; y++)
  {
    for (int x = 0; x < *width; x++)
    {
      pixel.x = x; // width
      pixel.y = y; // height
      Uint8 r = fgetc(fp);
      Uint8 g = fgetc(fp);
      Uint8 b = fgetc(fp);
      Uint32 color = SDL_MapRGB(psurface->format, r, g, b);
      SDL_FillRect(psurface, &pixel, color);
    }
  }
  SDL_UpdateWindowSurface(pwin);

  int running = 1;
  SDL_Event e;

  while (running)
  {
    while (SDL_PollEvent(&e))
    {
      if (e.type == SDL_QUIT)
        running = 0;
    }
    SDL_Delay(16);
  }

  SDL_DestroyWindow(pwin);
  SDL_Quit();
}
