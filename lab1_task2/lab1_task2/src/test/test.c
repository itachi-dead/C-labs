#include <stdio.h>

#include "..\lab1_task2.h"
#include "test.h"


int runTestSum(struct TestDataSum* data, char* header) {
    int answer = data-> answer;
    int code;
    printf("--------------------------------------\n");
    printf("%s\n", header);
    int result = sumOfDigits(data->number);
    
    printf("Answer = %d, result = %d\n", answer, result);
    if (result != answer) {
        printf("Error: %d != %d\n", answer, result);
        printf("Test failed: expected %d, got %d\n", answer, result);
        code = -1;
    } else {
        printf("Test OK\n");
        code = 0;
    }
    printf("--------------------------------------\n\n");
    return code;
    
}
