#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <estia-image.h>
#include <getopt.h>

#include "features.h"
#include "utils.h"
#include "argsparse.h"

int main(int argc, char **argv) {
 
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

  if ( strncmp( configuration.command, "rotate_cw", 9 ) == 0 ) {
    rotate_cw(configuration.filenames[0] );
  }
  if ( strncmp( configuration.command, "rotate_acw", 10 ) == 0 ) {
    rotate_acw(configuration.filenames[0] );
  }
  if ( strncmp( configuration.command, "color_red", 9 ) == 0 ) {
    color_red(configuration.filenames[0]);  
  }
  
  return 0;
}

 