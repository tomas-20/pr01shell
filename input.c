#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_split.h"

char *get_input_string(int max_size) {
  char *input = malloc(sizeof (char[max_size]));
  fgets(input, max_size, stdin);
  return strsep(&input, "\n");
}

char **get_input(int max_size) {
  char *input_string = get_input_string(max_size);
  char **input = string_split(input_string, " ");
  free(input_string);
  return input;
}
