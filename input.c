#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_split.h"

char *get_input_string(int max_size) {
  char *input = malloc(sizeof (char[max_size]));
  fgets(input, max_size, stdin);
  return strsep(&input, "\n");
}

char **get_input() {
  char *input_string = get_input_string(2187);
  char **input = string_split(input_string, " ");
  free(input_string);
  return input;
}

void free_strings(char **strings) {
  for (char **sp = strings; *sp; sp ++) {
    free(*sp);
  }
  free(strings);
}
