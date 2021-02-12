#include <iostream>

using std::cout;
using std::cin;
using std::endl;

//конструкторы и деструкторы
//различные конструктуры - это один из видов ПОЛИМОРФИЗМА
//(один интерфейс = разные реализации)


class Rectangle
{
	int a, b;
	void normalize();

public:
	Rectangle();			//конструктор по умолчанию
	Rectangle(int, int);		//конструктор c параметрами
	Rectangle(const Rectangle &);	//конструктор копирования
	~Rectangle();			//деструктор

	void setSize(int aNew, int bNew);
	void print();
};

Rectangle::Rectangle()				//конструктор по умолчанию
{
	a = 1;	//надо очень внимательно относится к инициализации данных
	b = 1;
}

Rectangle::Rectangle(int aNew, int bNew)	//конструктор с параметрами
{
	setSize(aNew, bNew);			//в конструкторе можно вызывать методы
}

Rectangle::Rectangle(const Rectangle & r)	//деструктор
{
	setSize(r.a, r.b);			//в конструкторе можно вызывать методы
}

Rectangle::~Rectangle()				//конструктор по умолчанию
{
	cout << "Bye Bye! ";
	print();
}


void Rectangle::normalize()
{
	if (a <= 0)
		a = 1;
	if (b <= 0)
		b = 1;
}
void Rectangle::setSize(int aNew, int bNew)
{
	a = aNew;
	b = bNew;
	normalize();
}

void Rectangle::print()
{
	cout << "Rectangle: (" << a << "; " << b << ")" << endl;
}

int main()
{
	cout << "1 step:" << endl;
	Rectangle A, B(3, 4);
	A.print();
	B.print();
	cout << "1 step" << endl << endl;

	cout << "2 step:" << endl;
	A = B;
	B.setSize(11, 12);
	A.print();
	B.print();
	cout << "2 step" << endl << endl;

	cout << "3 step:" << endl;
	{
		Rectangle C = A;
	}
	cout << "3 step" << endl << endl;

	return 0;
}
