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
	void multiInc(int t)
	{
		while(t--)
			inc();
	}
	Time addSecond(int t)
	{
		Time tmp;
		tmp.hour = hour;
		tmp.minute = minute;
		tmp.second = second;
		tmp.multiInc(t);
		return tmp;
	}
	bool isNight()
	{
		return (0 <= hour && hour <= 6);
	}
	int convertToSeconds()
	{
		return 3600*hour + 60*minute+second;
	}
	int diff(const Time &tmp)
	{
		return convertToSeconds() - tmp.convertToSeconds();
	}
	bool biggerThan(const Time &tmp)
	{
		if (hour > tmp.hour)
			return true;
		if (minute > tmp.minute)
			return true;
		if (second > tmp.second)
			return true;
		return false;
	}
};


int main()
{
	Time current;

	cout << "Текущее время: ";
	current.scanTime();

	cout << "Через 1 сек.: ";
	current.inc();
	current.printTime();

	cout << "Еще через 10 сек.:";
	current.multiInc(10);
	current.printTime();

	if (current.isNight())//новые слова с большой буквы
		cout << "Ночь" << endl;
	else
		cout << "День" << endl;

	Time next;
	cout << "Новая отсечка времени: ";
	next.scanTime();

	if (next.biggerThan(current))
		cout << "Новая отсечка идет спустя  " << next.diff(current) << " сек." <<  endl;
	else if (current.biggerThan(next))
		cout << "Новая отсечка идет за " << current.diff(next) << " сек." <<  endl;
	else
		cout << "Время совпадает" << endl;

	cout << "Еще отсечка" << endl;
	(next.addSecond(61)).printTime();
	
  next.addSecond(61).printTime();
	return 0;
}

