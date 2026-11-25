#include <time.h>
#include<stdio.h>

int main()
{
    int year, month, day;
    int days[] = {31, 28, 31, 30, 31, 30,
                  31, 31, 30, 31, 30, 31};

    char *months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    printf("Enter year: ");
    scanf("%d", &year);

   
    if ((year % 400 == 0) ||
        (year % 4 == 0 && year % 100 != 0))
    {
        days[1] = 29;
    }

   
    struct tm date = {0};
    date.tm_year = year - 1900;
    date.tm_mon = 0;
    date.tm_mday = 1;

    time_t t = mktime(&date);
    struct tm *first = localtime(&t);

    int start = first->tm_wday;

   
    for (month = 0; month < 12; month++)
    {
        printf("\n\n        %s %d\n", months[month], year);
        printf("Sun Mon Tue Wed Thu Fri Sat\n");

        
        for (day = 1; day <= days[month]; day++)
        {
            printf("%3d ", day);
            start++;
            if (start > 6)
            {
                start = 0;
                printf("\n");
            }
        }
        
        start %= 7;
    }

    return 0;
}
