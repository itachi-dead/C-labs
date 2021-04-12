#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include "lab1_task2.h"
#include<stdbool.h>

int sumOfDigits(int number) {
	int sum = 0;

	while (number > 0)
	{
		int lastDigit = number % 10;
		sum += lastDigit;
		number /= 10;
	}
	return sum;
}

int check(int number, int x) {
	
	number *= x;
	int sum = sumOfDigits(number);
	return sum;
}