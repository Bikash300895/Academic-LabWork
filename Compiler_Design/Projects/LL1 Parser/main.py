parse_table = {
    "S" : {
        "a" : "aBa"
    },
    "B" : {
        "a" : None,
        "b" : "bB"
    }
}

stack = "$S"
word = "abba"

while len(stack) >0:
    stackTop = stack[len(stack) - 1]
    inputFront = word[0]

