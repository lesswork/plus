#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Phonebook
{
	map < string, vector <string> > person;
	std::vector<string> v;
public:
	add(string n, string number)
	{
		v.push_back(number);
		person.insert(n, v);
	}
	add(string n, string number1, sting number2)
	{
		v.push_back(number1);
		v.push_back(number2);
		person.insert(n, v);
	}
	remove()
	{
		person.erase();
	}
}

class Person
{
	string name;
	// we can use this (vector)
	// vector <string *> v1;

	// we can use this (set)
	set <string*> s;
public:
	 Person() {}
	 Person(string n, string number)
	 {
	 	name = n;
	 }
	 add_number()
	 {
	 	v1.push_back(number);
	 }
	~ Person(){}
	
};

int main()
{
	map m1.insert(pair<const "Ratnesh", <string> "9998889998"> );	
}
