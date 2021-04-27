run: build
	./task.exe

build: task2.c
	clang task2.c -o task.exe
	
test: task2.c task2test.c
	clang -o test.exe task2test.c task2.c -D TESTING 
	./test.exe