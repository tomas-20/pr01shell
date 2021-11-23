#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "string_split.h"

void debug(int argc, char * argv[], int x) {
    if (x) {
        printf("argc: %d\n", argc);
        int i;
        int count = 0;
        for (i=0; i<=argc; i++) {
            printf("%d: %s\n", i, argv[i]);
        }
    }
}

int n_of_char(char * s, char c) {
    int i;
    int count = 0;
    int size = strlen(s);

    for (i = 0; i < size; i++) {
        if (s[i] == c) {
            count++;
        }
    }
    return count;
}

char ** get_args() {
    char s[100];
    fgets(s, 100, stdin);
    s[strcspn(s, "\n")] = 0;
    int argc = n_of_char(s, ' ' ) + 1;
    char **argv = string_split(s, " ");
    debug(argc, argv, 0);
    return argv;
}


int main() {
    while (1) {
        printf("shelly-shell: ");
        char **argv = get_args();

        if (strcmp(argv[0], "exit") == 0) {
            break;
        }

        int pid = fork();
        if (pid == 0){
            execvp(argv[0], &argv[0]);
            fprintf(stderr, "shelly-shell: command not found\n");
        } else {
            wait(NULL);
        }
    }
    return 0;
}
