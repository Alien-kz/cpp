#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <iomanip>	//манипуляторы

using std::setprecision;	//точность для вещественных чисел
using std::setw;		//ширины вывода
using std::setfill;		//пустой символ (по умолчанию - пробел)
using std::fixed;

int main()
{
	//точность
	double a = 11.23;
	for (int p = 0; p < 5; p++)	//обратите внимание, что область видимости переменной p - только внутри цикла
		cout << "C точностью " << p << " знаков после запятой: " << fixed << setprecision(p) << a << endl;
	cout << endl;

	//ширина вывода
	for (int w = 0; w < 5; w++)
	{
		cout << "Ширина вывода не менее " << w << " знаков на число: ";
		for (int p = 0; p < 5; p++)
			cout << setw(w) << setprecision(p) << a << " ";
		cout << endl;
	}
	cout << endl;

	//задание пустого символа
	cout << "Пустой символ '_': " << endl;
	for (int p = 0; p < 5; p++)
		cout << setfill('_') << setw(5) << setprecision(p) << a << endl;
	cout << endl;
	return 0;
}
