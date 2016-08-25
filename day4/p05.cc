#include <iostream>
#include <string>

using namespace std;

class MyException
{
protected:
	int i;
public:
	MyException()
	{
		cout << "MyException cttor" << endl;
	}

	MyException(int a) : i(a)
	{
		cout << "MyException cttor" << endl;
	}

	~MyException()
	{
		cout << "MyException dttor" << endl;
	}

};

class IOException : public MyException
{
	int i;
public:
	IOException()
	{
		cout << "IOException cttor" << endl;
	}
	
	IOException(int a) : i(a)
	{
		cout << "IOException(int i) cttor" << endl;
	}
	
	~IOException()
	{
		cout << "IOException dttor" << endl;
	}
};

class President
{
private:
	string name;
	President *p;
	President(string n) : name(n)
	{	}

public:
	static President* createIntance();

	void display()
	{
		cout << this << ": President : " << name << endl;
	}
};

President* President::createIntance()
{
	President* p = new President("Obama");
	return p;
}

int main()
{
	President *p1 = President::createIntance();
	p1->display();
	President *p2 = President::createIntance();
	p2->display();
	return 0;
}
