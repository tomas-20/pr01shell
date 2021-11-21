#include <stdio.h>
#include "input.h"

int main() {
  char **bobby = get_input("input cheese:", 2187);
  for (char **sp = bobby; *sp; sp ++) {
    printf("(%s)\n", *sp);
  }
  free_strings(bobby);
  return 0;
}
