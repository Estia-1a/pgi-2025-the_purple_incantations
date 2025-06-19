
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
                set_pixel(datadest, new_width, new_height, channel_count, height - 1 - y,x, pixel);
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
                set_pixel(datadest, new_width, new_height, channel_count, y, height - 1 - x, pixel);
            }
        }
    }

    write_image_data("./images/input/image_out.bmp", datadest, new_width, new_height);

    free(datadest);
    free_image_data(datasrc);
}

void max_pixel(char *source_path) {
    unsigned char *image = NULL;   
    int width = 0, height = 0, channel_count = 0; 

    read_image_data(source_path, &image, &width, &height, &channel_count);

    int max_sum = -1;
    int pixel_x = 0, pixel_y = 0;
    unsigned char max_r = 0, max_g = 0, max_b = 0;

    
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int i = (y * width + x) * channel_count;

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

void min_pixel(char *source_path) {
    unsigned char *image = NULL;
    int width = 0, height = 0, channel_count = 0;

    read_image_data(source_path, &image, &width, &height, &channel_count);

    int min_sum = 255 * 3 + 1;
    int pixel_x = 0, pixel_y = 0;
    unsigned char min_r = 0, min_g = 0, min_b = 0;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int i = (y * width + x) * channel_count;

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

void max_component(char *source_path, char component) {
    unsigned char *image = NULL;
    int width = 0, height = 0, channel_count = 0;

    read_image_data(source_path, &image, &width, &height, &channel_count);

    int max_value = -1;
    int pixel_x = 0, pixel_y = 0;

    if (channel_count < 3) {
        printf("ERREUR");
        free(image);
        return;
    }

    int offset;
    if (component == 'R') {
        offset = 0;
    } else if (component == 'G') {
        offset = 1;
    } else if (component == 'B') {
        offset = 2;
    } else {
        printf("ERREUR");
        free(image);
        return;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = (y * width + x) * channel_count;
            unsigned char value = image[index + offset];

            if (value > max_value) {
                max_value = value;
                pixel_x = x;
                pixel_y = y;
            }
        }
    }

    printf("max_component %c (%d, %d): %d\n", component, pixel_x, pixel_y, max_value);
}

void min_component(char *source_path, char component) {
    unsigned char *image = NULL;
    int width = 0, height = 0, channel_count = 0;

    read_image_data(source_path, &image, &width, &height, &channel_count);

    int min_value = 256;
    int pixel_x = 0, pixel_y = 0;

    if (channel_count < 3) {
        printf("ERREUR");
        free(image);
        return;
    }

    int offset;

    if (component == 'R') {
        offset = 0;
    } else if (component == 'G') {
        offset = 1;
    } else if (component == 'B') {
        offset = 2;
    } else {
        printf("ERREUR");
        free(image);
        return;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = (y * width + x) * channel_count;
            unsigned char value = image[index + offset];

            if (value < min_value) {
                min_value = value;
                pixel_x = x;
                pixel_y = y;
            }
        }
    }

    printf("min_component %c (%d, %d): %d\n", component, pixel_x, pixel_y, min_value);
}

void color_red(char *source_path){
    unsigned char *data = NULL;
    int width = 0, height = 0, channel_count = 0;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    
    for (int i = 0; i < width * height * channel_count; i += channel_count) {
        
        unsigned char luminance = (unsigned char)(0.299 * data[i] + 0.587 * data[i + 1] + 0.114 * data[i + 2]);
        
        
        data[i]     = luminance;  
        data[i + 1] = 0;         
        data[i + 2] = 0;          
    }
    
    write_image_data("./images/input/image_out.bmp", data, width, height);
}

void mirror_horizontal(char *source_path){
    unsigned char *datasrc = NULL;
    int width = 0, height = 0, channel_count = 0;

    if (!read_image_data(source_path, &datasrc, &width, &height, &channel_count)) {
        fprintf(stderr, "Erreur image.\n");
        return;
    }
    int new_width = width;
    int new_height = height;

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
                set_pixel(datadest, new_width, new_height, channel_count, width - 1 - x, y, pixel);
            }
        }
    }

    write_image_data("./images/input/image_out.bmp", datadest, new_width, new_height);

    free(datadest);
    free_image_data(datasrc);
}
void color_green(char *source_path){
    unsigned char *data = NULL;
    int width = 0, height = 0, channel_count = 0;
    read_image_data(source_path, &data, &width, &height, &channel_count);
   
    for (int i = 0; i < width * height * channel_count; i += channel_count) {
       
        unsigned char luminance = (unsigned char)(0.299 * data[i] + 0.587 * data[i + 1] + 0.114 * data[i + 2]);
       
       
        data[i]     = 0;        
        data[i + 1] = luminance;  
        data[i + 2] = 0;          
    }
   
    write_image_data("./images/input/image_out.bmp", data, width, height);
}

void color_blue(char *source_path){
    unsigned char *data = NULL;
    int width = 0, height = 0, channel_count = 0;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    
    for (int i = 0; i < width * height * channel_count; i += channel_count) {
        
        unsigned char luminance = (unsigned char)(0.299 * data[i] + 0.587 * data[i + 1] + 0.114 * data[i + 2]);
        
        
        data[i]     = 0;          
        data[i + 1] = 0;          
        data[i + 2] = luminance;  
    }
    
    write_image_data("./images/input/image_out.bmp", data, width, height);
}

void mirror_vertical(char *source_path){
    unsigned char *datasrc = NULL;
    int width = 0, height = 0, channel_count = 0;

    if (!read_image_data(source_path, &datasrc, &width, &height, &channel_count)) {
        fprintf(stderr, "Erreur image.\n");
        return;
    }
    
    int new_width = width;
    int new_height = height;

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
                set_pixel(datadest, new_width, new_height, channel_count, x, height - 1 - y, pixel);
            }
        }
    }

    write_image_data("./images/input/image_out.bmp", datadest, new_width, new_height);

    free(datadest);
    free_image_data(datasrc);
}