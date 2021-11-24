#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include "input.h"

void show_prompt() {
  char *path = getcwd(NULL, 0);
  printf("shelly-shell %s: ", path);
  free(path);
}

void run() {
  bool running = true;
  while (running) {
    show_prompt();
    char **input = get_input(2187);
    char *command = input[0];
    if (command) {
      if (!strcmp(command, "exit")) {
        running = false;
      }
      else if (!strcmp(command, "cd")) {
        char *mini_path = input[1];
        chdir(mini_path);
      }
    }
    free_strings(input);
  }
}
