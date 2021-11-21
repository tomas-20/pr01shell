#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "input.h"

void run() {
  bool running = true;
  while (running) {
    char **input = get_input("input thing:", 2187);
    char *command = input[0];
    if (command) {
      if (!strcmp(command, "exit")) {
        running = false;
      }
    }
    free_strings(input);
  }
}
