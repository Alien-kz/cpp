#include <iostream>

using namespace std;

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
	double size;
	const int id;
	const Color color;

	static const int step = 1;
	static int counter;

public:
	Square(double a = 1.0, Square::Color newColor = Square::UNKNOWN);
	friend ostream & operator<<(ostream & out, const Square & s);

	void printColor(ostream & out = cout) const;
	bool operator>(const Square & s) const;

	static void printCounter();
};

int Square::counter = 0;

Square::Square(double newSize, Square::Color newColor) : size(newSize), color(newColor), id(++counter)
{
	if (size <= 0.0)
		size = 1.0;
}

void Square::printColor(ostream & out) const
{
	switch (color)
	{
		case Square::RED: {out << "red"; break;}
		case Square::BLUE: {out << "blue"; break;}
		case Square::WHITE: {out << "white"; break;}
		default: {out << "unknown"; break;}
	}
}

bool Square::operator>(const Square & s) const
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
	Square *ptr = new Square(5.0, Square::WHITE);
	ptr->printColor();
	cout << endl;
	cout << (*ptr); // operator<<(cout, *ptr)
	delete ptr;

	Square *array = new Square[10];
	for (int i = 0; i < 10; i++)
	{
		array[i].printColor();
		cout << endl;
		cout << array[i];
	}
	delete []array; // если делать так delete array; то получите
  // AddressSanitizer: alloc-dealloc-mismatch (operator new [] vs operator delete)
  // чтобы отлавливать -fsanitize=address

	return 0;
}
