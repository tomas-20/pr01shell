def get_text(file_name):
  with open(file_name) as file:
    return file.read()

def get_lines(text):
  return text.split('\n')

def same(thing):
  return thing

def filtrar(listo):
  return filter(same, listo)

def get_words(line):
  return filtrar(line.split(' '))

def get_wordss(text):
  return map(get_words, get_lines(text))

def get_dep(words):
  return len(words) > 1 and words[0] == '#include' and words[1]

text = get_text('input.c')
wordss = get_wordss(text)
for words in wordss:
  print(list(words))
