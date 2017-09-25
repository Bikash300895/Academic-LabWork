def isTerminal(char):
    if "A" <= char <= "Z":
        return True
    else:
        return False


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
