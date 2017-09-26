public class Date
{
    private int month;
    private int day;
    private int year;

    private static final String[] MONTH_NAMES = {
            "",
            "january",
            "february",
            "march",
            "april",
            "may",
            "june",
            "july",
            "august",
            "september",
            "october",
            "november",
            "december"
    };

    private static final int[] DAYS_IN_MONTHS = {
            0,
            31,
            28,
            31,
            30,
            31,
            30,
            31,
            31,
            30,
            31,
            30,
            31
    };

    private static final int[] DAYS_IN_MONTHS_LEAP = {
            0,
            31,
            29,
            31,
            30,
            31,
            30,
            31,
            31,
            30,
            31,
            30,
            31
    };

    // main constructor that validates parameters and throws an exception
    Date(int month, int day, int year) throws IllegalArgumentException
    {
        if (isValidDate(month, day, year))
        {
            this.month = month;
            this.day = day;
            this.year = year;
        }
        else
        {
            throw new IllegalArgumentException();
        }
    }

    // gets month number and calls main constructor
    Date(String monthName, int day, int year)
    {
        this(getMonthNumber(monthName.toLowerCase()), day, year);
    }

    // calls helper constructor with MonthAndDay object
    Date(int daysIntoYear, int year)
    {
        this(getMonthAndDay(daysIntoYear, year), year);
    }

    // calls main constructor with month and day numbers
    private Date(MonthAndDay monthAndDay, int year)
    {
        this(monthAndDay.month, monthAndDay.day, year);
    }

    public int getMonth()
    {
        return this.month;
    }

    public int getDay()
    {
        return this.day;
    }

    public int getYear()
    {
        return this.year;
    }

    public void setMonth(int month)
    {
        if (isValidDate(month, this.day, this.year))
        {
            this.month = month;
        }
    }

    public void setDay(int day)
    {
        if (isValidDate(this.month, day, this.year))
        {
            this.day = day;
        }
    }

    public void setYear(int year)
    {
        if (isValidDate(this.month, this.day, year))
        {
            this.year = year;
        }
    }

    // checks if the combination of month, day, and year is valid
    private static boolean isValidDate(int month, int day, int year)
    {
        if (month < 1 || month > 12)
        {
            return false;
        }
        if (year < 0 || year > 9999)
        {
            return false;
        }
        if (day == 29 && month == 2 && isLeapYear(year))
        {
            return true;
        }
        return day > 0 && day <= DAYS_IN_MONTHS[month];
    }

    private static boolean isLeapYear(int year)
    {
        if (year % 4 == 0)
        {
            if (year % 100 == 0)
            {
                return year % 400 == 0;
            }
            return true;
        }
        return false;
    }

    // given a month name, returns its number or 0
    private static int getMonthNumber(String monthName)
    {
        for (int i = 1; i < 13; i++)
        {
            if (monthName.equals(MONTH_NAMES[i]))
            {
                return i;
            }
        }
        return 0;
    }

    // given a month number, returns its name
    private static String getMonthName(int month)
    {
        String monthName = MONTH_NAMES[month];
        return monthName.substring(0, 1).toUpperCase() + monthName.substring(1);
    }

    // given the number of days into the year, returns the month and day
    private static MonthAndDay getMonthAndDay(int daysIntoYear, int year)
    {
        int month;
        int[] daysInMonths = isLeapYear(year) ? DAYS_IN_MONTHS_LEAP : DAYS_IN_MONTHS;
        for (month = 1; month < 13; month++)
        {
            if (daysIntoYear <= daysInMonths[month])
            {
                break;
            }
            daysIntoYear -= daysInMonths[month];
        }
        return new MonthAndDay(month, daysIntoYear);
    }

    // helper class for returning month and day values
    private static class MonthAndDay
    {
        int month;
        int day;

        MonthAndDay(int month, int day)
        {
            this.month = month;
            this.day = day;
        }
    }

    // given the month, day, and year, returns the days into the year
    private static int getDaysIntoYear(int month, int day, int year)
    {
        int daysIntoYear = 0;
        int[] daysInMonths = isLeapYear(year) ? DAYS_IN_MONTHS_LEAP : DAYS_IN_MONTHS;
        for (int i = 1; i < month; i++)
        {
            daysIntoYear += daysInMonths[i];
        }
        return daysIntoYear + day;
    }

    @Override
    public String toString()
    {
        return String.format("Date: %02d/%02d/%04d", this.month, this.day, this.year);
    }

    public void displayDate()
    {
        System.out.printf("%02d/%02d/%04d%s", this.month, this.day, this.year, System.lineSeparator());
    }

    // displays the object in one of three formats, based on input
    public void displayDate(int format)
    {
        switch (format)
        {
            case 0: displayDate();
                    break;
            case 1: String monthName = getMonthName(this.month);
                    System.out.printf("%s %d, %d%s", monthName, this.day, this.year, System.lineSeparator());
                    break;
            case 2: int daysIntoYear = getDaysIntoYear(this.month, this.day, this.year);
                    System.out.printf("%03d %04d%s", daysIntoYear, this.year, System.lineSeparator());
        }
    }
}
