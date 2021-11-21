#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "input.h"

bool same_string(char *a, char *b) {
  return a && b && !strcmp(a, b);
}

void run() {
  bool running = true;
  while (running) {
    char **input = get_input("input thing:", 2187);
    if (same_string(input[0], "exit")) {
      running = false;
    }
    free_strings(input);
  }
}
