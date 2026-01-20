/*************************************************************
 * @file      src/main.c
 * @brief     Image Viewer with SDL2.
 * @author    Aravind Potluri <aravindswami135@gmail.com>
 ***************************************************************/

// Imports
#include <stdio.h>
#include <stdlib.h>
#include <image_viewer.h>

/**
 * @brief Entry point for the program.
 *
 * @param argc Number of command line args
 * @param argv Array of command line arg strings
 *
 * @return Exit status (0 on success, non-zero on failure)
 */
int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: imgview <image.ppm>\n\n");
    return 1;
  }

  FILE *fp = fopen(argv[1], "rb");
  if (!fp)
  {
    perror("fopen");
    return 1;
  }

  // Parse PPM file and fetch params
  int height, width, maxval;
  if (parse_ppm_header(fp, &height, &width, &maxval) != 0)
  {
    perror("Invalid PPM header\n");
    fclose(fp);
    return 1;
  }

  // Open the viewer
  image_viewer(fp, &height, &width, &maxval);

  return 0;
}
