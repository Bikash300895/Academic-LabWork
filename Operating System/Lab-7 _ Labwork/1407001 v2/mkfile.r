app: main.o functions.o
	cc -o app main.o functions.o

main.o: main.c functions.h
	cc -c main.c

functions.o: functions.c functions.h
	cc -c functions.c