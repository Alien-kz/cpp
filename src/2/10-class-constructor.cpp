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
	Rectangle(const Rectangle&);	//конструктор копирования
	~Rectangle();			//деструктор

	void setSize(int aNew, int bNew);
	void print();
};

Rectangle::Rectangle()				//конструктор по умолчанию
{
	a = 1;	//надо очень внимательно относится к инициализации данных
	b = 1;
}

Rectangle::Rectangle(int a, int b)	//конструктор с параметрами
{
	setSize(a, b);			//в конструкторе можно вызывать методы
}

Rectangle::Rectangle(const Rectangle & r)	//констcout <руктор копирования
{
	setSize(r.a, r.b);			//в конструкторе можно вызывать методы
}

Rectangle::~Rectangle()				//деструктор по умолчанию
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
void Rectangle::setSize(int a, int b)
{
  Rectangle::a = a;
  Rectangle::b = b;
//	this->a = a;
//	this->b = b;
  normalize();
}

void Rectangle::print()
{
	cout << "Rectangle: (" << a << "; " << b << ")" << endl;
}

int main()
{
	cout << "1 step:" << endl;
	Rectangle A, B(3, 4); //К по умолчанию, К с параметрами
	A.print();
	B.print();
	cout << "1 step" << endl << endl;

	cout << "2 step:" << endl;
	A = B; // К копирования
	Rectangle C(B); // К копирования
	B.setSize(11, 12);
	A.print();
	B.print();
	cout << "2 step" << endl << endl;

	cout << "3 step:" << endl;
	{
		Rectangle D; //К по умолчанию
	}
	cout << "3 step" << endl << endl;

	return 0;
}

//A()    +8byte
//B()    +8byte
//copy() +0byte т.к. const &
//C()    +8byte
//copy() +0byte т.к. const &
//D()    +8byte
//~D()   -8byte
//~C()   -8byte
//~B()   -8byte
//~A()   -8byte

// static = STACK = CREATE { = FREE } 
// dynamic = HEAP = CREATE NEW() = FREE DELETE()

