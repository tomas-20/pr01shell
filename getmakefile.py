from sys import argv

def mapa(*args):
    return list(map(*args))

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
    wordss = mapa(get_words, lines)
    return filtrar(mapa(get_dep, wordss))

def add_h(file_name):
    return file_name + '.h'

def get_file_code(file_name):
    dep_string = ' '.join(mapa(add_h, get_deps(file_name)))
    return f'{file_name}.o: {dep_string}\n\tgcc -c {file_name}.c'

def add_o(file_name):
    return file_name + '.o'

def get_option_code(option, file_name):
    all_dep_string = ' '.join(mapa(add_o, get_all_deps([file_name])))
    return f'{option}: {all_dep_string}\n\tgcc {all_dep_string}\n\trm *.o'

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

def get_code(options, file_names):
    option_code = '\n'.join(mapa(get_option_code, options, file_names))
    file_code = '\n'.join(mapa(get_file_code, get_all_deps(file_names)))
    return option_code + '\nclean:\n\trm *.o\n\n' + file_code

def get_pair(arg):
    return arg.split(':')

def get_option(pair):
    return pair[0]

def get_file_name(pair):
    return pair[1]

pairs = mapa(get_pair, argv[1:])
code = get_code(mapa(get_option, pairs), mapa(get_file_name, pairs))
print(code)
