#include "mylib.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STRINGS_AMOUNT 10

#define MAX_STRING_LENGTH 80

void test() {
   char text[MAX_STRINGS_AMOUNT][MAX_STRING_LENGTH] = { "New blood joins this Earth", "And quickly he's subdued",\
   "Through constant pained disgrace", "The young boy learns their rules", "With time the child draws in",\
   "This whipping boy done wrong", "Deprived of all his thoughts", "The young man struggles on and on, he's knows",\
   "Ooh, a temp unto his own", "That never from this day" };
   letters temp_test = get_info(text);
   assert(temp_test.a_amount == 13);
   assert(temp_test.e_amount == 20);
   assert(temp_test.i_amount == 17);
   assert(temp_test.o_amount == 22);
   assert(temp_test.u_amount == 10);
   assert(temp_test.y_amount == 6);
}

#undef main

int main()
{
   test();
   return 0;
}