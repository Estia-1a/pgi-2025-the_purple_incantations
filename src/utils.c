#include <estia-image.h>
#include <stdio.h>
#include "utils.h"

/**
 * @brief Here, you have to define functions of the pixel struct : getPixel and setPixel.
 * 
 */
pixelRGB* get_pixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y )
{
    if (x >=width || y >= height || data == NULL) {
        return NULL;
    }
    else{
        return(pixelRGB*) &data[(y * width + x) * n];
    }
}

void print_pixel(char * filename, int x, int y) {
    int width;
    int height;
    int channel_count;
    unsigned char* data;

   int res = read_image_data(filename, &data, &width, &height, &channel_count);
   if (res == 0) {
        printf("NULL");
   }

   pixelRGB* pixel = get_pixel(data, width, height, channel_count, x, y);

   printf("print_pixel (%d, %d): %d, %d, %d\n", x, y, pixel->R, pixel->G, pixel->B);
   free_image_data(data);
}