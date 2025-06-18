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

void print_pixel (char *source_path){
    int r,g,b,x,p,y;
    int width;
    int height;
    int channel_count;
    unsigned char *data;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
    scanf("%d %d",&x,&y);
    
    if (resultat && x<(width+1) && y<(height+1)) { 
        p=(width*(y-1))+x;
        r=(p-1)*3;
        g=r+1;
        b=g+1;
    printf("print_pixel (%d, %d): %d, %d, %d",x,y,data[r],data[g],data[b]);
    }
    else {
      printf("NULL");  
    }
}

/*rotation sens horaire*/
void rotate_cw(char *source_path){
    unsigned char *datasrc = NULL;
    int width=0, height =0, channel_count=0;
    int x,y ;
    read_image_data(source_path, &datasrc, &width, &height, &channel_count);
    unsigned char *datadest= malloc(height*width*channel_count*sizeof(unsigned char));
 
    for (x=0;x<height;x++){
        for (y=0;y<width;y++){
           datadest=set_pixel(datadest, width, height, channel_count, width-1-y, x, datasrc, x, y);
        }
    }
    write_image_data("./images/input/image_rotatecw_out.bmp", datadest, width, height);
    free(datadest);
}

/*somme maximale pixel*/
void max_pixel(char *source_path) {
    unsigned char *image = NULL;
    int width = 0, height = 0, channel_count = 0;

    read_image_data(source_path, &image, &width, &height, &channel_count);

    int max_sum = -1;
    int best_x = 0, best_y = 0;
    unsigned char r = 0, g = 0, b = 0;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int i = (y * width + x) * channel_count;

            unsigned char red = image[i];
            unsigned char green = image[i + 1];
            unsigned char blue = image[i + 2];

            int sum = red + green + blue;

            if (sum > max_sum) {
                max_sum = sum;
                best_x = x;
                best_y = y;
                r = red;
                g = green;
                b = blue;
            }
        }
    }

    printf("max_pixel (%d, %d): %d, %d, %d\n", best_x, best_y, r, g, b);
}