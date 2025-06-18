#include <estia-image.h>
#include <stdio.h>

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

/*
void rotate_cw(char *source_path){
    unsigned char *datasrc = NULL;
    int width=0, height =0, channel_count=0;
    int x,y ;
    read_image_data(source_path, &datasrc, &width, &height, &channel_count);
    unsigned char *datadest= malloc(height*width*channel_count*sizeof(unsigned char));
 
    for (x=0;x<height;x++){
        for (y=0;y<width;y++){
           datadest= set_pixel(datadest, width, height, channel_count, width-1-y, x, datasrc, x, y);
        }
    }
    write_image_data("./images/input/image_rotatecw_out.bmp", datadest, width, height);
    free(datadest);
}*/
void color_red(char *source_path) {
    unsigned char *datasrc = NULL;
    int width = 0, height = 0, channel_count = 0;

    // Lecture de l'image
    read_image_data(source_path, &datasrc, &width, &height, &channel_count);

    if (datasrc == NULL || channel_count < 3) {
        printf("Erreur : l'image n'a pas pu être lue correctement ou n'a pas assez de canaux.\n");
        return;
    }

    // On modifie les données pour garder uniquement la composante rouge
    int size = width * height * channel_count;
    for (int i = 0; i < size; i += channel_count) {
        // R = datasrc[i]
        datasrc[i + 1] = 0; // G à 0
        datasrc[i + 2] = 0; // B à 0
    }

    // Sauvegarde de l'image modifiée
    write_image_data("./images/input/image_out.bmp", datasrc, width, height);

    // Libération mémoire
    free(datasrc);
}

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



/*rotation sens horaire
void rotate_cw(char *source_path){
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
