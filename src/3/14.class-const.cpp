#include <iostream>

using namespace std;

unsigned char t;

class Square
{
public:
	enum Color
	{
		RED,
		BLUE,
		WHITE,
		UNKNOWN
	};
private:
	double size;		//изменяемый параметр
	const Color color;	//неизменяемый индивидуальный параметр
	const int id;		//неизменяемый индивидуальный параметр

	static const int step = 1;	//неизменяемый общий параметр
	static int counter;

//	const int id = 1;//warning: non-static data member initializers only available with -std=c++11
public:
	Square(double a = 1.0, Square::Color newColor = Square::UNKNOWN);
	friend ostream & operator<<(ostream & out, const Square & s);
};

int Square::counter = 1;

Square::Square(double newSize, Square::Color newColor) : size(newSize), color(newColor), id(counter)
//блок инициализации констант (перечислять через запятую)
//порядок перечисления должен соответствовать порядку объявления в классе (иначе warning: will be initialized after [-Wreorder])
{
	counter++;
	if (size <= 0.0)
		size = 1.0;
}

ostream & operator<<(ostream & out, const Square & s)
{
	out << "Square #" << s.id;
	out << " (size = " << s.size << "; color = ";
	switch (s.color)
	{
		case Square::RED: {cout << "red"; break;}
		case Square::BLUE: {cout << "blue"; break;}
		case Square::WHITE: {cout << "white"; break;}
		default: {cout << "unknown"; break;}
	}
	out << ")" << endl;
	return out;
}

int main()
{
	Square s1, s2(5.0), s3(5.0, Square::WHITE);
	cout << s1 << s2 << s3;
	return 0;
}
