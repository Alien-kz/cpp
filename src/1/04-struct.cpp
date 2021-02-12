#include <iostream>
#include <iomanip>

using namespace std;

struct Time{
	int hour;
	int minute;
	int second;
};
//Обратите внимание на ;


int main(){
	Time current, next;		//вообще можно писать и объявление типа прямо здесь 
					// struct Time{int hour, minute, second} current, next;
	cin >> current.hour >> current.minute >> current.second;

	next = current;
	next.second++;
	if (next.second == 60){
		next.second = 0;
		next.minute++;
	}
	if (next.minute == 60){
		next.minute = 0;
		next.hour++;
	}
	if (next.hour == 24)
		next.hour = 0;

	cout << setfill('0');
	cout << "Текущее время: ";
	cout << setw(2) << current.hour << ' ' << setw(2) << current.minute << ' ' << setw(2) << current.second << endl;

	cout << "Следующее время: ";
	cout << setw(2) << next.hour << ' ' << setw(2) << next.minute << ' ' << setw(2) << next.second << endl;
	return 0;
}

