struct string_list *get_string_list();
void free_string_list(struct string_list *);
void add_string(struct string_list *, char *);
void remove_string(struct string_list *);
char *get_first_string(struct string_list *);
char *get_path_string(struct string_list *, char *);
