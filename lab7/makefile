buildMain:
	g++ -o main main.cpp

buildTest: buildMain
	g++ -o main_test -Dmain=_main main.cpp tests.cpp