#include <stdlib.h>
#include <string.h>

struct string_list {
  int chrlen;
  struct string_list_node *node;
};

struct string_list_node {
  char *value;
  int length;
  struct string_list_node *next;
};

struct string_list_node *get_string_list_node(char *value, struct string_list_node *next) {
  struct string_list_node *node = malloc(sizeof (struct string_list_node));
  node->length = strlen(value);
  node->value = malloc(sizeof (char[node->length + 1]));
  strcpy(node->value, value);
  node->next = next;
  return node;
}

struct string_list *get_string_list() {
  struct string_list *list = malloc(sizeof (struct string_list));
  list->node = NULL;
  list->chrlen = 0;
  return list;
}

void free_string_list_node(struct string_list_node *node) {
  if (node) {
    free(node->value);
    free_string_list_node(node->next);
    free(node);
  }
}

void free_string_list(struct string_list *list) {
  free_string_list_node(list->node);
  free(list);
}

void add_string(struct string_list *list, char *value) {
  list->node = get_string_list_node(value, list->node);
  list->chrlen += list->node->length + 1;
}

void remove_string(struct string_list *list) {
  list->chrlen -= list->node->length + 1;
  list->node = list->node->next;
}

char *get_path_string(struct string_list *list, char *ending) {
  int path_string_length = list->chrlen + strlen(ending) + 1;
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
