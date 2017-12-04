bison -d main.y
flex main.l
gcc lex.yy.c main.tab.c -o run
run