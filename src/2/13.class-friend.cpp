#include <iostream>
//using namespace std;
using std::endl;
using std::cout;
using std::ostream;

class Vector2
{
	double x, y;
	static int constructors;
public:
	
	Vector2(double x, double y);
	double operator*(const Vector2 &v);
	Vector2 operator+(const Vector2 &v);
	Vector2 operator-(const Vector2 &v);
	double operator&(const Vector2 &v);
	
	friend void print(const Vector2 &v);
// Если закомментировать строку выше то получим ошибку:
// 13.class-friend.cpp:40:19: error: ‘double Vector2::x’ is private within this context

	friend std::ostream& operator<<(std::ostream & out, const Vector2 &v);
};

int Vector2::constructors = 0;

Vector2::Vector2(double x = 1.0, double y = 1.0)	//значения по умолчанию
{
	Vector2::x = x;
	Vector2::y = y;
	constructors++;
}

void print(const Vector2 &v)
{
	cout << "(" << v.x << "; " << v.y << ")" << endl;
	cout << v.constructors << endl;
}

std::ostream& operator<<(std::ostream& out, const Vector2 &v)
{
	out << "(" << v.x << "; " << v.y << ")" << endl;
	out << v.constructors << endl;
	return out;
}

double Vector2::operator*(const Vector2 &v)			//перегрузка оператора умножения
{
	return x * v.x + y * v.y;
}

Vector2 Vector2::operator+(const Vector2 &v)
{
	return Vector2(x + v.x, y + v.y);
}

Vector2 Vector2::operator-(const Vector2 &v)
{
	return Vector2(x - v.x, y - v.y);
}

double Vector2::operator&(const Vector2 &v)
{
	return x * v.y - v.x * y;
}

class Matrix2x2
{
	double a[2][2];
	
};


int main()
{

	Vector2 v1; 		//(1.0, 1.0)
	Vector2 v2(2.0, 2.0);	//(2.0, 2.0)
	Vector2 v3(2.0);	//(2.0, 1.0)
	std::cout << v3;

	cout << "dot = " << v1 * v3 << std::endl;
	
	v3 = 4.0;		//(4.0, 1.0)
	std::cout << v3;
	
	v3 = v1 + v2;		//(3.0, 3.0)
	std::cout << v3;

	return 0;
} 
