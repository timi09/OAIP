#include <iostream>
#include <string>

using namespace std;

struct Date
{
	unsigned short Day;
	unsigned short Month;
	unsigned short Year;

	Date(unsigned short day, unsigned short month, unsigned short year)
	{
		Day = day;
		Month = month;
		Year = year;
	}
};

Date nextDate(Date d);

int main()
{
	while (true)
	{
		int d, m, y;
		cout << "Input date: ";
		cin >> d >> m >> y;

		Date date = Date(d, m, y);

		date = nextDate(date);

		cout << "Next date: ";
		cout << to_string(date.Day) + " " + to_string(date.Month) + " " + to_string(date.Year) << endl;
	}

	system("pause");
	return 0;
}

bool leapYear(Date d)
{
	bool IsLeapYear = false;
	if (d.Year % 4 != 0 || d.Year % 100 == 0 && d.Year % 400 != 0)
	{
		IsLeapYear = false;
	}
	else
	{
		IsLeapYear = true;
	}

	return IsLeapYear;
}

int daysInMonth(Date d)
{
	int DaysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (leapYear(d))
	{
		DaysInMonth[1]++;
	}

	return DaysInMonth[d.Month - 1];
}

int checkDate(Date d)
{
	if (!(d.Month >= 1 && d.Month <= 12))
	{
		return 1;
	}

	int DaysInMonth = daysInMonth(d);
	if (!(d.Day >= 1 && d.Day <= DaysInMonth))
	{
		return 2;
	}

	return 0;
}

Date nextDate(Date d)
{
	int code = checkDate(d);
	if (code == 0)
	{
		d.Day++;

		int DaysInMonth = daysInMonth(d);
		if (d.Day > DaysInMonth)
		{
			d.Day = d.Day % DaysInMonth;
			d.Month++;
		}

		if (d.Month > 12)
		{
			d.Month = d.Month % 12;
			d.Year++;
		}
	}

	return d;
}