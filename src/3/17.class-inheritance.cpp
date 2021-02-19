#include <iostream>
#include <string>

using namespace std;

class Appliance
{
private:
	int shelftime;

protected:
	string firm;
	
	Appliance(string firm_) : 
		firm(firm_) 
	{
			shelftime = 12;
			price = 0;
	}
	
	void print()
	{
		cout << firm << " WARANTY: " << shelftime << " year; " << " PRICE: $" << price << " ";
	}

public:

	int price;
	Appliance(string firm_, int shelftime_, int price_ = 0) : 
		firm(firm_), shelftime(shelftime_), price(price_)
	{
		
	}	
};


class Fridge : public Appliance
{
	int cool;
  string firm;
 public:
	Fridge(string firm, int cool) : Appliance(firm)
	{
		Fridge::firm = "test";
		Fridge::cool = cool;
    cout << Fridge::firm << ' ' << Appliance::firm << endl;
	}

	void print()
	{
		Appliance::print();
		cout << " COOL: " << cool << " ";
	}
};


class Microwave : private Appliance
{
	int time;

public:
	Microwave() : time(0), Appliance("SAMSUNG") {}
	void print()
	{
		Appliance::print();
		cout << " TIME: " << time << " ";
	}
};


int main()
{
	Appliance A("MW", 24, 40000);
//	A.print(); //‘void Appliance::print()’ is protected
//	cout << endl;
	A.price++;

	//	Fridge F; // no matching Fridge::Fridge()
	Fridge F("LG", -20);	
	F.print();
	cout << endl;
	F.price++;

	Microwave M;
	M.print();
	cout << endl;
//	M.price++;	//‘int Appliance::price’ is inaccessible
	
	return 0;
}
