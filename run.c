#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "input.h"
#include "string_list.h"

void run() {
  struct string_list *path = get_string_list();
  bool running = true;
  while (running) {
    char **input = get_input("input thing:", 2187);
    char *command = input[0];
    if (command) {
      if (!strcmp(command, "exit")) {
        running = false;
      }
      else if (!strcmp(command, "pwd")){
        printf("%s\n", get_path_string(path, ""));
      }
      else if (!strcmp(command, "cd")) {
        char *dir = input[1];
        if (dir) {
          if (!strcmp(dir, "..")) {
            remove_string(path);
          }
          else if (strcmp(dir, ".")) {
            add_string(path, dir);
          }
        }
        else {
          free_string_list(path);
          path = get_string_list();
        }
      }
    }
    free_strings(input);
  }
}
