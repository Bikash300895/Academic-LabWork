def isTerminal(char):
    if "A" <= char <= "Z":
        return False
    else:
        return True


parse_table = {
    "S": {
        "a": "aBa"
    },
    "B": {
        "a": "",
        "b": "bB"
    }
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




stack = "$S"
word = input()
word = word + "$"

while len(stack) > 0:
    stackTop = stack[len(stack) - 1]
    inputFront = word[0]

    # Check if stack top is not terminal
    if stackTop in parse_table:
        stack = stack[:-1]
        production = parse_table[stackTop][inputFront]
        reversedProduction = production[::-1]
        stack = stack + reversedProduction

    # if terminal and same input
    elif stackTop == inputFront:
        if stackTop == "$":
            print("Successfully compiled")
            break

        stack = stack[:-1]
        word = word[1:]
    else:
        print("Error in compiling")
        break
