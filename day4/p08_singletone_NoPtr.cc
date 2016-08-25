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
	President pInstance;
	President()
	{
		//new President();
	}
	President(string n) : name(n)
	{
		//new President("Obama");
	}

public:
	static President& getIntance();

	void display()
	{
		cout << this << ": President : " << name << endl;
	}
};

President& President::getIntance()
{
	return pInstance;
}

//President* President::pInstance = NULL;

// create singletone method without pointer
int main()
{
	President *p1 = President::getIntance();
	p1->display();
	President *p2 = President::getIntance();
	p2->display();
	return 0;
}
