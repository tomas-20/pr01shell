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

int main() {
  printf("input thingy: ");
  char *bobby = get_input(2187);
  int bobby_words = get_word_count(bobby);
  return 0;
}
