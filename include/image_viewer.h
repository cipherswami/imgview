#ifndef IMAGE_VIEWER_H
#define IMAGE_VIEWER_H

/**
 * @brief Starts the image viewer application.
 *
 * Displays the image described by the given PPM metadata and
 * reads pixel data from the provided file stream.
 *
 * @param fp     FILE pointer to the PPM file.
 * @param width  Image width in pixels.
 * @param height Image height in pixels.
 * @param maxval Maximum color value.
 */
void image_viewer(FILE *fp, int *height, int *width, int *maxval);

/**
 * @brief Parses the header of a PPM (Portable Pixmap) file.
 *
 * @param fp     FILE pointer to the PPM file.
 * @param width  Output parameter; updated with the image width.
 * @param height Output parameter; updated with the image height.
 * @param maxval Output parameter; updated with the maximum color value.
 *
 * @return 0 on success, non-zero on failure.
 */
int parse_ppm_header(FILE *fp, int *height, int *width, int *maxval);

#endif /* IMAGE_VIEWER_H */
