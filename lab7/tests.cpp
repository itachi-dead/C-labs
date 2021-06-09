
#include <assert.h>
#include <stdio.h>
#include <string>
#include "main.h"
using namespace std;
struct Question{
	int first;
	int second;
	int third;
	int fourth;
	int fifth;
};

void main_test() {
	string str = GetStudentName();
	assert(str.empty()?0:1);

	str = GetStudentName();
	assert(str.empty()?0:1);

	str = GetStudentName();
	assert(str.empty()?0:1);

	str = GetStudentgroupNumber();
	assert(str.empty()?0:1);

	str = GetStudentgroupNumber();
	assert(str.empty()?0:1);

	str = GetStudentgroupNumber();
	assert(str.empty()?0:1);
	
	int scores = 0;
	int t = test();
	assert(t == 40);
	t = test();
	assert(t == 10);
	t = test();
	assert(t == 0);
	printf("Got it\n");
}

#undef main

int main() {
	main_test();
	return 0;
}