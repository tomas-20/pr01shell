#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "string_list.h"
#include "input.h"
#include "string_split.h"

void run() {
  struct string_list *path = get_string_list();
  bool running = true;
  while (running) {
    printf("input thing: ");
    char **input = get_input(2187);
    char *command = input[0];
    if (command) {
      if (!strcmp(command, "exit")) {
        running = false;
      }
      else if (!strcmp(command, "pwd")){
        printf("%s\n", get_path_string(path, ""));
      }
      else if (!strcmp(command, "cd")) {
        char *arg = input[1];
        if (arg) {
          if (!strcmp(arg, "..")) {
            remove_string(path);
          }
          else if (strcmp(arg, ".")) {
            if (arg[0] == '/') {
              free_string_list(path);
              path = get_string_list();
            }
            char **mini_path = string_split(arg, "/");
            for (char **sp = mini_path; *sp; sp ++) {
              add_string(path, *sp);
            }
            free_strings(mini_path);
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
