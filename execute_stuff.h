void execute(char **command) {
  //executes command
  //execute(["echo", "hello", "there"])
  //prints "hello there"
}

void pipe(char **command_that_makes_input, char **command) {
  //executes command but with the output of command_that_makes_input as the input instead of stdin
  //pipe(["echo", "hello", "there"], ["wc", "-w"])
  //prints "2"
}

void redirect_output(char **command, char *file_name) {
  //executes command but with file of file_name as the output insted of stdout
  //redirect_output(["echo", "hello", "there"], "bobby.txt")
  //writes "hello there" to bobby.txt
}

void redirect_input(char **command, char *file_name) {
  //executes command but with file of file_name as the input instead of stdin
  //redirect_input(["wc", "-w"], "bobby.txt")
  //prints whatever amount of words are in bobby.txt
}
