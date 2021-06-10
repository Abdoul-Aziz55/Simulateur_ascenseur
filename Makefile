all:main
FLAGS = -Wall -Werror -g

main.o: main.c person.h elevator.h
	gcc ${FLAGS} -c main.c

person.o: person.c person.h
	gcc ${FLAGS} -c person.c

elevator.o: elevator.c elevator.h person.c person.h
	gcc ${FLAGS} -c elevator.c

main: main.o person.o elevator.o
	gcc ${FLAGS} -o main person.o elevator.o main.o -lncurses

clean:
	rm -f *.o ./main

