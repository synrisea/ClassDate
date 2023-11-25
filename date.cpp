#include <iostream>


enum MonthOrder
{
    JANUARY = 1,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
};


class Date
{
private:
    int years = 0;
    int months = 0;
    int days = 0;


    // Count the number of days in the current and previous months.

    int countDaysInMonth(int& daysInMonth, int& daysInPrevMonth, int currentMonth) const
    {
        currentMonth = (currentMonth - 1) % 12 + 1;

        switch (currentMonth)
        {
        case JANUARY:
        {
            daysInMonth = 31;
            daysInPrevMonth = 31;
            break;
        }
        case FEBRUARY:
        {
            if (!isLeapYear())
            {
                daysInMonth = 28;
            }
            else
            {
                daysInMonth = 29;
            }

            daysInPrevMonth = 31;
            break;
        }
        case MARCH:
        {
            daysInMonth = 31;

            if (!isLeapYear())
            {
                daysInPrevMonth = 28;
            }
            else
            {
                daysInPrevMonth = 29;
            }
            break;
        }
        case APRIL:
        {
            daysInMonth = 30;
            daysInPrevMonth = 31;
            break;
        }
        case MAY:
        {
            daysInMonth = 31;
            daysInPrevMonth = 30;
            break;
        }
        case JUNE:
        {
            daysInMonth = 30;
            daysInPrevMonth = 31;
            break;
        }
        case JULY:
        {
            daysInMonth = 31;
            daysInPrevMonth = 30;
            break;
        }
        case AUGUST:
        {
            daysInMonth = 31;
            daysInPrevMonth = 31;
            break;
        }
        case SEPTEMBER:
        {
            daysInMonth = 30;
            daysInPrevMonth = 31;
            break;
        }
        case OCTOBER:
        {
            daysInMonth = 31;
            daysInPrevMonth = 30;
            break;
        }
        case NOVEMBER:
        {
            daysInMonth = 30;
            daysInPrevMonth = 31;
            break;
        }
        case DECEMBER:
        {
            daysInMonth = 31;
            daysInPrevMonth = 30;
            break;
        }
        }

        return daysInMonth;
    }


    bool isLeapYear() const
    {
        return (years % 4 == 0 && years % 100 != 0) || (years % 400 == 0);
    }


    void Normalize()
    {
        int daysInMonth, daysInPrevMonth;

        countDaysInMonth(daysInMonth, daysInPrevMonth, months);

        // For days : 

        months += days / (daysInMonth + 1);
        days %= daysInMonth + 1;

        if (days == 0)
        {
            days++;
        }

        if (days < 0)
        {
            months -= 1;
            days += daysInPrevMonth + 1;
        }

        // For months :

        years += months / 12;
        months %= 12;

        if (months == 0)
        {
            months++;
        }

        if (months < 0)
        {
            years -= 1;
            months += 12;
        }
    }
};


int main()
{

}
