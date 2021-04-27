#include "solution.h"
#include <assert.h>
#include <stdio.h>


int main(void) {

    assert(is_leap_year(2004) > 0);
    assert(is_leap_year(1000) == 0);
    assert(is_leap_year(2000) > 0);

    assert(calc_days_in_month(2000, 2) == 29);
    assert(calc_days_in_month(2001, 2) == 28);
    assert(calc_days_in_month(2003, 5) == 31);

    struct Date test_date = {1, 1, 1};
    assert(calc_day_from_Christ(test_date) == 0);
    
    test_date.month = 2;
    assert(calc_day_from_Christ(test_date) == 31);
    
    test_date.year = 2;

    assert(calc_day_from_Christ(test_date) == 365 + 31);

    printf("Tests OK");
}