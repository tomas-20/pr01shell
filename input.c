#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_input(int n) {
  char *input = malloc(sizeof (char[n]));
  fgets(input, n, stdin);
  input = strsep(&input, "\n");
  return input;
}

int get_word_count(char *string) {
  int word_count = 0;
  while (string) {
    char *portion = strsep(&string, " ");
    printf("(%s)\n", portion);
    if (*portion) {
      word_count ++;
    }
  }
  printf("word count: %d\n", word_count);
  return word_count;
}

char **get_words(char *string, int word_count) {
  char **words = malloc(sizeof (char[word_count]));
  for (int i = 0; i < word_count; i ++) {
    while (!*string) {
      string ++;
    }
    words[i] = string;
    string += strlen(string);
  }
  return words;
}

int main() {
  printf("input thingy: ");
  char *bobby = get_input(2187);
  int bobby_word_count = get_word_count(bobby);
  char **bobby_words = get_words(bobby, bobby_word_count);
  for (int i = 0; i < bobby_word_count; i ++) {
    printf("[%s]\n", bobby_words[i]);
  }
  return 0;
}
