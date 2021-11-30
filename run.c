#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "input.h"
#include <sys/wait.h>

void show_prompt() {
  char *path = getcwd(NULL, 0);
  printf("\e[32mshelly-shell \e[34m%s\e[0m: ", path);
  free(path);
}

int main() {
  while (1) {
    show_prompt();
    char **input = get_input();
    char *command = input[0];

    if (command) {
      if (!strcmp(command, "exit")) {
        return 0;
      }
      else if (!strcmp(command, "cd")) {
        char *mini_path = input[1];
        chdir(mini_path);
      }
      else {
      	int pid = fork();
        if (pid == 0){
            execvp(input[0], &input[0]);
            printf("Error: %s\n", strerror(errno));
            exit(0);
        } else {
            wait(NULL);
        }
      }
    }
    free_strings(input);
  }
}


