#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <iomanip>

using std::noskipws;	//white space пробелы табуляция перенос строки

int main()
{
	//ввод-вывод символа
	char ch;
	cout << "Введите символ: " << endl;
	cin >> ch;
	cout << "символ " << ch << ", код " << (int)ch << endl;	//cout самостоятельно корректно определяет тип, который ему передают
	cout << endl;

	int num;
	cout << "Введите ASCII-код:" << endl;
	cin >> num;
	cout << "символ " << (char)num << ", код " << num << endl;	//cout самостоятельно корректно определяет тип, который ему передают
	cout << endl;

	//разделители ввод-вывод строки с разделителями
	cout << "Ввод-вывод с разделителями (5 символов): " << endl;
	for (int i = 0; i < 5; i++)
	{
		cin >> ch;
		cout << ch;
	}
	cout << endl;
	cout << endl;

	//буфер [a][ ][b][ ][c][d][ ][ ][e][enter]

	//посимвольный ввод-вывод строки без разделителей
	cout << "Ввод-вывод без разделителей (5 символов): " << endl;
	for (int i = 0; i < 5; i++)
	{
		cin >> noskipws >> ch;	//или cin.get(ch);
		cout << ch;		//или cout.put(ch);
		cout << "[" << (int) ch << "]" << endl;
	}
	cout << endl;
	cout << endl;

	//ввод-вывод строки
	cout << "Ввод строки по умолчанию (небезопасный, до пробела): " << endl;
	char buffer[100];
	cin >> buffer;
	cout << buffer << endl;

	//ввод-вывод строки
	cout << "Ввод строки по умолчанию (безопасный, до разделителя не более размера буфера): " << endl;
	cin.get(buffer, 10, '\n');
	cout << buffer << endl;

	//ввод-вывод строки
	cout << "Ввод текста до конца файла (эмуляция через Ctrl+D): " << endl;
	while (cin >> ch)
		cout << ch;

	return 0;
}
