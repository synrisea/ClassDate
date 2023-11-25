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

public:
    Date(int y, int m, int d) {};

    int GetYear() const {};
    int GetMonth() const {};
    int GetDay() const {};

    Date(int d) : Date(0, 0, d) {};


    void AddDays(int d)
    {
        days += d;
    }


    // Overload operators '+' and '+=' : 

    Date& operator += (int d)
    {
        days += d;

        return *this;
    }

    Date operator+ (int d) const
    {
        return Date(years, months, days + d);
    }


    // Counting the total number of days.

    int TotalDays() const
    {
        int totalDays = days;

        for (int i = 1; i < months; ++i)
        {
            int daysInMonth, daysInPrevMonth;
            countDaysInMonth(daysInMonth, daysInPrevMonth, i);

            totalDays += daysInPrevMonth;
        }

        return totalDays;
    }
};


int Date::GetYear() const
{
    return years;
}

int Date::GetMonth() const
{
    return months;
}

int Date::GetDay() const
{
    return days;
}


Date::Date(int y, int m, int d)
{
    years = y;
    months = m;
    days = d;

    Normalize();
}


int operator- (const Date& d1, const Date& d2)
{
    return d1.TotalDays() - d2.TotalDays();
}


// Overloading input and output operators.

std::ostream& operator << (std::ostream& out, const Date& d)
{
    out << " Date : " << d.GetDay() << "/" << d.GetMonth() << "/" << d.GetYear() << "\n\n";
    return out;
}

std::istream& operator >> (std::istream& in, Date& date)
{
    int y, m, d;
    std::cout << " Year : ";
    in >> y;
    std::cout << " Month : ";
    in >> m;
    std::cout << " Day : ";
    in >> d;

    date = Date(y, m, d);

    return in;
}


int main()
{
    std::cout << "\n\n ----TEST 1----\n";
    Date date(2021, 39, -28);
    std::cout << date;

    std::cout << "\n\n ----TEST 2----\n";
    std::cin >> date;
    std::cout << date;

    std::cout << "\n\n ----TEST 3----\n";
    std::cout << date + 53;

    std::cout << "\n\n ----TEST 4----\n";
    date += 4;
    std::cout << date;

    std::cout << "\n\n ----TEST 5----\n";
    Date date1(3533);
    Date date2(5456);

    std::cout << date2 - date1;

    return 0;
}
