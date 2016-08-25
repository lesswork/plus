#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Subscriber
{
protected:
	int price;
public:
	Subscriber() { }
	virtual void Update(int price) = 0;
};

class StockBroker
{
private:
	vector<Subscriber*> subscriber;
	int price;
public:
	void Register(Subscriber* p)
	{
		subscriber.push_back(p);
	}

	// Will call Notify when change done
	void Change(int p)
	{
		price = p;
		Notify();
	}

	// Called hen price changed
	// can check for some condition and then call Update funtions also.
	void Notify()
	{
		for(vector<Subscriber*>::iterator it = subscriber.begin() ; 
			it != subscriber.end() ; ++it )
			(*it)->Update(price);
	}
};

class Equity : public Subscriber
{
	virtual void Update(int i)
	{
		cout << "Equity() updated" << endl;
		price =i;
	}
};

class MutualFund : public Subscriber
{
	virtual void Update(int i)
	{
		cout << "MutualFund() updated" << endl;
		price =i;
	}
};

// create singletone method without pointer
int main()
{
	StockBroker bob;

	Equity ajay;
	MutualFund vijay;
	Equity satish;

	bob.Register(&ajay);
	bob.Register(&vijay);
	bob.Register(&satish);
	
	// Notify all subscribers, call Update()
	bob.Change(10);
	return 0;
}
