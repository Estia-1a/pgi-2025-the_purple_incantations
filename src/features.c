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
    printf("Ouech les zgegs !!");
}
void dimension(char *source_path){
    int width;
    int height;
    int channel_count;
    unsigned char *data;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
     

    if (resultat){
        printf("dimension %d,%d",width,height);
    }
    else{
        printf("ERREUR");
    }

}
void first_pixel (char *source_path){
    int width;
    int height;
    int channel_count;
    unsigned char *data;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
     

    if (resultat){
        printf("first_pixel %d,%d,%d",data[0],data[1],data[2]);
    }
    else{
        printf("ERREUR");
    }
    

}
void tenth_pixel (char *source_path){
    int width;
    int height;
    int channel_count;
    unsigned char *data;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
     

    if (resultat){
        printf("tenth_pixel %d,%d,%d",data[27],data[28],data[29]);
    }
    else{
        printf("ERREUR");
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
        p=(width*(l-1)+p);
        r=(p-1)*3;
        g=r+1;
        b=g+1;
        printf("second_line %d,%d,%d",data[r],data[g],data[b]);
    }
    else{
        printf("ERREUR");
    }
}  