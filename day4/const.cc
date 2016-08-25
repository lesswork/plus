#include <iostream>

using namespace std;

class Base
{
	const int c;
	int b;
public:
	Base(int arguments) : c(arguments)
	{
		b = 10;
		cout << "cttor() called" << endl;
	}
	~Base()
	{
		cout << "dttor() called" << endl;
	}
	void display(void) const
	{
		//we can not modify in const function
		//b++;

		cout << "const Value : " << c << endl;
	}

	void display(void)
	{
		//we can not modify in const function
		//b++;

		cout << "Value : " << c << endl;
	}

	/* data */
};

int main(void)
{
	Base b1(5);
	const Base b2(12);
	b1.display();
	b2.display();
	return 0;
}
