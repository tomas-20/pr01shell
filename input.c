#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_input_string(char *prompt, int max_size) {
  printf("%s ", prompt);
  char *input = malloc(sizeof (char[max_size]));
  fgets(input, max_size, stdin);
  return strsep(&input, "\n");
}

int split(char *string) {
  int word_count = 0;
  while (string) {
    if (*strsep(&string, " ")) {
      word_count ++;
    }
  }
  return word_count;
}

char **get_words(char *string, int word_count) {
  char **words = malloc(sizeof (char *[word_count + 1]));
  for (int i = 0; i < word_count; i ++) {
    while (!*string) {
      string ++;
    }
    char *word = malloc(sizeof (char[strlen(string) + 1]));
    strcpy(word, string);
    words[i] = word;
    string = strchr(string, '\0');
  }
  words[word_count] = NULL;
  return words;
}

char **get_input(char *prompt, int max_size) {
  char *input_string = get_input_string(prompt, max_size);
  int word_count = split(input_string);
  free(input_string);
  return get_words(input_string, word_count);
}

int main() {
  char **bobby = get_input("input cheese:", 2187);
  for (int i = 0; bobby[i]; i ++) {
    printf("(%s)\n", bobby[i]);
  }
  return 0;
}
