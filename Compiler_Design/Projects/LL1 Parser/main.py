parse_table = {
    "S" : {
        "a" : "aBa"
    },
    "B" : {
        "a" : "",
        "b" : "bB"
    }
}

stack = "$S"
word = input()
word = word + "$"

while len(stack) > 0:
    stackTop = stack[len(stack) - 1]
    inputFront = word[0]
    
    if stackTop in parse_table:
        stack = stack[:-1]
        production = parse_table[stackTop][inputFront]
        reversedProduction = production[::-1]
        stack = stack + reversedProduction
        
    elif stackTop == inputFront:
        if stackTop == "$":
            print("Successfully compiled")
            break
        
        stack = stack[:-1]
        word = word[1:]
    else:
        print("Error in compiling")
        break

