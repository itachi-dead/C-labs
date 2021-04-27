run: build
	./main.exe

build:
	clang main.c solution.c -o main.exe

test: build
	clang test.c solution.c -o test.exe
	./test.exe