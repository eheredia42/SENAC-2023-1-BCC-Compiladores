.PHONY: all run build clean teste format valgrind
.ONESHELL :
path = src

all: build

run: src/main.out
	cd $(path)
	./main.out ./hello_world.txt

build: src/main.out

src/main.out: src/main.c
	cd $(path)
	gcc -W -Wall -std=c11 -pedantic -g main.c -o main.out

clean:
	rm -f src/main.out

teste:
	cd $(path)
	./main.out ./nested_loop.txt

format:
	clang-format -i -style=file **/*.c 

valgrind:
	valgrind --leak-check=full ./src/main.out ./src/hello_world.txt 