#include <iostream>
#include <limits>

class Date {
private:
    int day, month, year;
    static Date defaultDate;

public:
    Date(int aDay = 0, int aMonth = 0, int aYear = 0);
    ~Date(); // Destructor

    void setDefaultDate(int aDay, int aMonth, int aYear);
    void setDay(int aDay);
    int getDay() const;
    void addDay(int x);
    void setMonth(int aMonth);
    int getMonth() const;
    void addMonth(int x);
    void setYear(int aYear);
    int getYear() const;
    void addYear(int x);
    bool leapYear(int x) const;
    void setDate(int aDay, int aMonth, int aYear);
};

// Initialize static member
Date Date::defaultDate(7, 3, 2005);

Date::Date(int aDay, int aMonth, int aYear)
    : day(aDay == 0 ? defaultDate.day : aDay),
      month(aMonth == 0 ? defaultDate.month : aMonth),
      year(aYear == 0 ? defaultDate.year : aYear) {}

Date::~Date() {
    std::cout << "Date destructor" << std::endl;
}

void Date::setMonth(int a) {
    if (a > 0 && a <= 12) {
        month = a;
    }
}

int Date::getMonth() const {
    return month;
}

void Date::addYear(int x) {
    year += x;
    if (day == 29 && month == 2 && !leapYear(year)) {
        day = 1;
        month = 3;
    }
}

bool Date::leapYear(int x) const {
    return (x % 4 == 0 && x % 100 != 0) || (x % 400 == 0);
}

void Date::setYear(int aYear) {
    year = aYear;
}

void Date::setDay(int aDay) {
    day = aDay;
}

int Date::getDay() const {
    return day;
}

void Date::setDate(int aDay, int aMonth, int aYear) {
    setDay(aDay);
    setMonth(aMonth);
    setYear(aYear);
    std::cout << day << "/" << month << "/" << year << std::endl;
}

void Date::addDay(int x) {
    while (x > 0) {
        int daysInCurrentMonth;
        switch (month) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                daysInCurrentMonth = 31; break;
            case 4: case 6: case 9: case 11:
                daysInCurrentMonth = 30; break;
            case 2:
                daysInCurrentMonth = leapYear(year) ? 29 : 28; break;
            default:
                daysInCurrentMonth = 30; // Default case for safety, not expected to reach
        }

        if (day + x <= daysInCurrentMonth) {
            day += x;
            x = 0; // No more days left to add
        } else {
            x -= (daysInCurrentMonth - day + 1);
            day = 1; // Reset to the first day of the next month
            addMonth(1); // Move to the next month
        }
    }
}


void Date::addMonth(int x) {
    month += x;
    while (month > 12) {
        month -= 12;
        addYear(1);
    }
}


int Date::getYear() const {
    return year;
}

int main() {
    int day, month, year;

    // Prompt user for initial date
    std::cout << "Enter day: ";
    std::cin >> day;
    while (std::cin.fail() || day <= 0 || day > 31) {
        std::cout << "Invalid input. Please enter a valid day (1-31): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> day;
    }

    std::cout << "Enter month: ";
    std::cin >> month;
    while (std::cin.fail() || month <= 0 || month > 12) {
        std::cout << "Invalid input. Please enter a valid month (1-12): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> month;
    }

    std::cout << "Enter year: ";
    std::cin >> year;
    while (std::cin.fail() || year <= 0) {
        std::cout << "Invalid input. Please enter a valid year (>0): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> year;
    }

    // Set the date
    Date userDate(day, month, year);
    userDate.setDate(day, month, year);

    // Prompt if the user wants to add days
    char addMore;
    std::cout << "Do you want to add days to this date? (y/n): ";
    std::cin >> addMore;

    if (addMore == 'y' || addMore == 'Y') {
        int daysToAdd;
        std::cout << "Enter number of days to add: ";
        std::cin >> daysToAdd;
        while (std::cin.fail() || daysToAdd < 0) {
            std::cout << "Invalid input. Please enter a non-negative number of days: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> daysToAdd;
        }

        userDate.addDay(daysToAdd);
        std::cout << "Updated date: ";
        userDate.setDate(userDate.getDay(), userDate.getMonth(), userDate.getYear());
    }

    return 0;
}
