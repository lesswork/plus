#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

#define VEG 1
#define NONVEG 2

class Pizza
{
public:
	Pizza()
	{
		cout << "Pizza() cttor" << endl;
	}
	
	static Pizza* createPizza(int i);
	virtual void create() = 0;

	// it should be virtual
	virtual ~Pizza()
	{
		cout << "Pizza() dttor" << endl;
	}
};

class VegPizza : public Pizza
{
public:
	VegPizza()
	{
		cout << "VegPizza() cttor" << endl;
	}
	void create()
	{
		cout << this << " Veg Pizza created" << endl;
	}

	~VegPizza()
	{
		cout << "VegPizza() dttor" << endl;
	}
};

class NonvegPizza : public Pizza
{
public:
	NonvegPizza()
	{
		cout << "NonvegPizza() cttor" << endl;
	}
	void create()
	{
		cout << this << " Nonveg Pizza created" << endl;
	}
	~NonvegPizza()
	{
		cout << "NonvegPizza() dttor" << endl;
	}
};

Pizza* Pizza::createPizza(int i)
{
	if(i == VEG)
	{
		return new VegPizza();
	}
	else if(i == NONVEG)
	{
		return new NonvegPizza();
	}
	else
		return NULL;
}

int main()
{
	Pizza *p1 = Pizza::createPizza(VEG);
	p1->create();
	
	Pizza *p2 = Pizza::createPizza(NONVEG);
	p1->create();

// we may use template, but then any strange class start using
// base class
	delete p1;
	delete p2;
	return 0;
}
