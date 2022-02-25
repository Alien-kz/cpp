#include <iostream>

using namespace std;

class Test {
public:
    const int id = 2;

    Test(int n) : id(n) {
    }

    void print() {
        cout << id << endl;
    }
};


/*
class Square {
  int id;
public:
  const int id;
  Square(int n) {
    id = n; //  error: assignment of read-only member ‘::id’
  }
};

class Square {
  int id;
public:
  const int id = 2;
  Square(int n) {
    id = n; //  error: assignment of read-only member ::id’
  }
};

class Square {
  int id;
public:
  const int id;
  const double value;
  const Edge edge;
  Edge a;
  Square(int n) : id(n), value(12.3), edge(), a(1) {
  }
};
*/


/*
Ошибка компилятор (анализатор)
15.class-const-method.cpp: In constructor ‘Test::Test(int)’:
15.class-const-method.cpp:10:10: error: assignment of read-only member ‘Test::id’
     id = n;
          ^
Ошибка линковщика
/tmp/cctJYFRB.o: In function `Square::Square(double, Square::Color)':
15.class-const-method.cpp:(.text+0x1f): undefined reference to `Square::counter'
 */


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
	const int id;		//неизменяемый индивидуальный параметр
	const Color color;	//неизменяемый индивидуальный параметр

	static int counter; // нельзя инициализировать 
	// error: ISO C++ forbids in-class initialization of non-const static member ‘Square::counter’
	const static int step;	//неизменяемый общий параметр

public:
	Square(double a = 1.0, Square::Color newColor = Square::UNKNOWN);
	friend ostream & operator<<(ostream & out, const Square & s);

	void printColor(ostream & out = cout) const;
	bool operator>(const Square & s) const;

	static void printCounter();
};

int Square::counter = 0; // если это не написать будет ошибка линковки
const int Square::step = 1;

Square::Square(double newSize, Square::Color newColor) : \
   size(newSize), color(newColor), id(++counter) //блок инициализации констант (перечислять через запятую)
{
	if (size <= 0.0)
		size = 1.0;
}

void Square::printColor(ostream & out) const
{
	switch (color)
	{
		case RED: {out << "red"; break;}
		case Square::BLUE: {out << "blue"; break;}
		case Square::WHITE: {out << "white"; break;}
		default: {out << "unknown"; break;}
	}
//	size = 5; // error: assignment of member ‘Square::size’ in read-only object
}

bool Square::operator>(const Square & s) const //операторы + - * / % > < >= <= == [] () тоже const, если они не изменяют САМ объект
{
	return (size > s.size);
}

void Square::printCounter()
{
	cout << counter << endl;
}

ostream & operator<<(ostream & out, const Square & s)
{
	out << "Square #" << s.id;
	out << " (size = " << s.size << "; color = ";
	s.printColor();
	out << ")" << endl;
	return out;
}

int main()
{
        Test test(3);
        test.print();

        cout << sizeof(Square) << endl;
	Square s1, s2(5.0), s3(5.0, Square::WHITE);
	s3.printColor();
	cout << endl;

	cout << s1 << s2 << s3;

	Square::printCounter();
	return 0;
}
