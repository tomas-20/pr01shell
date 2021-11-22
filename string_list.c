#include <stdlib.h>
#include <string.h>

struct string_list {
  int chrlen;
  struct string_list_node *node;
};

struct string_list_node {
  char *value;
  int chrlen;
  struct string_list_node *next;
};

struct string_list_node *get_string_list_node(char *value, struct string_list_node *next) {
  struct string_list_node *node = malloc(sizeof (struct string_list_node));
  node->value = value;
  node->chrlen = strlen(value) + 1;
  node->next = next;
  return node;
}

struct string_list *get_string_list() {
  struct string_list *list = malloc(sizeof (struct string_list));
  list->node = NULL;
  list->chrlen = 0;
  return list;
}

void add_value(struct string_list *list, char *value) {
  list->node = get_string_list_node(value, list->node);
  list->chrlen += list->node->chrlen;
}

void remove_value(struct string_list *list) {
  list->chrlen -= list->node->chrlen;
  list->node = list->node->next;
}
