
#include <assert.h>
#include <stdio.h>
#include <string>

#include "main.h"

void main_test() {
	string str = GetStudentName();
	assert(str == "Putin");
	str = GetStudentName();
	assert(str == "Gonchar");
	str = GetStudentName();
	assert(str == "Obeme");
	str = GetStudentgroupNumber();
	assert(str == "053502");
	str = GetStudentgroupNumber();
	assert(str == "100000");
	str = GetStudentgroupNumber();
	assert(str == "053504");
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