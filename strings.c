#include <stdlib.h>
#include <string.h>

char **strssep(char ***stringsp, char *delim) {
  char **original = *stringsp;
  for (char **strings = original; *strings; strings ++) {
    if (!strcmp(*strings, delim)) {
      *strings = NULL;
      *stringsp = strings + 1;
      return original;
    }
  }
  *stringsp = NULL;
  return original;
}

int strslen(char **strings) {
  int length = 0;
  for (char **sp = strings; *sp; sp ++) {
    length ++;
  }
  return length;
}

char **strscpy(char **dest, char **source) {
  char **original = dest;
  while ((*dest = *source)) {
    dest ++;
    source ++;
  }
  return original;
}
