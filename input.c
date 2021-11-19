#include <stdio.h>
#include <stdlib.h>

char *get_input(int n) {
  char *input = malloc(sizeof (int[n]));
  fgets(input, n, stdin);
  return input;
}

int main() {
  printf("input thingy: ");
  char *bobby = get_input(2187);
  printf("%s", bobby);
  return 0;
}
