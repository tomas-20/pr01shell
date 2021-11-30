#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "input.h"
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>







int get_word_count(char *string, char *delim) {
  int word_count = 0;
  while (string) {
    if (*strsep(&string, delim)) {
      word_count ++;
    }
  }
  return word_count;
}

char *copy_string(char *string) {
  return strcpy(malloc(sizeof (char[strlen(string) + 1])), string);
}

char **string_split(char *string, char *delim) {
  int word_count = get_word_count(string, delim);
  char **words = malloc(sizeof (char *[word_count + 1]));
  for (int i = 0; i < word_count; i ++) {
    while (!*string) {
      string ++;
    }
    words[i] = copy_string(string);
    while (*string) {
      string ++;
    }
  }
  words[word_count] = NULL;
  return words;
}

char *get_input_string() {
  char *input = malloc(sizeof (char[2187]));
  fgets(input, 2187, stdin);
  return strsep(&input, "\n");
}

char **get_input() {
  char *input_string = get_input_string();
  char **input = string_split(input_string, " ");
  free(input_string);
  return input;
}

void free_strings(char **strings) {
  for (char **sp = strings; *sp; sp ++) {
    free(*sp);
  }
  free(strings);
}

void show_prompt() {
  char *path = getcwd(NULL, 0);
  printf("\e[32mshelly-shell \e[34m%s\e[0m: ", path);
  free(path);
}











void execute(char **command) {
    //executes command
    //execute(["echo", "hello", "there"]);
    //prints "hello there"
    if (command[0]) {
        if (!strcmp(command[0], "cd")) {
            char *mini_path = command[1];
            chdir(mini_path);
        } else {
            int pid = fork();
            if (pid == 0){
                execvp(command[0], &command[0]);
                printf("Error: %s\n", strerror(errno));
                exit(0);
            } else {
                wait(NULL);
            }
        }
    }
    free_strings(command);
}


void sh_pipe(char **command_that_makes_input, char **command) {
    //executes command but with the output of command_that_makes_input as the input instead of stdin
    //pipe(["echo", "hello", "there"], ["wc", "-w"]);
    //prints "2"
        FILE *in, *out;
        char readbuf[80];

        if ((in = popen("echo hello there", "r")) == NULL) {
                perror("popen");
                exit(1);
        }

        if ((out = popen("wc -w", "w")) == NULL) {
                perror("popen");
                exit(1);
        }

        while(fgets(readbuf, 80, in)) {
            fputs(readbuf, out);
        }

        pclose(in);
        pclose(out);
}


void redirect_output(char **command, char *file_name) {
    //executes command but with file of file_name as the output insted of stdout
    //redirect_output(["echo", "hello", "there"], "bobby.txt");
    //writes "hello there" to bobby.txt

    char co[100];
    int i;
    int length = 3; //am not sure how to get length of command
    strcat(co, command[0]);
    for (i = 1; i < length; i++) {
        strcat(co, " ");
        strcat(co, command[i]);
    }
    printf("%s\n", co);
    strcat(co, " > ");
    strcat(co, file_name);
    FILE * out = popen(co, "w");
    pclose(out);
    
}


void redirect_input(char **command, char *file_name) {
    //executes command but with file of file_name as the input instead of stdin
    //redirect_input(["wc", "-w"], "bobby.txt");
    //prints whatever amount of words are in bobby.txt

    char co[100];
    int i;
    int length = 2; //am not sure how to get length of command
    strcat(co, command[0]);
    for (i = 1; i < length; i++) {
        strcat(co, " ");
        strcat(co, command[i]);
    }
    printf("%s\n", co);
    strcat(co, " < ");
    strcat(co, file_name);
    printf("%s\n", co);
    FILE * out = popen(co, "w");
    pclose(out);
}

int main() {
    //executes command
    //execute(["echo", "hello", "there"])
    //prints "hello there"
    /*show_prompt();
    char **command1 = get_input(); //echo hello there
    execute(command1);*/

    //executes command but with the output of command_that_makes_input as the input instead of stdin
    //pipe(["echo", "hello", "there"], ["wc", "-w"]);
    //prints "2"
    /*show_prompt();
    char **command_that_makes_input = get_input(); //echo hello there
    char **command2 = get_input(); //wc -w
    sh_pipe(command_that_makes_input, command2);*/

    //executes command but with file of file_name as the output insted of stdout
    //redirect_output(["echo", "hello", "there"], "bobby.txt");
    //writes "hello there" to bobby.txt
    /*char **command3 = get_input(); //echo hello there
    char *file_name = "bobby.txt";
    redirect_output(command3, file_name);*/

    //executes command but with file of file_name as the input instead of stdin
    //redirect_input(["wc", "-w"], "bobby.txt");
    //prints whatever amount of words are in bobby.txt
    char **command4 = get_input(); //wc -w
    char *file_name2 = "bobby.txt";
    redirect_input(command4, file_name2);
}