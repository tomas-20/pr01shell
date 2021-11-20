#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_input(char *prompt, int max_size) {
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
    words[i] = string;
    string = strchr(string, '\0');
  }
  words[word_count] = NULL;
  return words;
}

int main() {
  char *bobby = get_input("input cheese:", 2187);
  int bobby_word_count = split(bobby);
  char **bobby_words = get_words(bobby, bobby_word_count);
  for (int i = 0; bobby_words[i]; i ++) {
    printf("(%s)\n", bobby_words[i]);
  }
  return 0;
}
