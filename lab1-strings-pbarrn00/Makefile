c11_gcc: ejemplo1.c
	gcc -Wall -pedantic -std=c11 ejemplo1.c -o ejemplo1.o

c99_gcc: ejemplo1.c
	gcc -Wall -pedantic -std=c99 ejemplo1.c -o ejemplo1.o

c11_g++: ejemplo1.c
	g++ -Wall -pedantic -std=c++11 ejemplo1.c -o ejemplo1.o

c99_g++: ejemplo1.c
	g++ -Wall -pedantic -std=c++98 ejemplo1.c -o ejemplo1.o

asan: ejemplo2.c
	gcc ejemplo2.c -Wall -std=c11 -o ejemplo2.o -fsanitize=address -static-libasan -g

clean:
	@echo "Cleaning outputs... "
	rm -rf *.o
