#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>
#include "features.h"
#include "utils.h"

/**
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
        l=2;/*rentrer la ligne voulu */
        p=1;/*rentrer le pixel voulu */
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

/*rotation sens horaire*/
/*void rotate_cw(char *source_path){
    unsigned char *datasrc = NULL;
    int width=0, height =0, channel_count=0;
    int x,y ;
    read_image_data(source_path, &datasrc, &width, &height, &channel_count);
    unsigned char *datadest= malloc(height*width*channel_count*sizeof(unsigned char));
 
    for (x=0;x<height;x++){
        for (y=0; y<width; y++) {
            set_pixel(datadest, height, width, channel_count, x, y, datasrc, y, width - 1 - x);
        }
    }
    write_image_data("./images/input/image_rotatecw_out.bmp", datadest, width, height);
    free(datadest);
}*/

void max_pixel(char *image_path) {
    // Déclaration des variables
    unsigned char *image = NULL;   // Contiendra les données de l'image
    int width = 0, height = 0, channels = 0; // Dimensions et nombre de canaux (R, G, B)

    // Charger l'image
    read_image_data(image_path, &image, &width, &height, &channels);

    // Variables pour garder le pixel avec la plus grande somme R+G+B
    int max_sum = -1;
    int pixel_x = 0, pixel_y = 0;
    unsigned char max_r = 0, max_g = 0, max_b = 0;

    // Parcourir tous les pixels de l'image
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Calcul de l'index du pixel dans le tableau
            int i = (y * width + x) * channels;

            // Lire les 3 composantes du pixel
            unsigned char r = image[i];
            unsigned char g = image[i + 1];
            unsigned char b = image[i + 2];

            // Calculer la somme R + G + B
            int sum = r + g + b;

            // Si c'est plus grand que le max actuel, on le garde
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

    // Afficher le résultat
    printf("max_pixel (%d, %d): %d, %d, %d\n", pixel_x, pixel_y, max_r, max_g, max_b);
}

