#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
//#include "string_split.h"

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

//toams' string_split
int get_word_count(char *string, char *delim) {
  int word_count = 0;
  while (string) {
    if (*strsep(&string, delim)) {
      word_count ++;
    }
  }
  return word_count;
}

char **string_split(char *string, char *delim) {
  int word_count = get_word_count(string, delim);
  char **words = malloc(sizeof (char *[word_count + 1]));
  for (int i = 0; i < word_count; i ++) {
    while (!*string) {
      string ++;
    }
    int word_length = strlen(string);
    char *word = malloc(sizeof (char[word_length + 1]));
    strcpy(word, string);
    words[i] = word;
    string += word_length;
  }
  words[word_count] = NULL;
  return words;
}

void free_strings(char **strings) {
  for (char **sp = strings; *sp; sp ++) {
    free(*sp);
  }
  free(strings);
}
//end






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