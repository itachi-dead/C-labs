#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include "lab1_task2.h"
#include<stdbool.h>

int main() {
	int sum = 0;
	bool equal = true;
	for (int i = 10; i < 100; i++)
	{
		sum = sumOfDigits(i);
		for (int j = 2; j <= 9; j++) {
			if (sum != check(i, j)) {
				equal = false;
				break;
			}
		}
		if (equal)
		{
			printf("\n%d", i);
		}
		equal = true;
	}
	return 0;
}
