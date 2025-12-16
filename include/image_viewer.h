#ifndef IMAGE_VIEWER_H
#define IMAGE_VIEWER_H

#include <stdio.h>

/**
 * Starts the image viewer application.
 */
void image_viewer(FILE *fp, int *height, int *width, int *maxval);

/**
 * Parses the given .ppm file and gets the width, height, and maxval.
 * Returns 0 on success, non-zero on failure.
 */
int parse_ppm_header(FILE *fp, int *height, int *width, int *maxval);

#endif /* IMAGE_VIEWER_H */
