#define _CRT_SECURE_NO_WARNINGS

#include "solution.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

short __SOLUTION_DAYS_IN_MONTHS[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char* __SOLUTION_MONTHS_NAMES[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
char* __SOLUTION_WEEK_DAYS[] = {"Monday", "Tuesday", "Wednesday", "Thirsday", "Friday", "Saturday", "Sunday"};

struct Date __SOLUTION_DEFAULT_DATE = {01, 01, 1970};


short calc_days_in_month(short year, short month_number) {

    short result = __SOLUTION_DAYS_IN_MONTHS[month_number - 1]; 
    if (is_leap_year(year) && month_number == 2) {
        result += 1;
    }
    return result;
}

short is_leap_year(short year) {
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

int read_number_forced(int min, int max) {
    int result;
    short is_read = 0;

    while (!is_read) {
        printf("Enter number from %d to %d\n", min, max);

        printf("Your choice: ");

        short read_success = scanf("%d", &result);

        if (!read_success || result < min || result > max) {
            printf("Invalid number. Please, try again");
            int n;
            while((n = getchar()) != EOF && n != '\n' );
        } else {
            is_read = 1;
        }

        printf("\n");
    }

    return result;
}

struct Date read_date() {
    printf("Enter year:\n");
    short year = read_number_forced(1, 9999);
    
    printf("Enter month:\n");
    short month = read_number_forced(1, 12);

    short max_days = calc_days_in_month(year, month);
    printf("Enter day:\n");
    short day = read_number_forced(1, max_days);

    struct Date result = {day, month, year};
    
    printf("\nOK\n");
    return result;
}

short is_number(char* str) {
    short result = 1;
    for (int i = 0; i < strlen(str); i++) {
        result = result && isdigit(str[i]);
        printf("%d %d\n", str[i], result);
    }
    return result;
}


short is_date_valid(struct Date date) {
    return (
        (date.year >= 1000 && date.year <= 9999)
        && (date.month >= 1 && date.month <= 12)
        && (date.day >= 1 && date.day <= calc_days_in_month(date.year, date.month))
    );
}


short PARCE_ERROR = 0;

struct Date parce_date() {
    PARCE_ERROR = 0;

    int day;

    if (scanf("%d", &day) != 1) {
        printf("Invalid day format\n");
        PARCE_ERROR = 1;
        return __SOLUTION_DEFAULT_DATE;
    }

    
    char month_s[100];
    scanf("%s", month_s);

    short month_valid = 0;
    short month;
    for (int i = 0; i < 12; i++) {
        
        if (strcmp(__SOLUTION_MONTHS_NAMES[i], month_s) == 0) {
            
            month_valid = 1;
            month = i + 1;
            break;
        }
    }

    if (!month_valid) {
        printf("Invalid month format\n");
        PARCE_ERROR = 1;
        return __SOLUTION_DEFAULT_DATE;
    }

    int year;

    if (scanf("%d", &year) != 1) {
        printf("Invalid year format\n");
        PARCE_ERROR = 1;
        return __SOLUTION_DEFAULT_DATE;
    }
    
    struct Date result = {day, month, year};
    if (!is_date_valid(result)) {
        printf("Invalid date\n");
        PARCE_ERROR = 1;
        return __SOLUTION_DEFAULT_DATE;
    } else {
        return result;
    }
}

struct Date read_date_month_name() {

    short is_read = 0;
    while (!is_read)
    {
        printf("Enter date: ");
        struct Date date = parce_date();

        if (PARCE_ERROR) {
            printf("Error. Try again\n\n");
        } else {
            is_read = 1;
            printf("\nOK\n");
            return date;
        }
        
    }

    return __SOLUTION_DEFAULT_DATE;
    
}

struct Date read_date_short() {

    short is_read = 0;
    while (!is_read)
    {
        int day;
        if (scanf("%d.", &day) != 1) {
            printf("Invalid day format\n");
            int n;
            while((n = getchar()) != EOF && n != '\n' );
            continue;
        }
        int month;
        if (scanf("%d.", &month) != 1) {
            printf("Invalid month format\n");
            int n;
            while((n = getchar()) != EOF && n != '\n' );
            continue;
        }
        int year;
        if (scanf("%d", &year) != 1) {
            printf("Invalid month format\n");
            int n;
            while((n = getchar()) != EOF && n != '\n' );
            continue;
        }
        year += 2000;

        struct Date result = {day, month, year};
        if (!is_date_valid(result)) {
            printf("Invalid date\n");
        } else {
            is_read = 1;
            return result;
        }
    }

    
    return __SOLUTION_DEFAULT_DATE;
    
    
}

void increment_date(struct Date* date) {
        date->day++;

        if (date->day > calc_days_in_month(date->year, date->month)) {
            date->day = 1;
            date->month++;
        }

        if (date->month > 12) {
            date->year++;
            date->month = 1;
        }
}



short DAY_IN_YEAR;
short DAY_OF_WEEK;
int DAY_FROM_BEGGINNIG;


void run_timeline(struct Date date, struct Date current) {
    DAY_IN_YEAR = 1;
    DAY_OF_WEEK = 5;
    DAY_FROM_BEGGINNIG = 0;

    while (current.year != date.year || current.month != date.month || current.day != date.day)
    {
        DAY_OF_WEEK = (DAY_OF_WEEK + 1) % 7;
        DAY_IN_YEAR++;
        DAY_FROM_BEGGINNIG++;

        short old_year = current.year;
        increment_date(&current);

        if (current.year != old_year) {
            DAY_IN_YEAR = 1;
        }
        
    }
}

char* calc_day_of_week(struct Date date) {
    struct Date begin_date = {1, 1, 1583}; 
    run_timeline(date, begin_date);

    return __SOLUTION_WEEK_DAYS[DAY_OF_WEEK];
     
}

short calc_day_in_year(struct Date date) {
    
    struct Date begin_date = {1, 1, 1583};
    run_timeline(date, begin_date);

    return DAY_IN_YEAR;
}

int calc_day_from_Christ(struct Date date) {
    
    struct Date begin_date = {1, 1, 1};
    run_timeline(date, begin_date);

    return DAY_FROM_BEGGINNIG;
}
