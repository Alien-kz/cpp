#include <iostream>
#include <iomanip>

using namespace std;

struct Time
{
	int hour;
	int minute;
	int second;
};

////////////////////////Ввод///////////////////////////
//Вариант 1. Возврат по значению.
//Память: sizeof(Time) байт (в нашем случае 12 байт)
//Время: операция копирования структуры current = tmp
/*
Time scanTime()
{
	Time tmp;
	cin >> tmp.hour >> tmp.second >> tmp.minute;
	return tmp;
}

int main()
{
	Time current;
	current = scanTime();
	...
}
*/

////////////////////////Ввод///////////////////////////
//Вариант 2. Изменение по указателю.
//Память: sizeof(Time*) байт (в нашем случае 8 байта)
//Время: 0
/*
void scanTime(Time *ptr)
{
	cin >> (tmp->hour) >> (tmp->second) >> (tmp->minute);
}

int main()
{
	Time current;
	scanTime(&current);
	...
}
*/

////////////////////////Ввод///////////////////////////
//Вариант 3. Изменение по ссылке
//Память: 0
//Время: 0
void scanTime(Time & tmp) //возврат параметра по ссылке, 
			 //обратите внимание, что передача по значнию void scanTime(Time tmp)
			 //здесь не сработает, так как будет создаваться и изменять копия переменной current
{
	cin >> tmp.hour >> tmp.minute >> tmp.second;
}

////////////////////////Вывод///////////////////////////
void printTime(const Time & tmp) //передача параметра по константной ссылке
				//можно было бы передавать и по значению void print(Time tmp)
				//но тогда бы создавался временный объект - дополнительная память
{
	cout << setfill('0');
	cout << setw(2) << tmp.hour << ' ' << setw(2) << tmp.minute << ' ' << setw(2) << tmp.second << endl;
}

////////////////////////Увеличение на 1///////////////////////////
void inc(Time & tmp)
{
	tmp.second++;
	if (tmp.second == 60){
		tmp.second = 0;
		tmp.minute++;
	}
	if (tmp.minute == 60){
		tmp.minute = 0;
		tmp.hour++;
	}
	if (tmp.hour == 24)
		tmp.hour = 0;
}


int main()
{
	Time current, next;
	scanTime(current);

	next = current;
	inc(next);

	cout << "Текущее время: ";
	printTime(current);
	cout << "Следующее время: ";
	printTime(next);
	return 0;
}

