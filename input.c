#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_input(int n) {
  char *input = malloc(sizeof (char[n]));
  fgets(input, n, stdin);
  return input;
}

void cheese(char *string) {
  int size = 0;
  while (string) {
    char *portion = strsep(&string, " ");
    printf("(%s)\n", portion);
    if (*portion) {
      size ++;
    }
  }
  printf("size is:%d\n", size);
}

int main() {
  printf("input thingy: ");
  char *bobby = get_input(2187);
  cheese(bobby);
  return 0;
}
