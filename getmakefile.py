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
            return dep.strip('.h')
    return False

def get_deps(file_name):
    file_name_c = file_name + '.c'
    with open(file_name_c) as file:
        text = file.read()
    lines = text.split('\n')
    wordss = map(get_words, lines)
    return filtrar(map(get_dep, wordss))

def add_h(file_name):
    return file_name + '.h'

def get_file_code(file_name, deps):
    dep_string = ' '.join(map(add_h, deps))
    return f'{file_name}.o: dep_string\n\tgcc -c {file_name}.c'

def fill_all_deps(all_deps, file_name):
    deps = get_deps(file_name)
    for dep in deps:
        if not dep in all_deps:
            all_deps.append(dep)
            fill_all_deps(all_deps, dep)

def get_all_deps(file_names):
    all_deps = file_names[:]
    for file_name in file_names:
        fill_all_deps(all_deps, file_name)
    return all_deps

from sys import argv
all_deps = get_all_deps(argv[1:])
for dep in all_deps:
    print(dep)
