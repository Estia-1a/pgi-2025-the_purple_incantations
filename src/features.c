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
    printf("first pixel: %d, %d, %d",data[0],data[1],data[2]);
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
    printf("tenth_pixel: %d, %d, %d\n",data[r],data[g],data[b]);
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
    int r,g,b,x,y;
    int width;
    int height;
    int channel_count;
    unsigned char *data;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
    printf("Coordonnees du pixel x,y ");
    scanf("%d,%d",&x,&y);
    
    if (resultat && x<(width+1) && y<(height+1)) { 
        x=(width*(y-1))+x;
        r=(x-1)*3;
        g=r+1;
        b=g+1;
    printf("pixel: %d, %d, %d",data[r],data[g],data[b]);
    }
    else {
      printf("ERROR!!!!!!");  
    }
}

void max_pixel(char *source_path) {
    int width, height, channel_count;
    unsigned char *data;

    int result = read_image_data(source_path, &data, &width, &height, &channel_count);
    (void)result; 
    
    int max_sum = -1;
    int max_index = 0;

    for (int i = 0; i < width * height; i++) {
        int r = data[i * channel_count];
        int g = data[i * channel_count + 1];
        int b = data[i * channel_count + 2];
        int sum = r + g + b;

        if (sum > max_sum) {
            max_sum = sum;
            max_index = i;
        }
    }

    int r = data[max_index * channel_count];
    int g = data[max_index * channel_count + 1];
    int b = data[max_index * channel_count + 2];

    int x = max_index % width;
    int y = max_index / width;

    printf("max_pixel (%d, %d): %d, %d, %d", x, y, r, g, b);
}

void min_pixel(char *source_path) {
    int width, height, channel_count;
    unsigned char *data;

    int result = read_image_data(source_path, &data, &width, &height, &channel_count);
    if (result != 0) {
        printf("ERROR!!!!!!");
        return;
    }

    int min_sum = 255 * 3 + 1; // Plus grande somme possible + 1
    int min_index = 0;

    for (int i = 0; i < width * height; i++) {
        int r = data[i * channel_count];
        int g = data[i * channel_count + 1];
        int b = data[i * channel_count + 2];
        int sum = r + g + b;

        if (sum < min_sum) {
            min_sum = sum;
            min_index = i;
        }
    }

    int r = data[min_index * channel_count];
    int g = data[min_index * channel_count + 1];
    int b = data[min_index * channel_count + 2];

    int x = min_index % width;
    int y = min_index / width;

    printf("min_pixel (%d, %d): %d, %d, %d", x, y, r, g, b);
}