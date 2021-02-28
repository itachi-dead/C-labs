#include "lab1_task2.h"
#include <assert.h>
#include<cassert>
int test_sum() {
    assert(sumOfDigits(27) == 9);
}
#undef main
int main() {
    test_sum();
}