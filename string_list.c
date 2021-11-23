#include <stdlib.h>
#include <string.h>

struct string_list {
  struct string_list_node *node;
  int chrlen;
};

struct string_list_node {
  char *value;
  int length;
  struct string_list_node *next;
};

struct string_list_node *get_string_list_node(char *value, struct string_list_node *next) {
  struct string_list_node *node = malloc(sizeof (struct string_list_node));
  node->value = malloc(sizeof (char[node->length + 1]));
  strcpy(node->value, value);
  node->length = strlen(value);
  node->next = next;
  return node;
}

struct string_list *get_string_list() {
  struct string_list *list = malloc(sizeof (struct string_list));
  list->node = NULL;
  list->chrlen = 0;
  return list;
}

void add_string(struct string_list *list, char *value) {
  list->node = get_string_list_node(value, list->node);
  list->chrlen += list->node->length + 1;
}

void remove_string(struct string_list *list) {
  struct string_list_node *node = list->node;
  list->node = node->next;
  list->chrlen -= node->length + 1;
  free(node->value);
  free(node);
}

void empty_string_list(struct string_list *list) {
  while (list->node) {
    remove_string(list);
  }
}

char *get_first_string(struct string_list *list) {
  if (list->node) {
    return list->node->value;
  }
  else {
    return NULL;
  }
}

char *get_path_string(struct string_list *list, char *ending) {
  int path_string_length = list->chrlen + 1 + strlen(ending);
  char *path_string = malloc(sizeof (char[path_string_length + 1]));
  char *sp = path_string + path_string_length;
  sp -= strlen(ending);
  strcpy(sp, ending);
  for (struct string_list_node *node = list->node; node; node = node->next) {
    sp --;
    *sp = '/';
    sp -= node->length;
    strncpy(sp, node->value, node->length);
  }
  sp --;
  *sp = '/';
  return path_string;
}
