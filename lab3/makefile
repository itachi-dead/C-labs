build:
	clang main.c solution.c -o main.exe

run: build
	./main.exe

test: build
	clang test.c solution.c -o test.exe
	./test.exe