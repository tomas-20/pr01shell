def same(thing):
    return thing

def filtrar(listo):
    return list(filter(same, listo))

def get_words(line):
    return filtrar(line.split(' '))

def get_dep(words):
    if len(list(words)) >= 2 and words[0] == '#include':
        dep = words[1].strip('"')
        if dep != words[1]:
            return dep
    return False

def get_deps(file_name):
    file_name_c = file_name + '.c'
    with open(file_name_c) as file:
        text = file.read()
    lines = text.split('\n')
    wordss = map(get_words, lines)
    return filtrar(map(get_dep, wordss))

for dep in get_deps('input'):
    print(dep)
