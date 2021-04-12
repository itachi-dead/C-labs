build: clean buildProgram

run:
	.\bin\program.exe

test: buildTest
	.\bin\test.exe

buildTest:
	g++ .\src\test\test.c .\src\test\runner.c  .\src\lab1_task2.c -o bin\test.exe

buildProgram:
	g++ src\main.c src\lab1_task2.c -o bin\program.exe

clean:
	-del bin\* /Q /F
	-rmdir bin
	mkdir bin


	