#include <stdio.h>
#include <math.h>

static int days_in_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
static char *day_of_week_name[7] = { "mon", "tue", "wed", "thu", "fri", "sat", "sun" };

bool is_leap_year(const int year) {
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int get_leap_years_quantity(const int year) {
    int result = 0;
    for (int i = 1600; i < year; i++) {
        if (is_leap_year(i))
            result++;
    }

    return result;
}

int get_days_from_year_started(const int day, const int month, const int year) {
    int leapInc = (month > 2 && is_leap_year(year)) ? 1 : 0;
    int result = 0;
    for (int i = 0; i < month - 1; i++) {
        result += days_in_month[i];
    }

    return result + leapInc + day;
}

int get_day_of_week(const int day, const int month, const int year) {
    int leapInc = get_leap_years_quantity(year);
    // start: 1/1/1600 = Sa = +6
    int yearsInc = leapInc + 5 + year - 1600;
    int daysInc = get_days_from_year_started(day, month, year);

    return (yearsInc + daysInc) % 7;
}


void print_day_of_week(const int day_of_week, const bool skipFirst, const int firstNum,
                       const int maxNum, const int selectedNum, const bool selectedInOneDigitWeek) {
    printf("%s ", day_of_week_name[day_of_week - 1]);
    if (skipFirst) {
        printf("    "); // 4 spaces
    }

    for (int currentNum = firstNum; currentNum <= maxNum; currentNum = currentNum + 7){
        bool needSpecialSpace = currentNum != selectedNum && (currentNum - day_of_week + 1) < 10 && (currentNum - day_of_week + 7) >= 10 && (currentNum < 10);
        if (needSpecialSpace)
            printf(" ");

        if (currentNum == selectedNum)
            if (selectedNum >= 10)
                printf(" [%d]", currentNum);
            else
            {
                if (selectedInOneDigitWeek)
                    printf("[ %d]", currentNum);
                else
                    printf(" [ %d]", currentNum);

            }
        else
            printf("  %d ", currentNum);
    }

    printf("\n");
}

int main() {
    // start: 1/1/1600 = 6
    unsigned int day, month, year;
    scanf("%d %d %d", &day, &month, &year);

    int firstDayOfWeek = get_day_of_week(1, month, year);
    firstDayOfWeek = firstDayOfWeek == 0 ? 7 : firstDayOfWeek;

    int daysInMonth = days_in_month[month - 1] + ((month == 2 && is_leap_year(year)) ? 1 : 0);
    int firstMonday = firstDayOfWeek == 1 ? 1 : 9 - firstDayOfWeek;
    bool selectedInOneDigitWeek = (firstMonday > day) || (day < 10 && (firstMonday + 7 <= 10 && firstMonday + 7 > day));

    for (int i = 1; i < 8; i++) {
        int startNum = firstDayOfWeek <= i ? 1 + (i - firstDayOfWeek) : 8 - firstDayOfWeek + i;
        bool skipFirst = i < firstDayOfWeek;
        print_day_of_week(i, skipFirst, startNum, daysInMonth, day, selectedInOneDigitWeek);
    }

/*
mon........4...11...18...25
tue........5...12...19...26
wed........6...13...20...27
thu........7...14...21...28
fri...1....8...15...22...29
sat...2....9..[16]..23...30
sun...3...10...17...24...31
*/

    return 0;
}

