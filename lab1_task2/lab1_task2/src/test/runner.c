#include <stdio.h>

#include "test.h"

#define TEST_SIZE 5

struct TestDataSum data[TEST_SIZE] = {
    {0, 0},
    {5, 5},
    {123, 6},
    {1000001, 2},
    {2147483647, 46},
};


int main(void) {


    int testsOk = 0;
    
    for (int testNum = 0; testNum < TEST_SIZE; testNum++) {
        char header[15];
        sprintf(header, "Test %d", testNum + 1);
        int testResult = runTestSum(&data[testNum], header);
        if (testResult >= 0) {
            testsOk++;
        }
    }

    printf("Finished\n");
    printf("Total tests: %d\n", TEST_SIZE);
    printf("Passed: %d\n", testsOk);
    printf("Failed: %d\n", TEST_SIZE - testsOk);

}