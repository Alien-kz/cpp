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
	
public:
	void print()
	{
		cout << firm << " WARANTY: " << shelftime << " year; " << " PRICE: $" << price << " ";
	}
	int price;
	Appliance(string firm_, int shelftime_, int price_ = 0) : 
		firm(firm_), shelftime(shelftime_), price(price_)
	{
		
	}	
};

class Fridge : public Appliance
{
	int cool;
	
public:
	Fridge(string firm_, int shelftime_, int price_, int cool_) : 
		Appliance(firm_, shelftime_, price_) 
	{
		Fridge::cool = cool;
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
	
	Microwave(string firm_, int shelftime_, int price_, int time_) : 
		Appliance(firm_, shelftime_, price_) 
	{
		time = time_;
	}
	void print()
	{
		Appliance::print();
		cout << " TIME: " << time << " ";
	}
};


int main()
{
	char t;
	string firm;
	int price;
	int shelftime;
	cin >> firm >> shelftime >> price ;

	cin >> t;
	if (t == 'm')
	{
		int temp;
		cin >> temp;
		Microwave M(firm, shelftime, price, temp); //[12]
		Appliance A("LG", 12, 1); //[8]
//		M = A; //no match for ‘operator=’ 
//		A = M; //‘Appliance’ is an inaccessible base of ‘Microwave’ - public:price := private:price
	}
	else if (t == 'f')
	{
		int cool;
		cin >> cool;
		Fridge F(firm, shelftime, price, cool);
		Appliance A("LG", 12, 1);
//		F = A; //no match for ‘operator=’ 
		A = F; //public:price := publice:price
		A.print(); //‘void Appliance::print()’ is protected
	}

	return 0;
}
