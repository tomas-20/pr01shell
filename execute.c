#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

/*
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
*/


int main() {
    while (1) {
        printf("shelly-shell: ");
        char **argv = get_input();

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
