/**************************************************************
 * Author        : Aravind Potluri <aravindswami135@gmail.com>
 * Description   : Image Viewer with SDL2.
 ***************************************************************/

// Required
#include <stdio.h>
#include <stdlib.h>
#include "image_viewer.h"

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

  int height, width, maxval;
  if (parse_ppm_header(fp, &height, &width, &maxval) != 0)
  {
    perror("Invalid PPM header\n");
    fclose(fp);
    return 1;
  }
  image_viewer(fp, &height, &width, &maxval);
  return 0;
}
