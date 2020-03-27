FLAGS = -W -Wall -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -fstack-protector-all -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wcast-align -Wno-long-long -Wmissing-declarations -O3


all: a01.out a02.out a03.out a04.out a05.out a06.out a07.out a08.out a09.out a10.out a11.out


matrix.o: matrix.c matrix.h
	gcc $(FLAGS) -c matrix.c -o matrix.o


a01.out: main01.o matrix.o solve01.o
	gcc $(FLAGS) -lm main01.o matrix.o solve01.o -o a01.out
main01.o: main01.c
	gcc $(FLAGS) -c main01.c -o main01.o
solve01.o: solve01.c solve01.h
	gcc $(FLAGS) -c solve01.c -o solve01.o


a02.out: main02.o matrix.o solve02.o
	gcc $(FLAGS) -lm main02.o matrix.o solve02.o -o a02.out
main02.o: main02.c
	gcc $(FLAGS) -c main02.c -o main02.o
solve02.o: solve02.c solve02.h
	gcc $(FLAGS) -c solve02.c -o solve02.o


a03.out: main03.o matrix.o solve03.o
	gcc $(FLAGS) -lm main03.o matrix.o solve03.o -o a03.out
main03.o: main03.c
	gcc $(FLAGS) -c main03.c -o main03.o
solve03.o: solve03.c solve03.h
	gcc $(FLAGS) -c solve03.c -o solve03.o


a04.out: main04.o matrix.o solve04.o
	gcc $(FLAGS) -lm main04.o matrix.o solve04.o -o a04.out
main04.o: main04.c
	gcc $(FLAGS) -c main04.c -o main04.o
solve04.o: solve04.c solve04.h
	gcc $(FLAGS) -c solve04.c -o solve04.o


a05.out: main05.o matrix.o solve05.o
	gcc $(FLAGS) -lm main05.o matrix.o solve05.o -o a05.out
main05.o: main05.c
	gcc $(FLAGS) -c main05.c -o main05.o
solve05.o: solve05.c solve05.h
	gcc $(FLAGS) -c solve05.c -o solve05.o


a06.out: main06.o matrix.o solve06.o
	gcc $(FLAGS) -lm main06.o matrix.o solve06.o -o a06.out
main06.o: main06.c
	gcc $(FLAGS) -c main06.c -o main06.o
solve06.o: solve06.c solve06.h
	gcc $(FLAGS) -c solve06.c -o solve06.o


a07.out: main07.o matrix.o solve07.o
	gcc $(FLAGS) main07.o matrix.o solve07.o -o a07.out
main07.o: main07.c
	gcc $(FLAGS) -c main07.c -o main07.o
solve07.o: solve07.c solve07.h
	gcc $(FLAGS) -c solve07.c -o solve07.o


a08.out: main08.o matrix.o solve08.o
	gcc $(FLAGS) main08.o matrix.o solve08.o -o a08.out
main08.o: main08.c
	gcc $(FLAGS) -c main08.c -o main08.o
solve08.o: solve08.c solve08.h
	gcc $(FLAGS) -c solve08.c -o solve08.o


a09.out: main09.o matrix.o solve09.o
	gcc $(FLAGS) main09.o matrix.o solve09.o -o a09.out
main09.o: main09.c
	gcc $(FLAGS) -c main09.c -o main09.o
solve09.o: solve09.c solve09.h
	gcc $(FLAGS) -c solve09.c -o solve09.o


a10.out: main10.o matrix.o solve10.o
	gcc $(FLAGS) main10.o matrix.o solve10.o -o a10.out
main10.o: main10.c
	gcc $(FLAGS) -c main10.c -o main10.o
solve10.o: solve10.c solve10.h
	gcc $(FLAGS) -c solve10.c -o solve10.o


a11.out: main11.o matrix.o solve11.o
	gcc $(FLAGS) -lm main11.o matrix.o solve11.o -o a11.out
main11.o: main11.c
	gcc $(FLAGS) -c main11.c -o main11.o
solve11.o: solve11.c solve11.h
	gcc $(FLAGS) -c solve11.c -o solve11.o
