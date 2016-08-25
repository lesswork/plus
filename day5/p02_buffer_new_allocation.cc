#include <iostream>
#include <string.h>

using namespace std;

char buffer[40];

class President
{
private:
	char name[12];
	char * city;

public:
	President()
	{
		city = new char[10];
	}

	~President()
	{
		cout << "~President()" << endl;
		delete[] city;
	}

	void doSomething();

	void display()
	{
		cout << this << ": President : " << name << endl;
	}
};

void President::doSomething()
{
	cout << "Hello" << endl;
}

int main()
{
	// allocate new from given buffer
	President* ptr = new (buffer) President;
	ptr->doSomething();
	cout << "ptr : " << ptr << " &buffer : " << &buffer << endl;
	ptr->~President();
	return 0;
}
