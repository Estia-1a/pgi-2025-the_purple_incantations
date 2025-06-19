
#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>
#include "features.h"
#include "utils.h"

/*
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */


void helloWorld() {
    printf("Salut les copaings");
}
void dimension (char *source_path){
    int width;
    int height;
    int channel_count;
    unsigned char *data;

    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);

    if (resultat){ 
    printf("dimension: %d,%d",width,height);
    }
    else {
      printf("ERROR!!!!!!");  
    }
}

void first_pixel (char *source_path){
    int width;
    int height;
    int channel_count;
    unsigned char *data;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
    
    if (resultat){ 
    printf("first_pixel: %d, %d, %d",data[0],data[1],data[2]);
    }
    else {
      printf("ERROR!!!!!!");  
    }
}

void tenth_pixel (char *source_path){
    int width;
    int r,g,b,p;
    int height;
    int channel_count;
    unsigned char *data;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
    
    if (resultat){
        p=10;
        r=(p-1)*3;
        g=r+1;
        b=g+1;
    printf("tenth_pixel: %d, %d, %d",data[r],data[g],data[b]);
    }
    else {
      printf("ERROR!!!!!!");  
    }
}

void second_line (char *source_path){
    int r,g,b,p,l;
    int width;
    int height;
    int channel_count;
    unsigned char *data;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
    
    if (resultat){ 
        l=2;
        p=1;
        p=(width*(l-1))+p;
        r=(p-1)*3;
        g=r+1;
        b=g+1;
    printf("second_line: %d, %d, %d",data[r],data[g],data[b]);
    }
    else {
      printf("ERROR!!!!!!");  
    }
}
//rotation sens horaire
void rotate_cw(char *source_path){
    unsigned char *datasrc = NULL;
    int width = 0, height = 0, channel_count = 0;

    if (!read_image_data(source_path, &datasrc, &width, &height, &channel_count)) {
        fprintf(stderr, "Erreur image.\n");
        return;
    }
    int new_width = height;
    int new_height = width;

    unsigned char *datadest = malloc(new_width * new_height * channel_count * sizeof(unsigned char));
    if (!datadest) {
        fprintf(stderr, "Erreur mémoire.\n");
        free_image_data(datasrc);
        return;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB *pixel = get_pixel(datasrc, width, height, channel_count, x, y);
            if (pixel) {
                set_pixel(datadest, new_width, new_height, channel_count, new_height - 1 - y,x, pixel);
            }
        }
    }

    write_image_data("./images/input/image_out.bmp", datadest, new_width, new_height);

    free(datadest);
    free_image_data(datasrc);
}
/*rotation sens anti-horaire*/
void rotate_acw(char *source_path){
    unsigned char *datasrc = NULL;
    int width = 0, height = 0, channel_count = 0;

    if (!read_image_data(source_path, &datasrc, &width, &height, &channel_count)) {
        fprintf(stderr, "Erreur image.\n");
        return;
    }
    int new_width = height;
    int new_height = width;

    unsigned char *datadest = malloc(new_width * new_height * channel_count * sizeof(unsigned char));
    if (!datadest) {
        fprintf(stderr, "Erreur mémoire.\n");
        free_image_data(datasrc);
        return;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB *pixel = get_pixel(datasrc, width, height, channel_count, x, y);
            if (pixel) {
                set_pixel(datadest, new_width, new_height, channel_count, y, new_height - 1 - x, pixel);
            }
        }
    }

    write_image_data("./images/input/image_out.bmp", datadest, new_width, new_height);

    free(datadest);
    free_image_data(datasrc);
}

void max_pixel(char *image_path) {
    
    unsigned char *image = NULL;  
    int width = 0, height = 0, channels = 0; 

    
    read_image_data(image_path, &image, &width, &height, &channels);

    
    int max_sum = -1;
    int pixel_x = 0, pixel_y = 0;
    unsigned char max_r = 0, max_g = 0, max_b = 0;

    
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
          
            int i = (y * width + x) * channels;

            
            unsigned char r = image[i];
            unsigned char g = image[i + 1];
            unsigned char b = image[i + 2];

            
            int sum = r + g + b;

            
            if (sum > max_sum) {
                max_sum = sum;
                pixel_x = x;
                pixel_y = y;
                max_r = r;
                max_g = g;
                max_b = b;
            }
        }
    }


    printf("max_pixel (%d, %d): %d, %d, %d\n", pixel_x, pixel_y, max_r, max_g, max_b);
}

void min_pixel(char *image_path) {
    unsigned char *image = NULL;
    int width = 0, height = 0, channels = 0;

    read_image_data(image_path, &image, &width, &height, &channels);

    int min_sum = 255 * 3 + 1;
    int pixel_x = 0, pixel_y = 0;
    unsigned char min_r = 0, min_g = 0, min_b = 0;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int i = (y * width + x) * channels;

            unsigned char r = image[i];
            unsigned char g = image[i + 1];
            unsigned char b = image[i + 2];

            int sum = r + g + b; 

            if (sum < min_sum) {
                min_sum = sum;
                pixel_x = x;
                pixel_y = y;
                min_r = r;
                min_g = g;
                min_b = b;
            }
        }
    }

    printf("min_pixel (%d, %d): %d, %d, %d\n", pixel_x, pixel_y, min_r, min_g, min_b);
}
void color_red(char *source_path){
    unsigned char *data = NULL;
    int width=0, height =0, channel_count=0;
    int i ;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    for(i=0; i<channel_count * width * height;i++){
       if (i%3 != 0){
        data[i] = 0;
       }
    }
    write_image_data("./images/input/image_out.bmp", data, width, height);
}
