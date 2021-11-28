#include <stdlib.h>
#include <string.h>

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
    words[i] = strcpy(malloc(sizeof (char[strlen(string) + 1])), string);
    while (*string) {
      string ++;
    }
  }
  words[word_count] = NULL;
  return words;
}
