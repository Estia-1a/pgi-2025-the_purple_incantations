#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <estia-image.h>
#include <getopt.h>

#include "features.h"
#include "utils.h"
#include "argsparse.h"

int main(int argc, char **argv) {
 //test
  Config configuration ;
  parse_arguments( argc, argv, &configuration ) ;
  check_debug_mode(configuration);
  check_file();
  
  if ( strncmp( configuration.command, "helloworld", 10 ) == 0 ) {
    helloWorld();
  }
  if ( strncmp( configuration.command, "dimension", 9 ) == 0 ) {
    dimension(configuration.filenames[0] );
  }

  if ( strncmp( configuration.command, "first_pixel", 11 ) == 0 ) {
    first_pixel(configuration.filenames[0] );
  }

  if ( strncmp( configuration.command, "tenth_pixel", 11 ) == 0 ) {
    tenth_pixel(configuration.filenames[0] );
  }

  if ( strncmp( configuration.command, "second_line", 11 ) == 0 ) {
    second_line(configuration.filenames[0] );
  }

  if ( strncmp( configuration.command, "print_pixel", 11 ) == 0 ) {
    print_pixel(configuration.filenames[0],atoi(configuration.arguments[0]) , atoi(configuration.arguments[1]));
  }
  
  if ( strncmp( configuration.command, "max_pixel", 9 ) == 0 ) {
    max_pixel(configuration.filenames[0] );
  }

  if ( strncmp( configuration.command, "min_pixel", 9 ) == 0 ) {
    min_pixel(configuration.filenames[0] );
  }

  if ( strncmp( configuration.command, "max_component", 13 ) == 0 ) {
    max_component(configuration.filenames[0], configuration.arguments[0][0]);
  }
  if ( strncmp( configuration.command, "min_component", 13 ) == 0 ) {
    min_component(configuration.filenames[0], configuration.arguments[0][0]);
  }

  if ( strncmp( configuration.command, "rotate_cw", 9 ) == 0 ) {
    rotate_cw(configuration.filenames[0] );
  }

  if ( strncmp( configuration.command, "rotate_acw", 10 ) == 0 ) {
    rotate_acw(configuration.filenames[0] );
  }

  if ( strncmp( configuration.command, "color_red", 9 ) == 0 ) {
    color_red(configuration.filenames[0]);  
  }

  if ( strncmp( configuration.command, "mirror_horizontal", 17) == 0 ) {
    mirror_horizontal(configuration.filenames[0]);  
  } 

  if ( strncmp( configuration.command, "color_green", 11 ) == 0 ) {
    color_green(configuration.filenames[0]);  
  }

  if ( strncmp( configuration.command, "color_blue", 10 ) == 0 ) {
    color_blue(configuration.filenames[0]); 
  }
  if ( strncmp( configuration.command, "color_gray", 10 ) == 0 ) {
    color_gray(configuration.filenames[0]); 
  }
  if ( strncmp( configuration.command, "mirror_vertical", 15) == 0 ) {
    mirror_vertical(configuration.filenames[0]);  
  }

  if ( strncmp( configuration.command, "mirror_total", 15) == 0 ) {
    mirror_total(configuration.filenames[0]);  
  }
  return 0;
}
  
 