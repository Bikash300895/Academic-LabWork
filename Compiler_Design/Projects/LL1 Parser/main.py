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
