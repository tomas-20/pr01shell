def get_text(filename):
  with open(filename) as file:
    return file.read()

print(get_text('input.c'))
