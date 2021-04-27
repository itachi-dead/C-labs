#define OPTIONS_CNT 5

#include <stdio.h>
#include "solution.h"

char* options[OPTIONS_CNT] = {
    "Enter date",
    "Enter date as DD MMMM YYYY",
    "Enter date as DD.MM.YY",
    "Author",
    "Exit"
};


int main(void) {

    short running = 1;

    struct Date current_date = {1, 1, 1970};

    while (running)
    {
        printf("Current date: %02d.%02d.%04d", current_date.day, current_date.month, current_date.year);

        if (current_date.year >= 1583) {
            char* day_of_week = calc_day_of_week(current_date);
            short day_in_year = calc_day_in_year(current_date);
            printf(", %s, %d day in year\n", day_of_week, day_in_year);
        } else {
            printf("\n");
        }

        printf("Day from Christ birth: %d\n\n", calc_day_from_Christ(current_date));

        printf("Menu\n");

        for (short option = 0; option < OPTIONS_CNT; option++) {
            printf("%d. ", option + 1);
            printf("%s\n", options[option]);
        }
        printf("\n");
        int choice = read_number_forced(1, OPTIONS_CNT);

        switch (choice)
        {
        case 1:
            current_date = read_date();
            break;

        case 2:
            current_date = read_date_month_name();
            break;

        case 3:
            current_date = read_date_short();
            break;
        
        case 4:
            printf("Savely Volodkov\n2021, Minsk, BSUIR\n");
            break;
        case 5:
            running = 0;
            continue;

        default:
            break;
        }


        printf("\nPress Enter to continue\n");

        getchar();
        getchar();


    }
    
}