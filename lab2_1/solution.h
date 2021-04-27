#ifndef SOLUTION_H
#define SOLUTION_H


struct Date {
    short day, month, year;
};

short calc_days_in_month(short year, short month_number);

short is_leap_year(short year);

int read_number_forced(int min, int max);

struct Date read_date();

struct Date read_date_month_name();

struct Date read_date_short();

char* calc_day_of_week(struct Date date);

short calc_day_in_year(struct Date date);


int calc_day_from_Christ(struct Date date);

#endif //SOLUTION_H