#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Subscriber
{
public:
	Subscriber()
	{
		cout << "Subscriber() cttor" << endl;
	}

	// defining funtion as virtual make behviour preditable.
	virtual ~Subscriber()
	{
		cout << "Subscriber() dttor" << endl;
	}
};

class Equity : public Subscriber
{
public:
	Equity()
	{
		cout << "Equity() cttor" << endl;
	}
	~Equity()
	{
		cout << "Equity() dttor" << endl;
	}
};

int main()
{
	//calls constructor of base and derived
	Subscriber *ptr = new Equity;
	
	//calls destructor of derive and base
	// but not call derived destructor
	delete ptr;
	return 0;
}
