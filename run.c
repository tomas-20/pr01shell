#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "string_list.h"
#include "input.h"
#include "string_split.h"

void show_prompt(char *dir) {
  if (!dir) {
    dir = "/";
  }
  printf("shelly-shell %s: ", dir);
}

void cd(struct string_list *path, char *dir) {
  if (!strcmp(dir, "..")) {
    remove_string(path);
  }
  else if (strcmp(dir, ".")) {
    add_string(path, dir);
  }
}

void run() {
  struct string_list *path = get_string_list();
  bool running = true;
  while (running) {
    show_prompt(get_first_string(path));
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
        if (!arg || arg[0] == '/') {
          empty_string_list(path);
        }
        if (arg) {
          char **mini_path = string_split(arg, "/");
          for (char **sp = mini_path; *sp; sp ++) {
            cd(path, *sp);
          }
          free_strings(mini_path);
        }
      }
    }
    free_strings(input);
  }
}
