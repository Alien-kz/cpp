#include <iostream>

using std::endl;
using std::cout;
class Vector2
{
	double x, y;
public:	
	static int constructors;
	Vector2();
        Vector2(const Vector2& v);
	Vector2(double x, double y);
	double operator*(const Vector2 &v);
	Vector2 operator+(const Vector2 &v);
	Vector2 operator-(const Vector2 &v);
	double operator&(const Vector2 &v);
	
	void print();
};

int Vector2::constructors = 0;

Vector2::Vector2() {
	x = 1;
	y = 1;
	constructors++;
	cout << "конструктор по умолчанию\n";
}

Vector2::Vector2(const Vector2& v) {
	x = v.x;
	y = v.y;
	constructors++;
	cout << "конструктор копирования\n";
}

Vector2::Vector2(double x, double y=1.0)	//значения по умолчанию
{
	Vector2::x = x;
	Vector2::y = y;
	constructors++;
	cout << "конструктор с параметрами\n";
}

void Vector2::print()
{
	cout << "(" << x << "; " << y << ")" << endl;
	cout << constructors << endl;
}
// a * b
// a.operator*(b)
double Vector2::operator*(const Vector2 &v)			//перегрузка оператора умножения
{
	return x * v.x + y * v.y;
}

Vector2 Vector2::operator+(const Vector2 &v)
{
	return Vector2(x + v.x, y + v.y);
}

/*
Vector2 Vector2::operator+(const Vector2 &v)
{
	Vector2 res;
	res.x = x + v.x;
	res.y = y + v.y;
	return res;
}
*/ 

// Vector a, b, c;
// c = a.operator-(b)

Vector2 Vector2::operator-(const Vector2 &v)
{
  return Vector2(x - v.x, y - v.y);
}

double Vector2::operator&(const Vector2 &v)
{
	return x * v.y - v.x * y;
}

int main()
{
	Vector2 a, b, c;
	cout << Vector2::constructors << endl;
	c = a - b;
        //c.operator=(a.operator-(b))
	cout << Vector2::constructors << endl;
  
	Vector2 v1; 			//(1.0, 1.0)
	Vector2 v2(2.0, 2.0);           //(2.0, 2.0)
	Vector2 v3(2.0);		//(2.0, 1.0)
	Vector2 v4(v3);                 //(2.0, 1.0)
	v3.print();

	cout << "dot = " << v1 * v3 << std::endl;
	cout << "cross = " << (v1 &v3) << std::endl;
	
	v3 = 4.0;
        // v3.operator=(double) 
        // v3.operator=(Vector2(double)) 
        // v3.operator=(Vector2(double, double)) 
	v3.print();
	
	v3 = v1 - v2;			//(3.0, 3.0)
	v3.print();

	v3 = v3 + 5;			//(5.0, 3.0)
        // v3.operator=(v3.operator+(int)) 
        // v3.operator=(v3.operator+(Vector2(int))) 
        // v3.operator=(v3.operator+(Vector2(double(int)))) 
        // v3.operator=(v3.operator+(Vector2(double(int), double))) 
	v3.print();

	return 0;
}
