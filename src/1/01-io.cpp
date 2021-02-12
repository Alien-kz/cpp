#include <iostream>	//заголовочные файлы без .h, чтобы найти расположение набираем команду 
			//locate iostream

using std::cout;	//cout, cin, endl - объекты, которыe спрятаны в пространстве имен std
using std::cin;		//если не уточнять пространство, то будет ошибка error: ‘cin’ was not declared in this scope 
using std::endl;	//можно подключить всё пространство имён командной using namespace std; если нет сторонних библиотек

int main()
{
	//ввод-вывод
	int a, b;
	cout << "Ввод:\n"; // операция << примененная к объекту cout и константной строке "Ввод"
	cin >> a;		   // операция >> примененная к объекту cin и переменной a

	//однократное добавление в поток вывода константы, переменной, объекта
	cout << "Вывод (следующее число):\n";
	cout << (a + 1);		//скобки следуют расставлять для себя, так как приоритет << выше некоторых оперторов
	cout << endl;

	//многократное добавление в поток
	cout << "Сумма 2 чисел:\n";
	cin >> a >> b;			//следует читать как (cin >> a) >> b;
	cout << (a + b) << endl;	// cin и a - операнды (поток и переменная), >> - оператор, результат - опять поток

	//примеры с приоритетом
	cout << "Приоритет (2 в степени a битовым сдвигом):\n";
	cin >> a; //3

	cout << 1 << a; //13
	cout << endl;

	(cout << 1) << a; //13
	cout << endl;

	cout << (1 << a); //8
	cout << endl;

	return 0;
}
