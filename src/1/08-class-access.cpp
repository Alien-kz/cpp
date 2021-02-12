#include <iostream>

using std::cout;
using std::cin;
using std::endl;

//public и private доступ
//закрытые поля = реализация ИНКАПСУЛЯЦИИ 
//(клиентский код = main() может делать только то, что позволено интерфейсом в виде открытых методов)
//суть ООП = разделение интерфейса и реализизации

class Rectangle
{
	int s;		//закрытое поле (по умолчанию)

private:		//далее идут закрытые поля и методы

	int a, b;	//закрытые поля
	void normalize()	//закрытый метод
	{
		if (a <= 0)
			a = 1;
		if (b <= 0)
			b = 1;
	}

public:			//далее идут открытые поля и методы

	void setSize(int aNew, int bNew)	//сеттер - метод для задания значения закрытого поля
 	{
		a = aNew;			//закрытые поля могут использоваться в методах
		b = bNew;
		normalize();			//закрытые методы могут использоваться в других  методах
		s = a * b;
	}
	int getSquare()//геттер - метод для получения значения закрытого поля
	{
		return s;
	}
	bool isBiggerThan(const Rectangle & rect)
	{
		return (rect.s > s); 		//можно обратиться к закрытому полю
						//ДРУГОГО объекта ТАКОГО ЖЕ класса
	}
	void print()
	{
		cout << "Rectangle: (" << a << "; " << b << ")" << endl;
	}
};


int main()
{
	Rectangle A, B;
//	A.a = 2; //error: ‘int Rectangle::a’ is private
//	A.b = 5; //error: ‘int Rectangle::a’ is private
// 	cout << A.normalize()	//error: ‘void Rectangle::normalize()’ is private

	A.setSize(2, 5);
	B.setSize(3, 4);

	A.print();
	cout << A.getSquare() << endl;

	B.print();
	cout << B.getSquare() << endl;

	if (A.isBiggerThan(B))
		cout << "A is bigger than B" << endl;
	else if (B.isBiggerThan(A))
		cout << "B is bigger than A" << endl;
	else
		cout << "A equal to B" << endl;
	return 0;
}
