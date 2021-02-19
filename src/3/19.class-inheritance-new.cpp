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
virtual void print()
	{
		cout << firm << " WARANTY: " << shelftime << " year; " << " PRICE: $" << price << " ";
	}
	void printFirm()
	{
		cout << firm << endl;
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

	void printFirm()
	{
		cout << "YES" << endl;
	}
};

class Microwave : public Appliance
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
	
	void printFirm()
	{
		cout << "NO" << endl;
	}
	
};


int main()
{
	Appliance * Ptr;
	Ptr = new Fridge("LG", 12, 12000, -20);
	Ptr->print(); //‘void Appliance::print()’ is protected
	cout << endl;
	Ptr->printFirm();
	cout << endl;
	delete Ptr;
	
	Ptr = new Microwave("LG", 12, 12000, 3000);
	Ptr->print(); //‘void Appliance::print()’ is protected
	cout << endl;
	Ptr->printFirm();
	cout << endl;
	delete Ptr;
	
	return 0;
}
