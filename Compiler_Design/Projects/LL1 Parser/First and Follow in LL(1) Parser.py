def isTerminal(char):
    if "A" <= char <= "Z":
        return False
    else:
        return True


parse_table = {
    # "S": {
    #     "a": "aBa"
    # },
    # "B": {
    #     "a": "",
    #     "b": "bB"
    # }
}

grammer = {}
start = ""

with open("grammer.txt") as f:
    firstLine = f.readline()
    start = firstLine[0]
    f.close()

# Taking input from input file
with open("grammer.txt") as f:
    for line in f:
        variable = line[0]
        grammer[variable] = []
        production = ""
        for i in range(3, len(line)):
            if line[i] == '\n':
                break
            elif line[i] != '/':
                production += line[i]
            else:
                grammer[variable].append(production)
                production = ""
        grammer[variable].append(production)
    f.close()

# Calculating first
first = {}


def findFirst(x):
    # see if already calculated
    if x in first:
        return first[x]

    # If X is a terminal then First(X) ={X}
    if isTerminal(x):
        first[x] = x
        return x
    else:
        # Get all the productions
        productions = grammer[x]
        currentFirst = set()

        # If there is a Production X → ε then add ε to first(X)
        if '@' in productions:
            currentFirst = {'@'}
        for product in productions:
            if isTerminal(product[0]):
                currentFirst.add(product[0])
            else:
                currentFirst.update(findFirst(product[0]))
    first[x] = currentFirst
    return currentFirst


# Calculate all the first()
for key, ls in grammer.items():
    findFirst(key)

# Calculate follow
follow = {}
follow[start] = {"$"}


def findFirstinFollow(key, x):
    follows = set()
    if x == "":
        if key in follow:
            return follow[key]
        else:
            return {}

    firsts = findFirst(x[0])
    for i in firsts:
        if i == '@':
            follows.update(findFirstinFollow(key, x[1:]))
        else:
            follows.add(i)

    return follows


def findFollow():
    # saperate all the production rules
    for key, values in grammer.items():
        for product in values:
            for index in range(len(product)):
                if not isTerminal(product[index]):
                    # initialize empty set if it is encountered first time
                    if product[index] not in follow:
                        follow[product[index]] = set()

                    if index != len(product) - 1:
                        follow[product[index]].update(findFirstinFollow(key, product[index + 1:]))
                    else:
                        if key in follow:
                            follow[product[index]].update(follow[key])


for i in range(5):
    findFollow()
# print(follow)


# Creating parse table
for key, value in grammer.items():
    parse_table[key] = {}
    for production in value:
        if isTerminal(production[0]):
            if production[0] == "@":
                followofFirstTerm = follow[key]
                for f in followofFirstTerm:
                    parse_table[key][f] = ""
            else:
                parse_table[key][production[0]] = production

        else:
            firstofProduction = first[production[0]]
            for f in firstofProduction:
                parse_table[key][f] = production

stack = "$" + start
word = input()
word = word + "$"
print(stack.ljust(20), end="\t")
print(word.ljust(20), end="\t")

while len(stack) > 0:
    stackTop = stack[len(stack) - 1]
    inputFront = word[0]

    # Check if stack top is not terminal (variable)
    if stackTop in parse_table:
        stack = stack[:-1]
        try:
            production = parse_table[stackTop][inputFront]
        except:
            print("Grammar not defined for this...")
        reversedProduction = production[::-1]
        stack = stack + reversedProduction

        # change the name of production in case of epsilon
        if production == "":
            print("")
        else:
            print(stackTop, "->", production)

        print(stack.ljust(20), end="\t")
        print(word.ljust(20), end="\t")


    # if terminal and same input
    elif stackTop == inputFront:
        if stackTop == "$":
            print("Successfully compiled")
            break

        stack = stack[:-1]
        word = word[1:]
    else:
        print("Error in compilation")
        break
