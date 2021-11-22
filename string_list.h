struct string_list_node {
  char *value;
  int length;
  struct string_list_node *next;
};
struct string_list *get_string_list();
void add_string(struct string_list *, char *);
void remove_string(struct string_list *);
char *get_path_string(struct string_list *, char *);
