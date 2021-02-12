#include <iostream>
#include <iomanip>

using namespace std;

struct Time
{
	int hour;
	int minute;
	int second;

	void scanTime()
	{
		cin >> hour >> minute >> second;
	}

	void printTime()
	{
		cout << setfill('0');
		cout << setw(2) << hour << ' ' << setw(2) << minute << ' ' << setw(2) << second << endl;
	}
	void inc()
	{
		second++;
		if (second == 60){
			second = 0;
			minute++;
		}
		if (minute == 60){
			minute = 0;
			hour++;
		}
		if (hour == 24)
			hour = 0;
	}
};


int main()
{
	Time current, next;
	current.scanTime();

	next = current;
	next.inc();

	cout << "Текущее время: ";
	current.printTime();

	cout << "Через 1 сек.: ";
	next.printTime();

	return 0;
}

