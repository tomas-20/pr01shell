#include <stdlib.h>
#include <string.h>

int split(char *string) {
  int word_count = 0;
  while (string) {
    if (*strsep(&string, " ")) {
      word_count ++;
    }
  }
  return word_count;
}

char **get_words(char *string) {
  int word_count = split(string);
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
