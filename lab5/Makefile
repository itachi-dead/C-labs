all: buildMain buildTest runTest

buildMain:
	g++ -o main main.cpp

buildTest:
	g++ -o main_test -Dmain=_main main.cpp main_test.cpp

runTest:
	./main_test

	