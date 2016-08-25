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
	static President *pInstance;
	President(string n) : name(n)
	{	}

public:
	static President* getIntance();

	void display()
	{
		cout << this << ": President : " << name << endl;
	}
};

President* President::getIntance()
{
	// lazy initialization
	// object created at runtime
	if(President::pInstance == NULL)
		President::pInstance = new President("Obama");

	return pInstance;
}

President* President::pInstance = NULL;

int main()
{
	President *p1 = President::getIntance();
	p1->display();
	President *p2 = President::getIntance();
	p2->display();
	return 0;
}
