#include <iostream>
using namespace std;
class Date
{
public:
	Date(int day, int month, int year) : days_{ day }, month_{ month }, year_{ year }
	{
		if ((days_ > 31) || (month_ > 12))
		{
			cout << "Date error" << endl;
			return;
		}
	}

	bool isLeap() const
	{
		if ((year_ % 4 == 0 && year_ % 100 != 0) && year_ % 400) {
			return true;
		}
		return false;
	}

	void Show() const
	{
		cout << "Days: " << days_ << endl;
		cout << "Month: " << month_ << endl;
		cout << "Year: " << year_ << endl;
	}

	// Operator " + " for Int value
	Date& operator + (int Day)
	{
		if (days_ + Day > days[month_ - 1]) {
			for (;days_ + Day > days[month_ - 1];)
			{
				Day -= days[month_ - 1];
				Day = Day + days_;
				if (++month_ - 1 >= 12)
				{
					month_ = 1;
					year_++;
					isLeap() == true ? Day-- : Day;
				}
				days_ = Day;
				Day = 0;
			}
		}
		else
			days_ += Day;

		return *this;
	}

	// Operator "-" to take the value of the second instance of the Date type class
	// Taking into account leap year
	int operator - (const Date& SecondDate) const
	{
		// Assign value to the value of the object for which the method is called
		// To the value of the Temporary object
		Date temp = *this;

		// Remember the old value of the Year field
		int i = temp.year_;
		int j = 0;
		// Decrement the year in the Loop header
		// In the body of the Loop, check the result of the returned value by the isLeap() function
		// And decrement Days depending on Iterations and Return Value
		for (;temp.year_ != 0;temp.year_--)
		{
			temp.isLeap() == true ? j-- : j;
		};

		int TempDays = i * 365 + temp.days_ - j;

		for (int i = 0; i < month_ - 1; i++)
			TempDays += days[i];

		// Repeat above action

		Date tempSecond = SecondDate;

		int q = tempSecond.year_;
		int w = 0;

		for (;tempSecond.year_ != 0;tempSecond.year_--)
		{
			tempSecond.isLeap() == true ? w-- : w;
		};

		int TempSecondDays = q * 365 + tempSecond.days_ - w;

		for (int i = 0; i < tempSecond.month_ - 1; i++)
			TempSecondDays += days[i];

		return TempDays - TempSecondDays;
	}

	// The operator " - " takes the value of the second instance of the Date type class
	// Leap year not taken into account
	/*

	int operator - (Date& SecondDate) const
	{
		int FirstDays = year_ * 365 + days_;

		for (int i = 0; i < month_ - 1; i++)
			FirstDays += days[i];

		int SecondDays = SecondDate.year_ * 365 + SecondDate.days_;

		for (int i = 0; i < SecondDate.month_ - 1; i++)
			SecondDays += days[i];

		return FirstDays - SecondDays;
	}

	*/

	constexpr int GetDay() const
	{
		return days_;
	}

	constexpr int GetMonth() const
	{
		return month_;
	}

	constexpr int GetYear() const
	{
		return year_;
	}

	constexpr static int GetDaysInMonth(int index)
	{
		return days[index - 1];
	}

	~Date()
	{

	};

private:
	int days_;
	int month_;
	int year_;
	constexpr static int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
};

// Operator Overload "<<" To Output Number
ostream& operator<< (ostream& out, const Date& Date)
{
	const char* Month[] =
	{ "January","February","March","April","May","June","July","August","September","October","November","December" };

	out << "Date: " << Date.GetDay() << "." << Date.GetYear() << " " << Month[Date.GetMonth() - 1] << "\n";

	return out;
}

int main()
{
	Date a(15, 07, 2021);
	Date b(19, 01, 2016);
	cout << "Difference between: " << a - b << endl;
	cout << "A + 2668 = " << endl;
	a.Show();
	a + 2668;
	a.Show();
	cout << "A + 20 = " << endl;
	a + 20;
	a.Show();
	cout << a;
	cout << a.GetDaysInMonth(4);
}