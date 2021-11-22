#include <stdio.h>
#include "run.h"
#include "string_list.h"

int main() {
  struct string_list *path = get_string_list();
  add_string(path, "hello");
  add_string(path, "there");
  add_string(path, "good");
  add_string(path, "sir");
  remove_string(path);
  printf("%s\n", get_path_string(path, "epic"));
  free_string_list(path);
  return 0;
}
