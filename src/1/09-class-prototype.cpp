#include <iostream>

using std::cout;
using std::cin;
using std::endl;

//прототипы

class Rectangle
{
	int s;
	int a, b;
	void normalize();

public:
	void setSize(int aNew, int bNew);	//имена параметров можно опускать
						//void setSize(int, int)
	int getSquare();
	bool isBiggerThan(const Rectangle &);
	void print();
};

void Rectangle::normalize()
{
	if (a <= 0)
		a = 1;
	if (b <= 0)
		b = 1;
}
void Rectangle::setSize(int aNew, int bNew)
{
	a = aNew;			//закрытые поля могут использоваться в методах
	b = bNew;
	normalize();			//закрытые методы могут использоваться в других  методах
	s = a * b;
}
int Rectangle::getSquare()
{
	return s;
}
bool Rectangle::isBiggerThan(const Rectangle & rect)
{
	return (rect.s > s);
}
void Rectangle::print()
{
	cout << "Rectangle: (" << a << "; " << b << ")" << endl;
}


int main()
{
	Rectangle A, B;

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
